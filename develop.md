# memory 

## original 
```
#define VERSION   "1.02x"
#define DIAG             1
#define KEYER            1
#define CAT              1
#define F_XTAL    27005000
//#define F_XTAL  25004000
//#define F_XTAL  25000000
//#define SWAP_ROTARY    1
//#define QCX            1
//#define OLED_SSD1306   1
//#define OLED_SH1106    1
//#define LCD_I2C        1
#define LPF_SWITCHING_DL2MAN_USDX_REV3           1 
//#define LPF_SWITCHING_DL2MAN_USDX_REV3_NOLATCH 1 
//#define LPF_SWITCHING_DL2MAN_USDX_REV2         1 
//#define LPF_SWITCHING_DL2MAN_USDX_REV2_BETA    1 
//#define LPF_SWITCHING_DL2MAN_USDX_REV1         1 
//#define LPF_SWITCHING_WB2CBA_USDX_OCTOBAND     1 
//#define LPF_SWITCHING_PE1DDA_USDXDUO           14
#define SI5351_ADDR   0x60 
//#define F_MCU   16000000 

// Advanced configuration switches
//#define CONDENSED      1 
//#define CAT_EXT        1 
//#define CAT_STREAMING  1 
#define CW_DECODER       1 
#define TX_ENABLE        1 
#define KEY_CLICK        1 
#define SEMI_QSK         1 
#define RIT_ENABLE       1 
#define VOX_ENABLE       1 
//#define MOX_ENABLE     1 
//#define FAST_AGC       1 
//#define VSS_METER      1 
//#define SWR_METER      1 
//#define ONEBUTTON      1 
//#define DEBUG          1 
//#define TESTBENCH      1 
//#define CW_FREQS_QRP   1 
//#define CW_FREQS_FISTS 1 
#define CW_MESSAGE       1 
//#define CW_MESSAGE_EXT 1 
//#define TX_DELAY       1 
//#define NTX            11
//#define PTX            11
//#define CLOCK          1 
#define CW_INTERMEDIATE  1 
//#define F_XTAL  20000000 
//#define TX_CLK0_CLK1   1 
//#define F_CLK2  12000000 
```

| define            | use byte  | use % | Max   |Gobal bye|Global %|leave
|---|---|---|---|---|---|---|---
| default           | 31640     | (98%) | 32256 | 1477 | (72%) | 571|
| DIAG              | 30320     | (93%) | 32256 | 1477 | (72%) | 571|
| KEYER             | 30698     | (95%) | 32256 | 1434 | (70%) | 614|
| CAT               | 27526     | (85%) | 32256 | 1141 | (55%) | 907|
| CW_DECODER        | 26084     | (80%) | 32256 | 1077 | (52%) | 971|
| TX_ENABLE         | 24808     | (76%) | 32256 | 833  | (40%) | 1215|
| KEY_CLICK         | 27400     | (84%) | 32256 | 1141 | (55%) | 907|
| SEMI_QSK          | 27222     | (84%) | 32256 | 1136 | (55%) | 912|
| RIT_ENABLE        | 27154     | (84%) | 32256 | 1141 | (55%) | 907|
| VOX_ENABLE        | 27182     | (84%) | 32256 | 1137 | (55%) | 911|
| CW_MESSAGE        | 26458     | (82%) | 32256 | 1083 | (52%) | 965|
| CW_INTERMEDIATE   | 27506     | (85%) | 32256 | 1141 | (55%) | 907|
