#include <SoftwareSerial.h>

SoftwareSerial SSerial(7, 8); // RX, TX

void setup() {
  Serial.begin(38400);
  while(!Serial) {}

  SSerial.begin(38400);
  Serial.println("pronto");
} 

void loop() {
  if (SSerial.available()) {
    Serial.write(SSerial.read());
  }
  if (Serial.available()) {
    SSerial.write(Serial.read());
  }
}
