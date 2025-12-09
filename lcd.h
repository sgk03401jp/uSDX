/**
 * @file lcd.h
 * @brief uSDX+ HF Transceiver
 * @author JJ1VQD
 * @date 25-12-09
 * @detail inspired by: http://www.technoblogy.com/show?2BET
 */
class LCD : public Print { 
public: // LCD1602 display in 4-bit mode, RS is pull-up and kept low when idle
        // to prevent potential display RFI via RS line
#define _dn 0 // PD0 to PD3 connect to D4 to D7 on the display
#define _en 4 // PD4 - MUST have pull-up resistor
#define _rs 4 // PC4 - MUST have pull-up resistor

/** @def Use pullup on RS line, ensures compliancy to the absolute maximum ratings
 * for the si5351 sda input that is shared with rs pin of lcd
 */
#define RS_PULLUP   1 
#ifdef RS_PULLUP
#define LCD_RS_HI()                                                            \
  DDRC &= ~(1 << _rs);                                                         \
  asm("nop");                         // RS high (pull-up)
#define LCD_RS_LO() DDRC |= 1 << _rs; // RS low (pull-down)
#else
#define LCD_RS_LO() PORTC &= ~(1 << _rs); // RS low
#define LCD_RS_HI() PORTC |= (1 << _rs);  // RS high
#endif                                    // RS_PULLUP
#define LCD_EN_LO() PORTD &= ~(1 << _en); // EN low
#define LCD_EN_HI() PORTD |= (1 << _en);  // EN high
#define LCD_PREP_NIBBLE(b)                                                     \
  (PORTD & ~(0xf << _dn)) | (b) << _dn | 1 << _en // Send data and enable high
  uint8_t _cols;

/** Send command , make sure at least 40ms after
 * power-up before sending commands
 * bool reinit = (x == 0) && (y == 0);
 */
  void begin(uint8_t x = 0,
             uint8_t y = 0) { 
#ifdef LCD_I2C

/** @def LCD I2C address where PCF8574 addess selection A0, A1, A2 are all open */
#define PCF_ADDR  0x27 
#define PCF_RS    0x01
#define PCF_RW    0x02 /** @def the 0xF0 bits are used for 4-bit data to the display. */
#define PCF_EN    0x04
#define PCF_BACKLIGHT 0x08
    Wire.beginTransmission(PCF_ADDR);
    Wire.write(0);
    Wire.endTransmission();
    delayMicroseconds(50000);
#else          //! LCD_I2C
    DDRD |= 0xf << _dn | 1 << _en; // Make data, EN outputs
    DDRC |= 1 << _rs;
    // PORTC &= ~(1 << _rs);                          // Set RS low in case to
    // support pull-down when DDRC is output
    delayMicroseconds(50000); // *
    LCD_RS_LO();
    LCD_EN_LO();
#endif         //! LCD_I2C
    cmd(0x33); // Ensures display is in 8-bit mode
    delayMicroseconds(4500);
    cmd(0x33);
    delayMicroseconds(4500);
    cmd(0x33);
    delayMicroseconds(150); // * Ensures display is in 8-bit mode
    cmd(0x32);              // Puts display in 4-bit mode
    cmd(0x28);              // * Function set: 2-line, 5x8
    cmd(0x0c);              // Display on
    // if(reinit) return;
    cmd(0x01); // Clear display
    /** Allow to execute Clear on display
     * [https://www.sparkfun.com/datasheets/LCD/HD44780.pdf, p.49, p58]
     */
    delay(3); 
    cmd(0x06); // * Entrymode: left, shift-dec
  }
#ifdef LCD_I2C
  void nib(uint8_t b, bool isData) { // Send four bit nibble to display
    b = (b << 4) | ((backlight) ? PCF_BACKLIGHT : 0) | ((isData) ? PCF_RS : 0);
    Wire.write(b | PCF_EN); // write command EN HI
    delayMicroseconds(4);   // enable pulse must be >450ns
    Wire.write(b);          // write command EN LO
    delayMicroseconds(60);  // commands need > 37us to settle
    Wire.write(b);          // must write for some unknown reason
  }
  void cmd(uint8_t b) {
    Wire.beginTransmission(PCF_ADDR);
    nib(b >> 4, false);
    nib(b, false);
    Wire.endTransmission();
  }
  size_t write(uint8_t b) {
    Wire.beginTransmission(PCF_ADDR);
    nib((b >> 4), true);
    nib((b), true);
    Wire.endTransmission();
  }
#else //! LCD_I2C
  // Since LCD is using PD0(RXD), PD1(TXD) pins in the data-path, some
  // co-existence feature is required when using the serial port. The following
  // functions are temporarily dsiabling the serial port when LCD writes happen,
  // and make sure that serial transmission is ended. To prevent that LCD writes
  // are received by the serial receiver, PC2 is made HIGH during writes to
  // pull-up TXD via a diode. The RXD, TXD lines are connected to the host via
  // 1k resistors, a 1N4148 is placed between PC2 (anode) and the TXD resistor.
  // There are two drawbacks when continuous LCD writes happen: 1. noise is
  // leaking via the AREF pull-ups into the receiver 2. serial data cannot be
  // received.
  void pre() {
#ifdef _SERIAL
    if (!vox)
      if (cat_active) {
        Serial.flush();
        for (; millis() < rxend_event;)
          wdt_reset();
        PORTC |= 1 << 2;
        DDRC |= 1 << 2;
      }
    UCSR0B &= ~((1 << RXEN0) |
                (1 << TXEN0)); // Complete serial TX and RX; mask PD1 LCD
                               // data-exchange by pulling-up TXD via PC2 HIGH;
                               // enable PD0/PD1, disable serial port
#endif
    noInterrupts(); // do not allow LCD tranfer to be interrupted, to prevent
                    // backlight to lighten-up
  }
  void post() {
    if (backlight)
      PORTD |= 0x08;
    else
      PORTD &= ~0x08; // Backlight control
#ifdef _SERIAL
    // UCSR0B |= (1<<RXEN0)|(1<<TXEN0); if(!vox) if(cat_active){ DDRC &=
    // ~(1<<2); } // Enable serial port, disable PD0, PD1; disable PC2
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    if (!vox)
      if (cat_active) {
        PORTC &= ~(1 << 2);
      } // Enable serial port, disable PD0, PD1; PC2 LOW to prevent CAT TX
        // disruption via MIC input
#endif
    interrupts();
  }
#ifdef RS_HIGH_ON_IDLE
  void cmd(uint8_t b) {
    pre();
    uint8_t nibh =
        LCD_PREP_NIBBLE(b >> 4); // Prepare high nibble data and enable high
    PORTD = nibh;                // Send high nibble data and enable high
    uint8_t nibl =
        LCD_PREP_NIBBLE(b & 0xf); // Prepare low nibble data and enable high
    LCD_RS_LO();
    LCD_EN_LO();
    PORTD = nibl; // Send low nibble data and enable high
    asm("nop");
    asm("nop"); // Keep RS low, but complete enable cycle (should be 500ns)
    LCD_EN_LO();
    LCD_RS_HI();
    post();
    delayMicroseconds(60); // Execution time  (37+4)*1.25 us
  }
  size_t write(uint8_t b) { // Write data:    send nibbles while RS high
    pre();
    uint8_t nibh =
        LCD_PREP_NIBBLE(b >> 4); // Prepare high nibble data and enable high
    PORTD = nibh;                // Send high nibble data and enable high
    uint8_t nibl =
        LCD_PREP_NIBBLE(b & 0xf); // Prepare low nibble data and enable high
    LCD_RS_HI();
    LCD_EN_LO();
    PORTD = nibl; // Send low nibble data and enable high
    asm("nop");
    asm("nop"); // Keep RS high, but complete enable cycle (should be 500ns)
    LCD_EN_LO();
    post();
    delayMicroseconds(60); // Execution time  (37+4)*1.25 us
    return 1;
  }
#else  //! RS_HIGH_ON_IDLE
  void nib(uint8_t b) { // Send four bit nibble to display
    pre();
    PORTD = LCD_PREP_NIBBLE(b); // Send data and enable high
    // asm("nop");                                    // Enable high pulse width
    // must be at least 230ns high, data-setup time 80ns
    delayMicroseconds(4);
    LCD_EN_LO();
    post();
    // delayMicroseconds(52);                         // Execution time
    delayMicroseconds(60); // Execution time
  }
  void cmd(uint8_t b) {
    nib(b >> 4);
    nib(b & 0xf);
  }                         // Write command: send nibbles while RS low
  size_t write(uint8_t b) { // Write data:    send nibbles while RS high
    pre();
    // LCD_EN_HI();                                   // Complete Enable cycle
    // must be at least 500ns (so start early)
    uint8_t nibh =
        LCD_PREP_NIBBLE(b >> 4); // Prepare high nibble data and enable high
    PORTD = nibh;                // Send high nibble data and enable high
    uint8_t nibl =
        LCD_PREP_NIBBLE(b & 0xf); // Prepare low nibble data and enable high
    // asm("nop");                                    // Enable high pulse width
    // must be at least 230ns high, data-setup time 80ns; ATMEGA clock-cycle is
    // 50ns (so at least 5 cycles)
    LCD_RS_HI();
    LCD_EN_LO();
    PORTD = nibl; // Send low nibble data and enable high
    LCD_RS_LO();
    // asm("nop"); asm("nop");                        // Complete Enable cycle
    // must be at least 500ns PORTD = nibl;                                  //
    // Send low nibble data and enable high asm("nop"); // Enable high pulse
    // width must be at least 230ns high, data-setup time 80ns; ATMEGA
    // clock-cycle is 50ns (so at least 5 cycles)
    LCD_RS_HI();
    LCD_EN_LO();
    LCD_RS_LO();
    post();
    delayMicroseconds(60); // Execution time  (37+4)*1.25 us
    return 1;
  }
#endif // RS_HIGH_ON_IDLE
#endif //! LCD_I2C
#ifdef CONDENSED
  void setCursor(uint8_t x, uint8_t y) {
    cmd(0x80 | (x + (uint8_t[]){0x00, 0x40, 0x00 + 20, 0x40 + 20}[y]));
  } // ONLY for LCD2004 display
#else
  void setCursor(uint8_t x, uint8_t y) { cmd(0x80 | (x + y * 0x40)); }
#endif
  void cursor() { cmd(0x0e); }
  void noCursor() { cmd(0x0c); }
  void noDisplay() { cmd(0x08); }
  void createChar(uint8_t l, uint8_t glyph[]) {
    cmd(0x40 | ((l & 0x7) << 3));
    for (int i = 0; i != 8; i++)
      write(glyph[i]);
  }
};

