/**
 * @file config.h
 * @brief uSDX+ HF Transceiver
 * @author JJ1VQD
 * @date 25-12-09
 * @attention
 */

#define VERSION "1.02x"

/*!
 * Configuration switches; remove/add a double-slash at line-start to
 * enable/disable a feature; to save space disable e.g. CAT, DIAG, KEYER
 * 設定スイッチ。行頭の二重スラッシュを削除/追加して機能を有効/無効にします。スペースを節約するには、例:
 * CAT、DIAG、KEYER を無効にします。
 */

 /** @def
 * Hardware diagnostics on startup (only disable when your rig is working)
 *  起動時のハードウェア診断（リグが動作しているときのみ無効にする）
 */
#define DIAG  1

#define KEYER 1         /*< CW keyer */
#define CAT 1           /*< CAT-interface */
#define F_XTAL 27005000 /*< 27MHz SI5351 crystal */
//#define F_XTAL  25004000   // 25MHz SI5351 crystal  (enable for WB2CBA-uSDX,
//SI5351 break-out board or uSDXDuO) #define F_XTAL  25000000   // 25MHz SI5351
//crystal  (enable for 25MHz TCXO) #define SWAP_ROTARY    1   // Swap rotary
//direction (enable for WB2CBA-uSDX) #define QCX            1   // Supports
//older (non-SDR) QCX HW modifications (QCX, QCX-SSB, QCX-DSP with I/Q
//alignment-feature)
//! 古い（非 SDR）QCX HW 変更（I/Q アライメント機能付き
//! QCX、QCX-SSB、QCX-DSP）をサポート

//#define OLED_SSD1306   1   // OLED display (SSD1306 128x32 or 128x64), connect
//SDA (PD2), SCL (PD3) #define OLED_SH1106    1   // OLED display (SH1106 1.3"
//inch display), connect SDA (PD2), SCL (PD3), NOTE that this display is pretty
//slow #define LCD_I2C        1   // LCD with I2C (PCF8574 module          ),
//connect SDA (PD2), SCL (PD3), NOTE that this display is pretty slow

/** @def 
 * Enable 8-band filter bank switching:     latching relays wired to a
 * TCA/PCA9555 GPIO extender on the PC4/PC5 I2C bus; relays are using IO0.0
 * as common (ground), IO1.0..7 used by the individual latches K0-7
 * switching respectively LPFs for 10m, 15m, 17m, 20m, 30m, 40m, 60m, 80m
 * 8 バンド フィルタ バンクの切り替えを有効にします。PC4/PC5 I2C バス上の
 * TCA/PCA9555 GPIO エクステンダーに接続されたラッチ リレー。リレーは IO0.0
 * を共通 (グランド) として使用し、IO1.0..7 は個別のラッチ K0-7
 * 切り替えによって使用され、それぞれ
 * 10m、15m、17m、20m、30m、40m、60m、80m の LPF が切り替えられます。
 */
#define LPF_SWITCHING_DL2MAN_USDX_REV3 1 

//#define LPF_SWITCHING_DL2MAN_USDX_REV3_NOLATCH 1   // Enable 8-band filter
//bank switching: non-latching relays wired to a TCA/PCA9555 GPIO extender on
//the PC4/PC5 I2C bus; relays are using IO0.0 as common (ground), IO1.0..7 used
//by the individual latches K0-7 switching respectively LPFs for 10m, 15m, 17m,
//20m, 30m, 40m, 60m, 80m. Enable this if you are using 8-band non-latching
//version for the relays, the radio will draw extra 15mA current but will work
//ity any relay (Tnx OH2UDS/TA7W Baris)
//! 8バンドフィルタバンクの切り替えを有効にします。PC4/PC5
//! I2Cバス上のTCA/PCA9555
//! GPIOエクステンダーに接続された非ラッチ型リレーです。リレーはIO0.0を共通（グランド）として使用し、IO1.0..7はK0～7のラッチ（それぞれ10m、15m、17m、20m、30m、40m、60m、80mのLPF）の切り替えに使用します。リレーに8バンド非ラッチ型バージョンを使用している場合は、これを有効にしてください。無線機は15mAの追加電流を消費しますが、どのリレーでも動作します（OH2UDS/TA7W
//! Barisより）。

