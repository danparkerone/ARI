#include <SoftwareSerial.h>

// definisco i pin TX e RX per la seriale Bluetooth
#define RX_BT 7
#define TX_BT 8

#define PIN_LED 2 // definisce pin x LED

// Inizializza seriale software
SoftwareSerial SSerial(RX_BT, TX_BT);

void setup() {
  Serial.begin(9600);
  Serial.println("OK");
  SSerial.begin(9600);
  
  pinMode(PIN_LED, OUTPUT); // LED
}

String str = "";

void loop() {
  if (SSerial.available()) {  // in ascolto di dati provenienti da SS (BT).
    char ch = SSerial.read(); // se presenti carico in ch
    Serial.println(ch); // visualizzo i caratteri ricevuti
    // ignoro i caratteri \n e \r
    if ( (ch == '\n') || (ch == '\r')) { // se ricevo i caratteri \n o \r allora elaboro stringa con cmd() e azzero str
      cmd(str);
      str = "";
    } else {
      str += ch; // altrimenti aggiungo a str il carattere ricevuto
    }
  }
}

void cmd(String str) {
  char c = str.charAt(0);
  if (c == 'a') {
    Serial.println("ON");
    digitalWrite(13, HIGH);  
  } else if (c == 's') {
    Serial.println("OFF");
    digitalWrite(13, LOW);  
  }
}
