ARI
Accentratore (a) Raggi Infrarossi
Arduino Remote InfraRed

Centralina per la tramissione di codici IR tramite App via Bluetooth.
Vengono copiati i codici base di alcuni dispositivi del mobile impianti:
- Lettore BR PRIMARE BD32
- TV PANASONIC
- DECODER DENON
I comandi verranno impartiti tramite una apposita App per smartphone ANDROID
creata con MIT App Inventor.

Si utilizza:
ARDUINO NANO
MODULO BT HC-05
(Convertitore di tensione 5-3.3V) partitore 1.2K - 2.2K per abbassare la tensione a 3.3V
da Tx di ARDUINO a Rx del modulo BT. Viceversa non serve, in quanto l'uscita da BT è a 3.3V,
quindi accettata da ARDUINO
Emettitore ad infrarossi LED IR5308C

Per IR utilizzare la libreria IRremote.h ver.2.1.0
nel file IRremoteInt.h alla riga 124 modificare _GAP a 50 (5000 di default)

----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
comandi:
PRIMARE ON/OFF		a
PRIMARE PALY		b
PRIMARE STOP		c
PRIMARE PREV		d
PRIMARE NEXT		e
PRIMARE PAUSE		f (stesso codice di PLAY ma mantenuto per un tempo maggiore)
PRIMARE EJECT		g (stesso codice di STOP ma mantenuto per un tempo maggiore)
..
PANASONIC TV ON/OFF	h
PANASONIC TV VOL+	i
PANASONIC TV VOL-	l
PANASONIC TV CH+	m
PANASONIC TV CH-	n
..
ROTEL DECODER ON/OFF	s
ROTEL DECODER VOL+	t
ROTEL DECODER VOL-	u


----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------