//#define LPF_SWITCHING_DL2MAN_USDX_REV2         1   // Enable 5-band filter
//bank switching:     latching relays wired to a TCA/PCA9555 GPIO extender on
//the PC4/PC5 I2C bus; relays are using IO0.1 as common (ground), IO0.3, IO0.5,
//IO0.7, IO1.1, IO1.3 used by the individual latches K1-5 switching respectively
//LPFs for 20m, 30m, 40m, 60m, 80m
//! 5バンドフィルタバンクの切り替えを有効にする：PC4/PC5 I2Cバス上のTCA/PCA9555
//! GPIOエクステンダーに接続されたラッチリレー。リレーはIO0.1を共通（グランド）として使用し、IO0.3、IO0.5、IO0.7、IO1.1、IO1.3は、それぞれ20m、30m、40m、60m、80mのLPFの個別のラッチK1-5切り替えで使用されます。

//#define LPF_SWITCHING_DL2MAN_USDX_REV2_BETA    1   // Enable 5-band filter
//bank switching:     latching relays wired to a PCA9539PW   GPIO extender on
//the PC4/PC5 I2C bus; relays are using IO0.1 as common (ground), IO0.3, IO0.5,
//IO0.7, IO1.1, IO1.3 used by the individual latches K1-5 switching respectively
//LPFs for 20m, 30m, 40m, 60m, 80m
//! 5バンドフィルタバンクの切り替えを有効にする：PC4/PC5 I2Cバス上のPCA9539PW
//! GPIOエクステンダーに接続されたラッチリレー。リレーはIO0.1を共通（グランド）として使用し、IO0.3、IO0.5、IO0.7、IO1.1、IO1.3は、それぞれ20m、30m、40m、60m、80mのLPFの個別のラッチK1-5切り替えで使用されます。

//#define LPF_SWITCHING_DL2MAN_USDX_REV1         1   // Enable 3-band filter
//bank switching:     latching relays wired to a PCA9536D    GPIO extender on
//the PC4/PC5 I2C bus; relays are using IO0 as common (ground), IO1-IO3 used by
//the individual latches K1-3 switching respectively LPFs for 20m, 40m, 80m
//! 3バンドフィルタバンクの切り替えを有効にする：PC4/PC5 I2Cバス上のPCA9536D
//! GPIOエクステンダーに接続されたラッチリレー。リレーはIO0を共通（グランド）として使用し、IO1～IO3は個々のラッチK1～3によって使用され、それぞれ20m、40m、80mのLPFが切り替えられる。

//#define LPF_SWITCHING_WB2CBA_USDX_OCTOBAND     1   // Enable 8-band filter
//bank switching: non-latching relays wired to a MCP23008    GPIO extender on
//the PC4/PC5 I2C bus; relays are using GND as common (ground), GP0..7 used by
//the individual latches K1-8 switching respectively LPFs for 80m, 60m, 40m,
//30m, 20m, 17m, 15m, 10m
//! 8 バンド フィルタ バンクの切り替えを有効にします。PC4/PC5 I2C バス上の
//! MCP23008 GPIO エクステンダーに接続された非ラッチ リレー。リレーは GND を共通
//! (グランド) として使用し、GP0..7 は個別のラッチ K1-8
//! 切り替えによって使用され、それぞれ 80m、60m、40m、30m、20m、17m、15m、10m の
//! LPF が切り替えられます。

//#define LPF_SWITCHING_PE1DDA_USDXDUO           14  // Enable 2-band filter
//bank switching: non-latching relay  wired to pin PD5 (pin 11); specify as
//value the frequency in MHz for which (and above) the relay should be altered
//(e.g. put 14 to enable the relay at 14MHz and above to use the 20m LPF).
//! 2 バンド フィルタ
//! バンクの切り替えを有効にします。ラッチングのないリレーがピン PD5 (ピン 11)
//! に接続されます。リレーを変更する周波数 (MHz 以上) を値として指定します
//! (たとえば、14 を設定すると、14MHz 以上でリレーが有効になり、20m LPF
//! が使用されます)。

/** @def 
 * SI5351A I2C address: 0x60 for SI5351A-B-GT, Si5351A-B04771-GT,
 * MS5351M; 0x62 for SI5351A-B-04486-GT; 0x6F for SI5351A-B02075-GT; see
 * here for other variants:
 * https://www.silabs.com/TimingUtility/timing-download-document.aspx?OPN=Si5351A-B02075-GT&OPNRevision=0&FileType=PublicAddendum
 * SI5351A I2C アドレス: SI5351A-B-GT、Si5351A-B04771-GT、MS5351M
 * の場合は 0x60、SI5351A-B-04486-GT の場合は 0x62、SI5351A-B02075-GT
 * の場合は 0x6F。その他のバリアントについては、こちらをご覧ください:
 * https://www.silabs.com/TimingUtility/timing-download-document.aspx?OPN=Si5351A-B02075-GT&OPNRevision=0&FileType=PublicAddendum
 */