/*
class LCD : public Print {  // inspired by: http://www.technoblogy.com/show?2BET
public:  // LCD1602 display in 4-bit mode, RS is pull-up and kept low when idle
to prevent potential display RFI via RS line #define _dn  0      // PD0 to PD3
connect to D4 to D7 on the display #define _en  4      // PC4 - MUST have
pull-up resistor #define _rs  4      // PC4 - MUST have pull-up resistor #define
LCD_RS_HI() DDRC &= ~(1 << _rs);         // RS high (pull-up) #define
LCD_RS_LO() DDRC |= 1 << _rs;            // RS low (pull-down) #define
LCD_EN_LO() PORTD &= ~(1 << _en);        // EN low #define LCD_PREP_NIBBLE(b)
(PORTD & ~(0xf << _dn)) | (b) << _dn | 1 << _en // Send data and enable high
  void begin(uint8_t x, uint8_t y){                // Send command
    DDRD |= 0xf << _dn | 1 << _en;                 // Make data, EN and RS pins
outputs PORTC &= ~(1 << _rs);                          // Set RS low in case to
support pull-down when DDRC is output delayMicroseconds(50000); // * At least
40ms after power rises above 2.7V before sending commands LCD_RS_LO();
    cmd(0x33);                                     // Ensures display is in
8-bit mode cmd(0x32);                                     // Puts display in
4-bit mode cmd(0x0e);                                     // Display and cursor
on cmd(0x01);                                     // Clear display delay(3); //
Allow to execute on display
[https://www.sparkfun.com/datasheets/LCD/HD44780.pdf, p.49, p58]
  }
  void nib(uint8_t b){                             // Send four bit nibble to
display PORTD = LCD_PREP_NIBBLE(b);                    // Send data and enable
high delayMicroseconds(4); LCD_EN_LO(); delayMicroseconds(60); // Execution time
(was: 37)
  }
  void cmd(uint8_t b){ nib(b >> 4); nib(b & 0xf); }// Write command: send
nibbles while RS low size_t write(uint8_t b){                         // Write
data:    send nibbles while RS high uint8_t nibh = LCD_PREP_NIBBLE(b >>  4); //
Prepare high nibble data and enable high uint8_t nibl = LCD_PREP_NIBBLE(b &
0xf);       // Prepare low nibble data and enable high PORTD = nibh; // Send
high nibble data and enable high LCD_RS_HI(); LCD_EN_LO(); PORTD = nibl; // Send
low nibble data and enable high LCD_RS_LO(); LCD_RS_HI(); LCD_EN_LO();
    LCD_RS_LO();
    delayMicroseconds(41);                         // Execution time
    PORTD |= 0x02;                                 // To support
serial-interface keep LCD_D5 high, so that DVM is not pulled-down via D return
1;
  }
  void setCursor(uint8_t x, uint8_t y){ cmd(0x80 | (x + y * 0x40)); }
  void cursor(){ cmd(0x0e); }
  void noCursor(){ cmd(0x0c); }
  void noDisplay(){ cmd(0x08); }
  void createChar(uint8_t l, uint8_t glyph[]){ cmd(0x40 | ((l & 0x7) << 3));
for(int i = 0; i != 8; i++) write(glyph[i]); }
};
*/
/*
#include <LiquidCrystal.h>
class LCD_ : public LiquidCrystal {
public: // QCXLiquidCrystal extends LiquidCrystal library for pull-up driven
LCD_RS, as done on QCX. LCD_RS needs to be set to LOW in advance of calling any
operation.
  //LCD_(uint8_t rs = LCD_RS, uint8_t en = LCD_EN, uint8_t d4 = LCD_D4, uint8_t
d5, = LCD_D5 uint8_t d6 = LCD_D6, uint8_t d7 = LCD_D7) : LiquidCrystal(rs, en,
d4, d5, d6, d7){ }; LCD_() : LiquidCrystal(LCD_RS, LCD_EN, LCD_D4, LCD_D5,
LCD_D6, LCD_D7){ }; virtual size_t write(uint8_t value){ // overwrites
LiquidCrystal::write() and re-implements LCD data writes pinMode(LCD_RS, INPUT);
// pull-up LCD_RS write4bits(value >> 4); write4bits(value); pinMode(LCD_RS,
OUTPUT); // pull-down LCD_RS return 1;
  };
  void write4bits(uint8_t value){
    digitalWrite(LCD_D4, (value >> 0) & 0x01);
    digitalWrite(LCD_D5, (value >> 1) & 0x01);
    digitalWrite(LCD_D6, (value >> 2) & 0x01);
    digitalWrite(LCD_D7, (value >> 3) & 0x01);
    digitalWrite(LCD_EN, LOW);  // pulseEnable
    delayMicroseconds(1);
    digitalWrite(LCD_EN, HIGH);
    delayMicroseconds(1);    // enable pulse must be >450ns
    digitalWrite(LCD_EN, LOW);
    delayMicroseconds(100);   // commands need > 37us to settle
  };
};
*/
