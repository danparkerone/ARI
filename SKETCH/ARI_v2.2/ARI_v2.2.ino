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
    /* BD -- PRIMARE ------------------------------------------------------------------------------------------- */
    case 1: Serial.println(F("BD_PRIMARE_ON_OFF"));
      for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow1 + i); txIr(1, 23); waitTx(); break;
    case 30: Serial.println(F("BD_PRIMARE_PLAY"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow30 + i); txIr(1, 21); waitTx(); break;  
    case 29: Serial.println(F("BD_PRIMARE_STOP"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow29 + i); txIr(1, 21); waitTx(); break; 
    case 24: Serial.println(F("BD_PRIMARE_UP"));
      for (int i = 0; i < 25; i++) data25[i] = pgm_read_word_near(dataRow24 + i); txIr(1, 25); waitTx(); break;       
    case 27: Serial.println(F("BD_PRIMARE_DOWN"));
      for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow27 + i); txIr(1, 23); waitTx(); break;  
    case 25: Serial.println(F("BD_PRIMARE_LEFT"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow25 + i); txIr(1, 21); waitTx(); break;  
    case 26: Serial.println(F("BD_PRIMARE_RIGHT"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow26 + i); txIr(1, 21); waitTx(); break;    
    case 28: Serial.println(F("BD_PRIMARE_SELECT"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow28 + i); txIr(1, 21); waitTx(); break;
    case 41: Serial.println(F("BD_PRIMARE_HOME"));
      for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow41 + i); txIr(1, 23); waitTx(); break; 
    case 31: Serial.println(F("BD_PRIMARE_PREV"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow31 + i); txIr(1, 21); waitTx(); break;   
    case 34: Serial.println(F("BD_PRIMARE_NEXT"));
      for (int i = 0; i < 23; i++) data23[i] = pgm_read_word_near(dataRow34 + i); txIr(1, 23); waitTx(); break;        
    case 33: Serial.println(F("BD_PRIMARE_FF"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow33 + i); txIr(1, 21); waitTx(); break;       
    case 32: Serial.println(F("BD_PRIMARE_FB"));
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow32 + i); txIr(1, 21); waitTx(); break;       
    case 49: Serial.println(F("BD_PRIMARE_TASTO_BLU"));
      for (int i = 0; i < 19; i++) data19[i] = pgm_read_word_near(dataRow49 + i); txIr(1, 19); waitTx(); break;  
    case 925: Serial.println(F("BD_PRIMARE_BACK")); // Tasto Left mantenuto per circa 2 sec
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow25 + i); txIr(10, 21); waitTx(); break;
    case 929: Serial.println(F("BD_PRIMARE_EJECT")); // Tasto STOP mantenuto per circa 2 sec
      for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow29 + i); txIr(10, 21); waitTx(); break;          
      
    /* TV -- PANASONIC ------------------------------------------------------------------------------------------ */  
    case 121: Serial.println(F("TV_PANASONIC_ON-OFF"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow121 + i); txIr(5, 99); break;  
    case 161: Serial.println(F("TV_PANASONIC_VOL+"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow161 + i); txIr(1, 99); break;
    case 162: Serial.println(F("TV_PANASONIC_VOL-"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow162 + i); txIr(1, 99); break;
    case 163: Serial.println(F("TV_PANASONIC_PROG+"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow163 + i); txIr(1, 99); break;  
    case 164: Serial.println(F("TV_PANASONIC_PROG-"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow164 + i); txIr(1, 99); break; 
    case 123: Serial.println(F("TV_PANASONIC_TV"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow123 + i); txIr(1, 99); break; 
    case 124: Serial.println(F("TV_PANASONIC_AV"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow124 + i); txIr(1, 99); break; 
    case 134: Serial.println(F("TV_PANASONIC_UP"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow134 + i); txIr(1, 99); break;  
    case 137: Serial.println(F("TV_PANASONIC_DOWN"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow137 + i); txIr(1, 99); break;                                                  
    case 135: Serial.println(F("TV_PANASONIC_LEFT"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow135 + i); txIr(1, 99); break; 
    case 136: Serial.println(F("TV_PANASONIC_RIGHT"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow136 + i); txIr(1, 99); break;   
    case 138: Serial.println(F("TV_PANASONIC_OK"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow138 + i); txIr(1, 99); break; 
    case 159: Serial.println(F("TV_PANASONIC_MUTE"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow159 + i); txIr(1, 99); break;   
    case 130: Serial.println(F("TV_PANASONIC_EXIT"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow130 + i); txIr(1, 99); break;                                   
    case 129: Serial.println(F("TV_PANASONIC_INFO"));
      for (int i = 0; i < 99; i++) data99[i] = pgm_read_word_near(dataRow129 + i); txIr(1, 99); break; 

    /* AV -- ROTEL ------------------------------------------------------------------------------------------ */  
    case 51: Serial.println(F("AV_ROTEL_ON-OFF"));
      for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow51 + i); txIr(1, 87); break;
    case 75: Serial.println(F("AV_ROTEL_VOL+"));
      for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow75 + i); txIr(1, 87); break;
    case 74: Serial.println(F("AV_ROTEL_VOL-"));
      for (int i = 0; i < 87; i++) data87[i] = pgm_read_word_near(dataRow74 + i); txIr(1, 87); break;
       
    /* DECODER TV XORO -------------------------------------------------------------------------------------- */
    case 76: Serial.println(F("DECODER_XORO_ON-OFF"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow76 + i); txIr(1, 67); waitTx(); break;
    case 95: Serial.println(F("DECODER_XORO_EXIT"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow95 + i); txIr(1, 67); waitTx(); break;
    case 96: Serial.println(F("DECODER_XORO_UP"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow96 + i); txIr(1, 67); waitTx(); break;
    case 97: Serial.println(F("DECODER_XORO_LEFT"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow97 + i); txIr(1, 67); waitTx(); break;
    case 98: Serial.println(F("DECODER_XORO_RIGTH"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow98 + i); txIr(1, 67); waitTx(); break;
    case 99: Serial.println(F("DECODER_XORO_DOWN"));  
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow99 + i); txIr(1, 67); waitTx(); break;
    case 100: Serial.println(F("DECODER_XORO_OK"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow100 + i); txIr(1, 67); waitTx(); break;
    case 101: Serial.println(F("DECODER_XORO_i"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow101 + i); txIr(1, 67); waitTx(); break;
    case 102: Serial.println(F("DECODER_XORO_INDIETRO"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow102 + i); txIr(1, 67); waitTx(); break;
    case 103: Serial.println(F("DECODER_XORO_EPG"));  
    for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow103 + i); txIr(1, 67); waitTx(); break;
    case 104: Serial.println(F("DECODER_XORO_TXT"));  
    for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow104 + i); txIr(1, 67); waitTx(); break;
    case 105: Serial.println(F("DECODER_XORO_VOL+")); 
    for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow105 + i); txIr(1, 67); waitTx(); break;
    case 106: Serial.println(F("DECODER_XORO_VOL-"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow106 + i); txIr(1, 67); waitTx(); break;
    case 107: Serial.println(F("DECODER_XORO_PAGE+"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow107 + i); txIr(1, 67); waitTx(); break;
    case 108: Serial.println(F("DECODER_XORO_PAGE-"));
      for (int i = 0; i < 67; i++) data67[i] = pgm_read_word_near(dataRow108 + i); txIr(1, 67); waitTx(); break;

    /* DEFAULT ---------------------------------------------------------------------------------------------- */
    default: 
      if (cmd != 0) {Serial.print("Comando: <");Serial.print(cmd);Serial.println("> non trovato!");} break;
  }
  delay(50);
}