#define SI5351_ADDR  0x60 

//#define F_MCU   16000000   // 16MHz ATMEGA328P crystal (enable for unmodified
//Arduino Uno/Nano boards with 16MHz crystal). You may change this value to any
//other crystal frequency (up to 28MHz may work)
//! 16MHz ATMEGA328P 水晶振動子（16MHz 水晶振動子を搭載した未改造の Arduino
//! Uno/Nano ボードで有効）。この値は他の水晶振動子周波数に変更できます（最大
//! 28MHz まで動作する可能性があります）。
// Advanced configuration switches
//! 高度な設定スイッチ

//#define CONDENSED      1   // Display in 4 line mode (for OLED and LCD2004
//modules)
//! 4行モードでの表示（OLEDおよびLCD2004モジュール用）

//#define CAT_EXT        1   // Extended CAT support: remote button and screen
//control commands over CAT
//! 拡張CATサポート: CAT経由のリモートボタンおよび画面制御コマンド

//#define CAT_STREAMING  1   // Extended CAT support: audio streaming over CAT,
//once enabled and triggered with CAT cmd, samplerate 7812Hz, 8-bit unsigned
//audio is sent over UART. The ";" is omited in the data-stream, and only sent
//to indicate the beginning and end of a CAT cmd.
//! CATサポートの拡張：CAT経由のオーディオストリーミング。CATコマンドで有効化・トリガーされると、サンプルレート7812Hz、8ビット符号なしオーディオがUART経由で送信されます。データストリーム中の「;」は省略され、CATコマンドの開始と終了を示すためだけに送信されます。

/** @def
 * CW decoder
 */
#define CW_DECODER 1

/** @def
 * Disable this for RX only (no transmit), e.g. to support uSDX for kids
 * idea: https://groups.io/g/ucx/topic/81030243#6276
 * これを RX のみ（送信なし）で無効にします。たとえば、子供向けの uSDX
 * をサポートする場合などです: https://groups.io/g/ucx/topic/81030243#6276
 */
#define TX_ENABLE   1 

/** @def 
 * Reduce key clicks by envelope shaping
 * エンベロープシェーピングによるキークリックの低減
 */
#define KEY_CLICK   1

/** @def 
 * Just after keying the transmitter, keeps the RX muted for a short amount
 * of time in the anticipation for continued keying
 * 送信機のキー入力直後、キー入力の継続に備えて受信機を短時間ミュート状態にします。
 */
#define SEMI_QSK    1 

/** @def
 * Receive-In-Transit alternates the receiving frequency with an
 * user-defined offset to compensate for any necessary tuning needed on
 * receive
 * 受信イントランジットは、受信時に必要な調整を補正するために、受信周波数をユーザー定義のオフセットと交互に切り替えます。
 */
#define RIT_ENABLE  1 

/** @def
 * Voice-On-Xmit which is switching the transceiver into transmit as soon
 * audio is detected (above noise gate level)
 * Voice-On-Xmit は、音声が検出されるとすぐに（ノイズ ゲート
 * レベル以上で）トランシーバーを送信モードに切り替える機能です。
 */
#define VOX_ENABLE  1 

//#define MOX_ENABLE     1   // Monitor-On-Xmit which is audio monitoring on
//speaker during transmit
//! 送信中にスピーカーで音声をモニタリングするMonitor-On-Xmit

//#define FAST_AGC       1   // Adds fast AGC option (good for CW)
//! 高速 AGC オプションを追加 (CW に最適)

//#define VSS_METER      1   // Supports Vss measurement (as s-meter option),
//requires resistor of 1M between 12V and pin 26 (PC3)
//! Vss測定をサポート（Sメーターオプションとして）、12Vとピン26（PC3）の間に1Mの抵抗が必要

//#define SWR_METER      1   // Supports SWR meter with bridge on A6/A7 (LQPF
//ATMEGA328P) by Alain, K1FM, see: https://groups.io/g/ucx/message/6262 and
//https://groups.io/g/ucx/message/6361
//! Alain、K1FMによるA6/A7（LQPF
//! ATMEGA328P）のブリッジ付きSWRメーターのサポートについては、https://groups.io/g/ucx/message/6262およびhttps://groups.io/g/ucx/message/6361を参照してください。

