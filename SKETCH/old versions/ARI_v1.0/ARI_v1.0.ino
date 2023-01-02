#include <IRremote.h> // Utilizzare ver.2.0.1
#include <SoftwareSerial.h>

//Il LED IR va sul pin 3
// definisco i pin TX e RX per la seriale Bluetooth
#define RX_BT 7
#define TX_BT 8
// definisco pin per pulsante (eventuale)
#define PIN_PULSANTE 12

#define LEDOUT 2 // definisce pin x LED

IRsend irsend;    // Oggetto IRSend
int freq_ir = 38; // Khz. Frequenza TX IR
int maxrep;       // max ripetizioni TX IR
char comcons;     // comando da console

// Inizializza seriale software
SoftwareSerial SSerial(RX_BT, TX_BT);

// SETUP -------------------------------------------------------
void  setup ( ) {
  pinMode(PIN_PULSANTE, INPUT); // pen eventuale pulsante
  pinMode(LEDOUT, OUTPUT); // LED di segnalazione
  Serial.begin(9600);
  Serial.println("ARIv1.0 Pronta!!!");
  SSerial.begin(9600);
}
//---------------------------------------------------------------

String str = "";

// LOOP ---------------------------------------------------------
void  loop ( ) {
  comcons = Serial.read(); // Leggi carattere da seriale
  String comando = "0";

  if (digitalRead(12)) { // leggi pulsante
    comando = "h";      // se premuto imposta ad "h" per comando TV ON-OFF
    delay(300);
  }
  
  if (SSerial.available()) {  // in ascolto di dati provenienti da SS (BT).
    char ch = SSerial.read(); // se presenti carico in ch
    //Serial.println(ch); // visualizzo i caratteri ricevuti
    // ignoro i caratteri \n e \r
    if ( (ch == '\n') || (ch == '\r')) { // se ricevo i caratteri \n o \r allora elaboro stringa con cmd() e azzero str
      comando = str.charAt(0);
      str = "";
    } else {
      str += ch; // altrimenti aggiungo a str il carattere ricevuto
    }
  }  
  
  //if (comando != "0") Serial.println(comando);

  // PRIMARE --------------------------------------------------------
  if(comando == "a"){
    Serial.println("PRIMARE ON/OFF");
    int lenData = 23;
    maxrep = 1;
    unsigned int rawData[lenData] = {900,800, 900,800, 850,800, 900,800, 900,800, 850,800, 1750,750, 950,750, 900,1650, 850,800, 1700,800, 900};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(100);
    }
    digitalWrite(LEDOUT, LOW);  
  }
  if(comando == "b"){
    Serial.println("PRIMARE PLAY");
    int lenData = 21;
    maxrep = 1;
    unsigned int rawData[lenData] = {900,800, 850,800, 900,800, 900,800, 850,800, 900,800, 1650,1650, 950,750, 1700,1700, 1700,1650, 850};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(100);
    }
    digitalWrite(LEDOUT, LOW);     
  }
  
  if(comando == "c"){
    Serial.println("PRIMARE STOP");
    int lenData = 21;
    maxrep = 1;
    unsigned int rawData[lenData] = {850,800, 850,850, 850,850, 800,850, 850,800, 900,850, 1650,1650, 850,850, 1650,1700, 850,850, 1650};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(100);
    }
    digitalWrite(LEDOUT, LOW);      
  }   
  
  if(comando == "d"){
    Serial.println("PRIMARE PREV");
    int lenData = 21;
    maxrep = 1;
    unsigned int rawData[lenData] = {950,750, 1750,1600, 900,800, 900,750, 950,750, 1700,1650, 1750,750, 950,750, 900,750, 950,1600, 900};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(100);
    }
    digitalWrite(LEDOUT, LOW);      
  }   

  if(comando == "e"){
    Serial.println("PRIMARE NEXT");
    int lenData = 23;
    maxrep = 1;
    unsigned int rawData[lenData] = {950,750, 900,800, 850,800, 900,800, 850,800, 850,850, 1700,1650, 1700,800, 900,800, 850,850, 850,850, 800};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(100);
    }
    digitalWrite(LEDOUT, LOW);      
  }     





