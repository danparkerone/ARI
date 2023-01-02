#include <IRremote.h> // Utilizzare ver.2.0.1

//Il LED IR va sul pin 3
#define LEDOUT 2

IRsend irsend;    // Oggetto IRSend
int freq_ir = 38; // Khz. Frequenza TX IR
int ripet;        // x ciclo ripetizione TX IR
int maxrep;     // max ripetizioni TX IR
char comando;     // comando da console


// SETUP -------------------------------------------------------
void  setup ( ) {
  pinMode(LEDOUT, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
  Serial.println("IR_Send_Prova1. Pronto per Trasmissione ...");
}
//---------------------------------------------------------------


// LOOP ---------------------------------------------------------
void  loop ( ) {

  if (digitalRead(12)) {
    //Serial.println("PULSANTE 12");
    comando = 'a';
    delay(100);
  }

  if (digitalRead(13)) {
    //Serial.println("PULSANTE 13");
    comando = 'h';
    delay(100);
  }

  //comando = Serial.read(); // Leggi carattere da seriale
  if(comando == 'a'){
    Serial.println("PRIMARE ON/OFF");
    int lenData = 23;
    maxrep = 1;
    unsigned int rawData[lenData] = {900,800, 900,800, 850,800, 900,800, 900,800, 850,800, 1750,750, 950,750, 900,1650, 850,800, 1700,800, 900};
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(100);
    }
    comando = '0';     
  }
  


// TV PANASONIC -------------------------------------------
  if(comando == 'h'){
    Serial.println("TV ON/OFF");
    int lenData = 99;
    maxrep = 10;
    unsigned int rawData[lenData] = {3450,1650, 500,350, 500,1200, 500,350, 500,400, 450,400, 450,400, 450,400, 450,400, 500,350, 500,350, 500,350, 500,350, 500,400, 450,1250, 450,400, 450,400, 450,400, 450,400, 500,350, 500,350, 500,350, 500,400, 450,400, 450,1250, 450,400, 400,450, 450,400, 450,400, 500,350, 500,350, 500,350, 400,500, 450,1250, 450,400, 450,1200, 400,1350, 350,1300, 500,1200, 400,500, 350,500, 400,1300, 400,450, 400,1250, 450,1300, 400,1300, 400,1300, 350,500, 400,1300, 400};
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(50);
    }
    comando = '0';      
  } 
}
  