//#define ONEBUTTON      1   // Use single (encoder) button to control full the
//rig; optionally use L/R buttons to completely replace rotory encoder function
//! 単一の（エンコーダ）ボタンを使用してリグ全体を制御します。オプションでL /
//! Rボタンを使用して、ロータリーエンコーダ機能を完全に置き換えます。

//#define DEBUG          1   // for development purposes only (adds debugging
//features such as CPU, sample-rate measurement, additional parameters)
//! 開発目的のみ（CPU、サンプルレート測定、追加パラメータなどのデバッグ機能を追加します）

//#define TESTBENCH      1   // Tests RX chain by injection of sine wave,
//measurements results are sent over serial
//! 正弦波を注入してRXチェーンをテストし、測定結果をシリアルで送信します。

//#define CW_FREQS_QRP   1   // Defaults to CW QRP   frequencies when changing
//bands
//! バンドを変更すると、デフォルトでCW QRP周波数になります。

//#define CW_FREQS_FISTS 1   // Defaults to CW FISTS frequencies when changing
//bands
//! バンドを変更すると、デフォルトでCW FISTS周波数になります。

/** @def
 * Transmits pre-defined CW messages on-demand (left-click menu item 4.2)
 * 事前定義されたCWメッセージをオンデマンドで送信します（左クリックメニュー項目4.2）
 */
#define CW_MESSAGE  1 

//#define CW_MESSAGE_EXT 1   // Additional CW messages
//! 追加のCWメッセージ

//#define TX_DELAY       1   // Enables a delay in the actual transmission to
//allow relay-switching to be completed before the power is applied (see also
//NTX, PTX definitions below for GPIO that can switch relay/PA)
//! 実際の送信に遅延を持たせることで、電源投入前にリレー切り替えが完了できるようにします（リレー/PAを切り替えることができるGPIOについては、以下のNTX、PTXの定義も参照してください）。

//#define NTX            11  // Enables LOW  on TX, used as PTT out to enable
//external PAs (a value of 11 means PB3 is used)
//! TX を LOW にし、外部 PA を有効にするために PTT 出力として使用します (値 11
//! は PB3 が使用されることを意味します)

//#define PTX            11  // Enables HIGH on TX, used as PTT out to enable
//external PAs (a value of 11 means PB3 is used)
//! TX で HIGH を有効にし、外部 PA を有効にするために PTT 出力として使用します
//! (値 11 は PB3 が使用されることを意味します)

//#define CLOCK          1   // Enables clock
//! クロックを有効にする

/** @def
 * CW decoder shows intermediate characters (only available for LCD and
 * F_MCU at 20M), sequences like:  EIS[HV] EIUF EAW[JP] EARL TMO TMG[ZQ]
 * TND[BX] TNK[YC], may be good to learn CW; a full list of possible
 * sequences:  EISH5 EISV3 EIUF EIUU2 EAWJ1 EAWP EARL TMOO0 TMOO9 TMOO8
 * TMGZ7 TMGQ TNDB6 TNDX TNKY TNKC
 * CWデコーダーは中間文字を表示します（20MのLCDとF_MCUでのみ利用可能）。シーケンスは次のようになります：EIS[HV]
 * EIUF EAW[JP] EARL TMO TMG[ZQ] TND[BX]
 * TNK[YC]。CWを学ぶのに良いかもしれません。可能なシーケンスの完全なリスト：EISH5
 * EISV3 EIUF EIUU2 EAWJ1 EAWP EARL TMOO0 TMOO9 TMOO8 TMGZ7 TMGQ TNDB6 TNDX
 * TNKY TNKC
 */
#define CW_INTERMEDIATE  1 

//#define F_XTAL  20000000   // Enable this for uSDXDuO, 20MHz SI5351 crystal
//! uSDXDuO、20MHz SI5351水晶でこれを有効にする

//#define TX_CLK0_CLK1   1   // Enable this for uSDXDuO, i.e. when PA is driven
//by CLK0, CLK1 (not CLK2); NTX pin may be used for enabling the TX path (this
//is like RX pin, except that RX may also be used as attenuator)
//! uSDXDuO の場合、つまり PA が CLK0、CLK1 (CLK2 ではない)
//! で駆動される場合にこれを有効にします。NTX ピンは TX
//! パスを有効にするために使用できます (これは RX ピンに似ていますが、RX
//! は減衰器としても使用できます)

