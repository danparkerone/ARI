#ifndef TXIR.H
#define TXIR.H

void transmitIr(int rep, String line, int lendata);
void waitTx();

void txIr(int rep, int lendata) {
  switch(lendata) {
    case 19: for (int i = 0; i < rep; i++) {digitalWrite(LEDOUT, HIGH); irsend.sendRaw(data19, lendata, FIR); delay(DELAYTX); digitalWrite(LEDOUT, LOW);} break;
    case 21: for (int i = 0; i < rep; i++) {digitalWrite(LEDOUT, HIGH); irsend.sendRaw(data21, lendata, FIR); delay(DELAYTX); digitalWrite(LEDOUT, LOW);} break;
    case 23: for (int i = 0; i < rep; i++) {digitalWrite(LEDOUT, HIGH); irsend.sendRaw(data23, lendata, FIR); delay(DELAYTX); digitalWrite(LEDOUT, LOW);} break;
    case 25: for (int i = 0; i < rep; i++) {digitalWrite(LEDOUT, HIGH); irsend.sendRaw(data25, lendata, FIR); delay(DELAYTX); digitalWrite(LEDOUT, LOW);} break;
    case 67: for (int i = 0; i < rep; i++) {digitalWrite(LEDOUT, HIGH); irsend.sendRaw(data67, lendata, FIR); delay(DELAYTX); digitalWrite(LEDOUT, LOW);} break;
    case 87: for (int i = 0; i < rep; i++) {digitalWrite(LEDOUT, HIGH); irsend.sendRaw(data87, lendata, FIR); delay(DELAYTX); digitalWrite(LEDOUT, LOW);} break;
    case 99: for (int i = 0; i < rep; i++) {digitalWrite(LEDOUT, HIGH); irsend.sendRaw(data99, lendata, FIR); delay(DELAYTX); digitalWrite(LEDOUT, LOW);} break;
  }             
}

void waitTx() { // TX tasto VERDE PRIMARE per attesa invio IR Primare n.48 len 21
  for (int i = 0; i < 21; i++) data21[i] = pgm_read_word_near(dataRow48 + i); txIr(1, 21);
}

#endif
