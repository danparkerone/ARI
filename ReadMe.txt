ARI
Accentratore (a) Raggi Infrarossi
(Arduino Remote InfreRed)

Centralina per la tramissione di codici IR tramite App via Bluetooth.
Vengono copiati i codici base di alcuni dispositivi del mobile impianti:
- Lettore BD PRIMARE BD32
- TV PANASONIC
- DECODER DENON
I comandi verranno impartiti tramite una apposita App per smartphone ANDROID
creata con MIT App Inventor.

Si utilizza:
- ARDUINO NANO;
- MODULO BT HC-05;
- (Convertitore di tensione 5-3.3V) partitore 1.2K - 2.2K per abbassare la tensione a 3.3V
  da Tx di ARDUINO a Rx del modulo BT. Viceversa non serve, in quanto l'uscita da BT è a 3.3V, quindi accettata da ARDUINO;
- Emettitore ad infrarossi LED IR5308C

Per IR utilizzare la libreria IRremote.h ver.2.1.0.
Nel file IRremoteInt.h alla riga 124 modificare _GAP a 50 (5000 di default).

Per Comandi e codici vedere il file Excel 'Codici.xlsx'

Versione corrente 2.2

----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------

ARI
Centralizer (a) Infrared rays
(Arduino Remote InfreRed)

Control unit for transmitting IR codes via App via Bluetooth.
The basic codes of some devices of the plant furniture are copied:
- BD player PRIMARE BD32
- TV PANASONIC
- DENON DECODER

The commands will be given through a special App for ANDROID smartphones created with MIT App Inventor.
It is used:
- ARDUINO NANO;
- MODULE BT HC-05;
- (Voltage converter 5-3.3V) divider 1.2K - 2.2K to lower the voltageto 3.3V
  from Tx of ARDUINO to Rx of BT module. Vice versa is not needed, as the output from BT is 3.3V, then accepted by ARDUINO;
- IR5308C LED infrared emitter.

For IR use the library IRremote.h ver.2.1.0.
In the irremoteint.h file on line 124 change _GAP to 50 (5000 by default).

For Commands and Codes, see the Excel 'Codici.xlsx'

Current version 2.2

----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