//#define F_CLK2  12000000   // Enables a fixed CLK2 clock output of choice
//(only applicable when TX_CLK0_CLK1 is enabled), e.g. for up-converter or to
//clock UART USB device
//! 選択した固定CLK2クロック出力を有効にします（TX_CLK0_CLK1が有効な場合にのみ適用されます）。例：アップコンバータ用、またはUART
//! USBデバイスのクロック用


// QCX pin defintions
#define LCD_D4    0   // PD0    (pin 2)
#define LCD_D5    1   // PD1    (pin 3)
#define LCD_D6    2   // PD2    (pin 4)
#define LCD_D7    3   // PD3    (pin 5)
#define LCD_EN    4   // PD4    (pin 6)
#define FREQCNT   5   // PD5    (pin 11)
#define ROT_A     6   // PD6    (pin 12)
#define ROT_B     7   // PD7    (pin 13)
#define RX        8   // PB0    (pin 14)
#define SIDETONE  9   // PB1    (pin 15)
#define KEY_OUT   10  // PB2    (pin 16)
#define SIG_OUT   11  // PB3    (pin 17)
#define DAH       12  // PB4    (pin 18)
#define DIT       13  // PB5    (pin 19)
#define AUDIO1    14  // PC0/A0 (pin 23)
#define AUDIO2    15  // PC1/A1 (pin 24)
#define DVM       16  // PC2/A2 (pin 25)
#define BUTTONS   17  // PC3/A3 (pin 26)
#define LCD_RS    18  // PC4    (pin 27)
#define SDA       18  // PC4    (pin 27)
#define SCL       19  // PC5    (pin 28)
//#define NTX     11  // PB3    (pin 17)
//#define PTX     11  // PB3    (pin 17)

#ifdef SWAP_ROTARY
#undef ROT_A
#undef ROT_B
#define ROT_A     7   // PD7    (pin 13)
#define ROT_B     6   // PD6    (pin 12)
#endif

#if (defined(OLED_SSD1306) || defined(OLED_SH1106))
#define OLED 1
#endif

#if (defined(CAT) || defined(TESTBENCH)) && !(OLED)
/** @def 
 *Coexistence support for serial port and LCD on the same pins 
 */
#define _SERIAL  1
#endif

#ifdef LPF_SWITCHING_DL2MAN_USDX_REV3_NOLATCH
#define LPF_SWITCHING_DL2MAN_USDX_REV3 1
#endif

#ifdef TX_CLK0_CLK1
#ifdef F_CLK2
#define TX1RX0 0b11111000
#define TX1RX1 0b11111000
#define TX0RX1 0b11111000
#define TX0RX0 0b11111011
#else //! F_CLK2
#define TX1RX0 0b11111100
#define TX1RX1 0b11111100
#define TX0RX1 0b11111100
#define TX0RX0 0b11111111
#endif /* F_CLK2 */
#else  /* ! TX_CLK0_CLK1 */
#define TX1RX0 0b11111011
#define TX1RX1 0b11111000
#define TX0RX1 0b11111100
#define TX0RX0 0b11111111
#endif /* TX_CLK0_CLK1 */

#if defined(F_CLK2) && !defined(TX_CLK0_CLK1)
#error "TX_CLK0_CLK1 must be enabled in order to use F_CLK2."
#endif

#ifndef TX_ENABLE
#undef KEYER
#undef TX_DELAY
#undef SEMI_QSK
#undef RIT_ENABLE
#undef VOX_ENABLE
#undef MOX_ENABLE
#endif /* TX_ENABLE */

#ifdef SWR_METER
float FWD;
float SWR;
float ref_V = 5 * 1.15;
static uint32_t stimer;
#define PIN_FWD A6
#define PIN_REF A7
#endif

