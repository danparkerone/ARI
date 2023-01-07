#include "config.h"
#include "readserial.h"
#include "tabellaCodiciRawIr.h"
#include "txIr.h"

void  setup () {
  pinMode(LEDOUT, OUTPUT); // LED di segnalazione
  Serial.begin(9600);
  delay(50);
  SSerial.begin(9600);
  delay(50);
  Serial.println("ARI v2.2 Pronta!!!");
  delay(1000);
}

void  loop () {
  cmd = 0;
  readConsole();
  readBT();
  //if (cmd != 0) Serial.println(cmd);
  
  switch(cmd) {
    case 1: Serial.println(F("BD_PRIMARE_ON-OFF")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow1 + i); txIr(1, 23); waitTx(); break;
    case 4: Serial.println(F("BD_PRIMARE_1")); for (int i = 0; i < 25; i++) data25[i] = pgm_read_word_near(dataRow4 + i); txIr(1, 25); waitTx(); break;
    case 5: Serial.println(F("BD_PRIMARE_2")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow5 + i); txIr(1, 23); waitTx(); break;
    case 6: Serial.println(F("BD_PRIMARE_3")); for (int i = 0; i < 25; i++) data25[i] = pgm_read_word_near(dataRow6 + i); txIr(1, 25); waitTx(); break;
    case 7: Serial.println(F("BD_PRIMARE_4")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow7 + i); txIr(1, 23); waitTx(); break;
    case 8: Serial.println(F("BD_PRIMARE_5")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow8 + i); txIr(1, 23); waitTx(); break;
    case 9: Serial.println(F("BD_PRIMARE_6")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow9 + i); txIr(1, 23); waitTx(); break;
    case 10: Serial.println(F("BD_PRIMARE_7")); for (int i = 0; i < 25; i++) data25[i] = pgm_read_word_near(dataRow10 + i); txIr(1, 25); waitTx(); break;
    case 11: Serial.println(F("BD_PRIMARE_8")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow11 + i); txIr(1, 23); waitTx(); break;
    case 12: Serial.println(F("BD_PRIMARE_9")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow12 + i); txIr(1, 23); waitTx(); break;
    case 13: Serial.println(F("BD_PRIMARE_0")); for (int i = 0; i < 25; i++) data25[i] = pgm_read_word_near(dataRow13 + i); txIr(1, 25); waitTx(); break;
    case 14: Serial.println(F("BD_PRIMARE_C")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow14 + i); txIr(1, 23); waitTx(); break;
    case 15: Serial.println(F("BD_PRIMARE_10P")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow15 + i); txIr(1, 21); waitTx(); break;
    case 24: Serial.println(F("BD_PRIMARE_UP")); for (int i = 0; i < 25; i++) data25[i] = pgm_read_word_near(dataRow24 + i); txIr(1, 25); waitTx(); break;
    case 25: Serial.println(F("BD_PRIMARE_LEFT")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow25 + i); txIr(1, 21); waitTx(); break;
    case 26: Serial.println(F("BD_PRIMARE_RIGTH")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow26 + i); txIr(1, 21); waitTx(); break;
    case 27: Serial.println(F("BD_PRIMARE_DOWN")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow27 + i); txIr(1, 23); waitTx(); break;
    case 28: Serial.println(F("BD_PRIMARE_SELECT")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow28 + i); txIr(1, 21); waitTx(); break;
    case 29: Serial.println(F("BD_PRIMARE_STOP/EJECT")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow29 + i); txIr(1, 21); waitTx(); break;
    case 30: Serial.println(F("BD_PRIMARE_PLAY/PAUSE")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow30 + i); txIr(1, 21); waitTx(); break;
    case 31: Serial.println(F("BD_PRIMARE_PREV")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow31 + i); txIr(1, 21); waitTx(); break;
    case 32: Serial.println(F("BD_PRIMARE_FB")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow32 + i); txIr(1, 21); waitTx(); break;
    case 33: Serial.println(F("BD_PRIMARE_FF")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow33 + i); txIr(1, 21); waitTx(); break;
    case 34: Serial.println(F("BD_PRIMARE_NEXT")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow34 + i); txIr(1, 23); waitTx(); break;
    case 35: Serial.println(F("BD_PRIMARE_SETUP")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow35 + i); txIr(1, 21); waitTx(); break;
    case 36: Serial.println(F("BD_PRIMARE_DISP")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow36 + i); txIr(1, 23); waitTx(); break;
    case 37: Serial.println(F("BD_PRIMARE_MENU")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow37 + i); txIr(1, 23); waitTx(); break;
    case 38: Serial.println(F("BD_PRIMARE_POP")); for (int i = 0; i < 25; i++) data25[i] = pgm_read_word_near(dataRow38 + i); txIr(1, 25); waitTx(); break;
    case 39: Serial.println(F("BD_PRIMARE_REPEAT")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow39 + i); txIr(1, 23); waitTx(); break;
    case 40: Serial.println(F("BD_PRIMARE_ANG")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow40 + i); txIr(1, 23); waitTx(); break;
    case 41: Serial.println(F("BD_PRIMARE_HOME")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow41 + i); txIr(1, 23); waitTx(); break;
    case 42: Serial.println(F("BD_PRIMARE_AUDIO")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow42 + i); txIr(1, 23); waitTx(); break;
    case 43: Serial.println(F("BD_PRIMARE_RES")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow43 + i); txIr(1, 21); waitTx(); break;
    case 44: Serial.println(F("BD_PRIMARE_ZOOM")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow44 + i); txIr(1, 23); waitTx(); break;
    case 45: Serial.println(F("BD_PRIMARE_GOTO")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow45 + i); txIr(1, 23); waitTx(); break;
    case 46: Serial.println(F("BD_PRIMARE_BAL/ST")); for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow46 + i); txIr(1, 23); waitTx(); break;
    case 47: Serial.println(F("BD_PRIMARE_ROSSO")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow47 + i); txIr(1, 21); waitTx(); break;
    case 48: Serial.println(F("BD_PRIMARE_VERDE")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow48 + i); txIr(1, 21); waitTx(); break;
    case 49: Serial.println(F("BD_PRIMARE_BLU")); for (int i = 0; i < 19; i++) data19[i] = pgm_read_word_near(dataRow49 + i); txIr(1, 19); waitTx(); break;
    case 50: Serial.println(F("BD_PRIMARE_GIALLO")); for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow50 + i); txIr(1, 21); waitTx(); break;
    case 51: Serial.println(F("AV_ROTEL_ON-OFF")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow51 + i); txIr(1, 87); waitTx(); break;
    case 52: Serial.println(F("AV_ROTEL_LINE")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow52 + i); txIr(1, 87); waitTx(); break;
    case 53: Serial.println(F("AV_ROTEL_LD")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow53 + i); txIr(1, 87); waitTx(); break;
    case 54: Serial.println(F("AV_ROTEL_VIDEO1")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow54 + i); txIr(1, 87); waitTx(); break;
    case 55: Serial.println(F("AV_ROTEL_VIDEO2")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow55 + i); txIr(1, 87); waitTx(); break;
    case 56: Serial.println(F("AV_ROTEL_TAPE")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow56 + i); txIr(1, 87); waitTx(); break;
    case 57: Serial.println(F("AV_ROTEL_BAS EQ")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow57 + i); txIr(1, 87); waitTx(); break;
    case 61: Serial.println(F("AV_ROTEL_DOLBY PRO LOGIC")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow61 + i); txIr(1, 87); waitTx(); break;
    case 62: Serial.println(F("AV_ROTEL_NORMAL")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow62 + i); txIr(1, 87); waitTx(); break;
    case 63: Serial.println(F("AV_ROTEL_PHANTOM")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow63 + i); txIr(1, 87); waitTx(); break;
    case 64: Serial.println(F("AV_ROTEL_WIDE")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow64 + i); txIr(1, 87); waitTx(); break;
    case 65: Serial.println(F("AV_ROTEL_JAZZ")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow65 + i); txIr(1, 87); waitTx(); break;
    case 66: Serial.println(F("AV_ROTEL_CONCERT")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow66 + i); txIr(1, 87); waitTx(); break;
    case 67: Serial.println(F("AV_ROTEL_STADIUM")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow67 + i); txIr(1, 87); waitTx(); break;
    case 68: Serial.println(F("AV_ROTEL_STEREO")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow68 + i); txIr(1, 87); waitTx(); break;
    case 71: Serial.println(F("AV_ROTEL_MUTE")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow71 + i); txIr(1, 87); waitTx(); break;
    case 74: Serial.println(F("AV_ROTEL_VOL -")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow74 + i); txIr(1, 87); waitTx(); break;
    case 75: Serial.println(F("AV_ROTEL_VOL +")); for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow75 + i); txIr(1, 87); waitTx(); break;
    case 76: Serial.println(F("DECODER_XORO_ON-OFF")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow76 + i); txIr(1, 67); waitTx(); break;
    case 77: Serial.println(F("DECODER_XORO_MUTE")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow77 + i); txIr(1, 67); waitTx(); break;
    case 78: Serial.println(F("DECODER_XORO_GOTO")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow78 + i); txIr(1, 67); waitTx(); break;
    case 79: Serial.println(F("DECODER_XORO_RPT")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow79 + i); txIr(1, 67); waitTx(); break;
    case 80: Serial.println(F("DECODER_XORO_SUB-T")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow80 + i); txIr(1, 67); waitTx(); break;
    case 81: Serial.println(F("DECODER_XORO_AUDIO")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow81 + i); txIr(1, 67); waitTx(); break;
    case 82: Serial.println(F("DECODER_XORO_FR")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow82 + i); txIr(1, 67); waitTx(); break;
    case 83: Serial.println(F("DECODER_XORO_FF")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow83 + i); txIr(1, 67); waitTx(); break;
    case 84: Serial.println(F("DECODER_XORO_PREV")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow84 + i); txIr(1, 67); waitTx(); break;
    case 85: Serial.println(F("DECODER_XORO_NEXT")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow85 + i); txIr(1, 67); waitTx(); break;
    case 86: Serial.println(F("DECODER_XORO_PLAY")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow86 + i); txIr(1, 67); waitTx(); break;
    case 87: Serial.println(F("DECODER_XORO_PAUSE")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow87 + i); txIr(1, 67); waitTx(); break;
    case 88: Serial.println(F("DECODER_XORO_STOP/EJECT")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow88 + i); txIr(1, 67); waitTx(); break;
    case 89: Serial.println(F("DECODER_XORO_REC")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow89 + i); txIr(1, 67); waitTx(); break;
    case 90: Serial.println(F("DECODER_XORO_ROSSO")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow90 + i); txIr(1, 67); waitTx(); break;
    case 91: Serial.println(F("DECODER_XORO_VERDE")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow91 + i); txIr(1, 67); waitTx(); break;
    case 92: Serial.println(F("DECODER_XORO_GIALLO")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow92 + i); txIr(1, 67); waitTx(); break;
    case 93: Serial.println(F("DECODER_XORO_BLU")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow93 + i); txIr(1, 67); waitTx(); break;
    case 94: Serial.println(F("DECODER_XORO_MENU")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow94 + i); txIr(1, 67); waitTx(); break;
    case 95: Serial.println(F("DECODER_XORO_EXIT")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow95 + i); txIr(1, 67); waitTx(); break;
    case 96: Serial.println(F("DECODER_XORO_UP")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow96 + i); txIr(1, 67); waitTx(); break;
    case 97: Serial.println(F("DECODER_XORO_LEFT")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow97 + i); txIr(1, 67); waitTx(); break;
    case 98: Serial.println(F("DECODER_XORO_RIGTH")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow98 + i); txIr(1, 67); waitTx(); break;
    case 99: Serial.println(F("DECODER_XORO_DOWN")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow99 + i); txIr(1, 67); waitTx(); break;
    case 100: Serial.println(F("DECODER_XORO_OK")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow100 + i); txIr(1, 67); waitTx(); break;
    case 101: Serial.println(F("DECODER_XORO_i")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow101 + i); txIr(1, 67); waitTx(); break;
    case 102: Serial.println(F("DECODER_XORO_INDIETRO")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow102 + i); txIr(1, 67); waitTx(); break;
    case 103: Serial.println(F("DECODER_XORO_EPG")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow103 + i); txIr(1, 67); waitTx(); break;
    case 104: Serial.println(F("DECODER_XORO_TXT")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow104 + i); txIr(1, 67); waitTx(); break;
    case 105: Serial.println(F("DECODER_XORO_VOL+")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow105 + i); txIr(1, 67); waitTx(); break;
    case 106: Serial.println(F("DECODER_XORO_VOL-")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow106 + i); txIr(1, 67); waitTx(); break;
    case 107: Serial.println(F("DECODER_XORO_PAGE+")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow107 + i); txIr(1, 67); waitTx(); break;
    case 108: Serial.println(F("DECODER_XORO_PAGE-")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow108 + i); txIr(1, 67); waitTx(); break;
    case 109: Serial.println(F("DECODER_XORO_1")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow109 + i); txIr(1, 67); waitTx(); break;
    case 110: Serial.println(F("DECODER_XORO_2")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow110 + i); txIr(1, 67); waitTx(); break;
    case 111: Serial.println(F("DECODER_XORO_3")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow111 + i); txIr(1, 67); waitTx(); break;
    case 112: Serial.println(F("DECODER_XORO_4")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow112 + i); txIr(1, 67); waitTx(); break;
    case 113: Serial.println(F("DECODER_XORO_5")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow113 + i); txIr(1, 67); waitTx(); break;
    case 114: Serial.println(F("DECODER_XORO_6")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow114 + i); txIr(1, 67); waitTx(); break;
    case 115: Serial.println(F("DECODER_XORO_7")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow115 + i); txIr(1, 67); waitTx(); break;
    case 116: Serial.println(F("DECODER_XORO_8")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow116 + i); txIr(1, 67); waitTx(); break;
    case 117: Serial.println(F("DECODER_XORO_9")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow117 + i); txIr(1, 67); waitTx(); break;
    case 118: Serial.println(F("DECODER_XORO_0")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow118 + i); txIr(1, 67); waitTx(); break;
    case 119: Serial.println(F("DECODER_XORO_TV/RADIO")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow119 + i); txIr(1, 67); waitTx(); break;
    case 120: Serial.println(F("DECODER_XORO_FAV")); for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow120 + i); txIr(1, 67); waitTx(); break;
    case 121: Serial.println(F("TV_PANASONIC_ON-OFF")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow121 + i); txIr(1, 99); waitTx(); break;
    case 122: Serial.println(F("TV_PANASONIC_3D")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow122 + i); txIr(1, 99); waitTx(); break;
    case 123: Serial.println(F("TV_PANASONIC_TV")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow123 + i); txIr(1, 99); waitTx(); break;
    case 124: Serial.println(F("TV_PANASONIC_AV")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow124 + i); txIr(1, 99); waitTx(); break;
    case 125: Serial.println(F("TV_PANASONIC_MENU")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow125 + i); txIr(1, 99); waitTx(); break;
    case 126: Serial.println(F("TV_PANASONIC_ASPECT")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow126 + i); txIr(1, 99); waitTx(); break;
    case 127: Serial.println(F("TV_PANASONIC_INTERNET")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow127 + i); txIr(1, 99); waitTx(); break;
    case 128: Serial.println(F("TV_PANASONIC_DIRECT TV REC")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow128 + i); txIr(1, 99); waitTx(); break;
    case 129: Serial.println(F("TV_PANASONIC_i")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow129 + i); txIr(1, 99); waitTx(); break;
    case 130: Serial.println(F("TV_PANASONIC_EXIT")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow130 + i); txIr(1, 99); waitTx(); break;
    case 131: Serial.println(F("TV_PANASONIC_VIERA LINK")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow131 + i); txIr(1, 99); waitTx(); break;
    case 132: Serial.println(F("TV_PANASONIC_VIERA TOOLS")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow132 + i); txIr(1, 99); waitTx(); break;
    case 133: Serial.println(F("TV_PANASONIC_GUIDE")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow133 + i); txIr(1, 99); waitTx(); break;
    case 134: Serial.println(F("TV_PANASONIC_UP")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow134 + i); txIr(1, 99); waitTx(); break;
    case 135: Serial.println(F("TV_PANASONIC_LEFT")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow135 + i); txIr(1, 99); waitTx(); break;
    case 136: Serial.println(F("TV_PANASONIC_RIGHT")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow136 + i); txIr(1, 99); waitTx(); break;
    case 137: Serial.println(F("TV_PANASONIC_DOWN")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow137 + i); txIr(1, 99); waitTx(); break;
    case 138: Serial.println(F("TV_PANASONIC_OK")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow138 + i); txIr(1, 99); waitTx(); break;
    case 139: Serial.println(F("TV_PANASONIC_OPTION")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow139 + i); txIr(1, 99); waitTx(); break;
    case 140: Serial.println(F("TV_PANASONIC_BACK/RETURN")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow140 + i); txIr(1, 99); waitTx(); break;
    case 141: Serial.println(F("TV_PANASONIC_ROSSO")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow141 + i); txIr(1, 99); waitTx(); break;
    case 142: Serial.println(F("TV_PANASONIC_VERDE")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow142 + i); txIr(1, 99); waitTx(); break;
    case 143: Serial.println(F("TV_PANASONIC_GIALLO")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow143 + i); txIr(1, 99); waitTx(); break;
    case 144: Serial.println(F("TV_PANASONIC_BLU")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow144 + i); txIr(1, 99); waitTx(); break;
    case 145: Serial.println(F("TV_PANASONIC_TEXT")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow145 + i); txIr(1, 99); waitTx(); break;
    case 146: Serial.println(F("TV_PANASONIC_STTL")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow146 + i); txIr(1, 99); waitTx(); break;
    case 147: Serial.println(F("TV_PANASONIC_INDEX")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow147 + i); txIr(1, 99); waitTx(); break;
    case 148: Serial.println(F("TV_PANASONIC_HOLD")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow148 + i); txIr(1, 99); waitTx(); break;
    case 149: Serial.println(F("TV_PANASONIC_1")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow149 + i); txIr(1, 99); waitTx(); break;
    case 150: Serial.println(F("TV_PANASONIC_2")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow150 + i); txIr(1, 99); waitTx(); break;
    case 151: Serial.println(F("TV_PANASONIC_3")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow151 + i); txIr(1, 99); waitTx(); break;
    case 152: Serial.println(F("TV_PANASONIC_4")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow152 + i); txIr(1, 99); waitTx(); break;
    case 153: Serial.println(F("TV_PANASONIC_5")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow153 + i); txIr(1, 99); waitTx(); break;
    case 154: Serial.println(F("TV_PANASONIC_6")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow154 + i); txIr(1, 99); waitTx(); break;
    case 155: Serial.println(F("TV_PANASONIC_7")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow155 + i); txIr(1, 99); waitTx(); break;
    case 156: Serial.println(F("TV_PANASONIC_8")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow156 + i); txIr(1, 99); waitTx(); break;
    case 157: Serial.println(F("TV_PANASONIC_9")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow157 + i); txIr(1, 99); waitTx(); break;
    case 158: Serial.println(F("TV_PANASONIC_0")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow158 + i); txIr(1, 99); waitTx(); break;
    case 159: Serial.println(F("TV_PANASONIC_MUTE")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow159 + i); txIr(1, 99); waitTx(); break;
    case 160: Serial.println(F("TV_PANASONIC_LAST VIEW")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow160 + i); txIr(1, 99); waitTx(); break;
    case 161: Serial.println(F("TV_PANASONIC_VOL+")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow161 + i); txIr(1, 99); waitTx(); break;
    case 162: Serial.println(F("TV_PANASONIC_VOL-")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow162 + i); txIr(1, 99); waitTx(); break;
    case 163: Serial.println(F("TV_PANASONIC_PROG+")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow163 + i); txIr(1, 99); waitTx(); break;
    case 164: Serial.println(F("TV_PANASONIC_PROG-")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow164 + i); txIr(1, 99); waitTx(); break;
    case 165: Serial.println(F("TV_PANASONIC_VCR ON-OFF")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow165 + i); txIr(1, 99); waitTx(); break;
    case 166: Serial.println(F("TV_PANASONIC_VCR REC")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow166 + i); txIr(1, 99); waitTx(); break;
    case 167: Serial.println(F("TV_PANASONIC_VCR DOWN")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow167 + i); txIr(1, 99); waitTx(); break;
    case 168: Serial.println(F("TV_PANASONIC_VCR UP")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow168 + i); txIr(1, 99); waitTx(); break;
    case 169: Serial.println(F("TV_PANASONIC_VCR PREV")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow169 + i); txIr(1, 99); waitTx(); break;
    case 170: Serial.println(F("TV_PANASONIC_VCR PLAY")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow170 + i); txIr(1, 99); waitTx(); break;
    case 171: Serial.println(F("TV_PANASONIC_VCR NEXT")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow171 + i); txIr(1, 99); waitTx(); break;
    case 172: Serial.println(F("TV_PANASONIC_VCR STOP")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow172 + i); txIr(1, 99); waitTx(); break;
    case 173: Serial.println(F("TV_PANASONIC_VCR PAUSE")); for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow173 + i); txIr(1, 99); waitTx(); break;


    /* DEFAULT ---------------------------------------------------------------------------------------------- */ 
    default: 
      if (cmd != 0) {Serial.print("Comando: <");Serial.print(cmd);Serial.println("> non trovato!");} break;                          
  }
  delay(50);
}