// TV PANASONIC -------------------------------------------
  if(comando == "h"){
    Serial.println("TV PANASONIC ON/OFF");
    int lenData = 99;
    maxrep = 10;
    unsigned int rawData[lenData] = {3450,1650, 500,350, 500,1200, 500,350, 500,400, 450,400, 450,400, 450,400, 450,400, 500,350, 500,350, 500,350, 500,350, 500,400, 450,1250, 450,400, 450,400, 450,400, 450,400, 500,350, 500,350, 500,350, 500,400, 450,400, 450,1250, 450,400, 400,450, 450,400, 450,400, 500,350, 500,350, 500,350, 400,500, 450,1250, 450,400, 450,1200, 400,1350, 350,1300, 500,1200, 400,500, 350,500, 400,1300, 400,450, 400,1250, 450,1300, 400,1300, 400,1300, 350,500, 400,1300, 400};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(50);
    }
    digitalWrite(LEDOUT, LOW);     
  }   
  if(comando == "i"){
    Serial.println("TV PANASONIC VOL+");
    int lenData = 99;
    maxrep = 1;
    unsigned int  rawData[99] = {3450,1650, 500,350, 550,1150, 550,300, 500,350, 550,300, 550,350, 500,350, 500,350, 500,350, 550,300, 550,350, 500,300, 550,350, 500,1200, 500,300, 550,350, 500,350, 500,350, 550,300, 550,350, 500,300, 550,350, 500,300, 550,1200, 500,350, 500,350, 500,350, 500,350, 550,350, 500,300, 550,350, 500,350, 500,350, 500,350, 500,350, 500,350, 550,350, 500,1200, 450,400, 450,350, 550,300, 550,350, 500,350, 500,350, 500,350, 550,1150, 500,350, 550,1150, 550};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(50);
    }
    digitalWrite(LEDOUT, LOW);   
  } 

  if(comando == "l"){
    Serial.println("TV PANASONIC VOL-");
    int lenData = 99;
    maxrep = 1;    
    unsigned int  rawData[99] = {3500,1600, 500,350, 550,1150, 550,350, 500,350, 500,350, 450,400, 500,350, 500,350, 500,350, 500,350, 550,350, 500,350, 500,350, 500,1200, 500,350, 500,350, 500,350, 500,350, 500,350, 550,350, 500,300, 550,300, 550,350, 500,1200, 500,350, 500,350, 500,350, 500,350, 550,350, 500,350, 500,350, 450,400, 500,1200, 500,350, 500,350, 500,350, 500,350, 500,1200, 500,350, 500,400, 450,1250, 500,350, 450,350, 550,350, 500,350, 500,1200, 500,350, 500,1200, 500};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(50);
    }
    digitalWrite(LEDOUT, LOW);  
  }      

  if(comando == "m"){
    Serial.println("TV PANASONIC PROG+");
    int lenData = 99;
    maxrep = 1;    
    unsigned int  rawData[99] = {3450,1650, 500,350, 500,1200, 500,350, 500,350, 500,350, 550,350, 450,400, 450,400, 500,350, 500,350, 500,350, 500,350, 550,350, 500,1150, 500,400, 500,350, 450,350, 550,350, 500,350, 500,350, 500,350, 550,350, 500,300, 550,1150, 500,350, 500,400, 500,350, 500,350, 500,350, 500,350, 550,300, 550,350, 500,300, 550,350, 500,1150, 550,350, 500,1200, 500,1150, 550,350, 500,350, 500,350, 500,350, 500,1200, 550,350, 500,1150, 550,1150, 550,350, 500,1200, 500};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(50);
    }
    digitalWrite(LEDOUT, LOW);  
  }  

  if(comando == "n"){
    Serial.println("TV PANASONIC PROG-");
    int lenData = 99;
    maxrep = 1;    
    unsigned int  rawData[99] = {3450,1650, 450,350, 550,1200, 500,350, 500,350, 500,350, 500,350, 500,400, 500,350, 500,350, 500,350, 500,350, 500,350, 500,350, 500,1200, 500,350, 500,400, 500,350, 500,350, 500,350, 500,350, 500,350, 500,350, 500,350, 500,1200, 500,400, 500,350, 500,350, 500,350, 500,350, 500,350, 500,350, 500,350, 550,1150, 500,350, 550,1150, 550,350, 500,1150, 550,1150, 550,350, 500,350, 500,1200, 500,350, 500,1150, 550,300, 550,1200, 500,1200, 500,350, 500,1200, 500};
    digitalWrite(LEDOUT, HIGH);
    for (int i = 0; i < maxrep; i++) {
      irsend.sendRaw(rawData, lenData, freq_ir);
      delay(50);
    }
    digitalWrite(LEDOUT, LOW);  
  }    
}