/*
// UCX installation: On blank chip, use (standard Arduino Uno) fuse settings
(E:FD, H:DE, L:FF), and use customized Optiboot bootloader for 20MHz clock, then
upload via serial interface (with RX, TX and DTR lines connected to pin 1, 2, 3
respectively)
// UCX pin defintions
+#define SDA     3         //PD3    (pin 5)
+#define SCL     4         //PD4    (pin 6)
+#define ROT_A   6         //PD6    (pin 12)
+#define ROT_B   7         //PD7    (pin 13)
+#define RX      8         //PB0    (pin 14)
+#define SIDETONE 9        //PB1    (pin 15)
+#define KEY_OUT 10        //PB2    (pin 16)
+#define NTX     11        //PB3    (pin 17)
+#define DAH     12        //PB4    (pin 18)
+#define DIT     13        //PB5    (pin 19)
+#define AUDIO1  14        //PC0/A0 (pin 23)
+#define AUDIO2  15        //PC1/A1 (pin 24)
+#define DVM     16        //PC2/A2 (pin 25)
+#define BUTTONS 17        //PC3/A3 (pin 26)
// In addition set:
#define OLED  1
#define ONEBUTTON  1
#define ONEBUTTON_INV 1
#undef DEBUG
adjust I2C and I2C_ ports,
ssb_cap=1; dsp_cap=2;
#define _DELAY() for(uint8_t i = 0; i != 5; i++) asm("nop");
#define F_XTAL 20004000
#define F_CPU F_XTAL
*/

// FUSES = { .low = 0xFF, .high = 0xD6, .extended = 0xFD };   // Fuse settings
// should be set at programming (Arduino IDE > Tools > Burn bootloader)

//#if(ARDUINO < 10810)
//   #error "Unsupported Arduino IDE version, use Arduino IDE 1.8.10 or later
//   from https://www.arduino.cc/en/software"
//#endif

#if !(defined(ARDUINO_ARCH_AVR))
#error                                                                         \
    "Unsupported architecture, select Arduino IDE > Tools > Board > Arduino AVR Boards > Arduino Uno."
#endif
#if (F_CPU != 16000000)
#error                                                                         \
    "Unsupported clock frequency, Arduino IDE must specify 16MHz clock; alternate crystal frequencies may be specified with F_MCU."
#endif
#undef F_CPU

/** @def 
 * Actual crystal frequency of 20MHz XTAL1, note that this
 * declaration is just informative and does not correct the timing in
 * Arduino functions like delay(); hence a 1.25 factor needs to be
 * added for correction.
 */
#define F_CPU 20007000 
#ifndef F_MCU
#define F_MCU 20000000 //< 20MHz ATMEGA328P crystal
#endif

extern char __bss_end;
static int freeMemory() {
  char *sp = reinterpret_cast<char *>(SP);
  return sp - &__bss_end;
} // see: http://www.nongnu.org/avr-libc/user-manual/malloc.html

#ifdef CAT_EXT
volatile uint8_t cat_key = 0;
uint8_t _digitalRead(
    uint8_t pin) { //< reads pin or (via CAT) artificially overriden pins
  serialEvent();   //< allows CAT update
  if (cat_key) {
    return (pin == BUTTONS) ? ((cat_key & 0x07) > 0)
           : (pin == DIT)   ? ~cat_key & 0x10
           : (pin == DAH)   ? ~cat_key & 0x20
                            : 0;
  } // overrides digitalRead(DIT, DAH, BUTTONS);
  return digitalRead(pin);
}
#else
#define _digitalRead(x) digitalRead(x)
#endif // CAT_EXT

//#define ONEBUTTON_INV 1 // Encoder button goes from PC3 to GND (instead PC3 to
//5V, with 10k pull down)
#ifdef ONEBUTTON_INV
uint8_t inv = 1;
#else
uint8_t inv = 0;
#endif

//#ifdef KEYER
// Iambic Morse Code Keyer Sketch, Contribution by Uli, DL2DBG. Copyright (c)
// 2009 Steven T. Elliott Source: http://openqrp.org/?p=343,  Trimmed by Bill
// Bishop - wrb[at]wrbishop.com.  This library is free software; you can
// redistribute it and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version. This
// library is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
// details: Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
// MA  02111-1307  USA.

// keyerControl bit definitions
/** @def Dit latch */
#define DIT_L     0x01
/** @def Dah latch */
#define DAH_L     0x02
/** @def Dit is being processed */
#define DIT_PROC  0x04
/** @def 0 for normal, 1 for swap */
#define PDLSWAP   0x08  
/** @def 0 for Iambic A, 1 for Iambic B */
#define IAMBICB   0x10  
/** @def 0 for Iambic A, 1 for Iambic B */
#define IAMBICA   0x00  
/** @def Keyer Mode 0 1 -> Iambic2  2 ->SINGLE */
#define SINGLE 2
