#ifndef READSERIAL.H
#define READSERIAL.H

void readConsole();
void readBT();

void readConsole(){
  if (Serial.available()) {
    char ch = Serial.read();
    if (ch == '\n') {
      cmd = str.toInt();
      str = "";
    } else if (ch != '\r') {
      str += ch;
    }
  }
}

void readBT(){
  if (SSerial.available()) {  // ascolto seriale BT.
    char ch = SSerial.read();
    if (ch == '\n') {
      cmd = str.toInt();
      str = "";
    } else if (ch != '\r') {
      str += ch;
    }
  }
}

#endif
