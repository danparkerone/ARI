#ifndef CONFIG.H
#define CONFIG.H

#include <IRremote.h> // Utilizzare ver.2.1.0
#include <SoftwareSerial.h>

//Il LED IR va sul pin 3
// definisco i pin TX e RX per la seriale Bluetooth
#define RX_BT 7
#define TX_BT 8
#define LEDOUT 2 // definisce pin x LED
#define DELAYTX 80 // ritardo per ripetizione segnale IR
#define FIR 38  // Khz. Frequenza TX IR

IRsend irsend;                        // IR
SoftwareSerial SSerial(RX_BT, TX_BT); // BT
int cmd;
String str;
unsigned int data19[19];
unsigned int data21[21];
unsigned int data23[23];
unsigned int data25[25];
unsigned int data67[67];
unsigned int data87[87];
unsigned int data99[99];

#endif
