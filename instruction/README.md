## Materialien und Werkzeuge

### Materialien
* Arduino Uno
* 3x Force Resistance Sensor
* 1 Neopixel LED Ring (4/4)
* Sperrholzplatte 4x460x61
* Kabel
* Streifenrasterplatine
* 5 Pin Stiftleiste
* 2x 6 Pin Stiftleiste
* 5 x 10 kΩ Widerstände

### Werkzeuge
* Laser Cutter
* Lötkolben
* Zange

## Vorbereitung

### Benötigte Vorkenntnisse

* Grundlegende handwerkliche Kentnisse
* Arduino Kentnisse
* Löten
* C++ (alles)

### Zusammenlöten des LED-Rings

### Drucken der Platten

Als erstes werden die SVG-Dateien für den Laser Cutter benötigt. Diese können [hier](https://github.com/cbm-instructions/moon-moon/tree/master/lasercutter/) heruntergeladen werden.

Es müssen folgende SVG-Dateien geschnitten werden:

* Grundplatte.svg
* Stelzenhalter.svg
* LedRingHalterung.svg
* Kabelplatte.svg
* DruckplatteUnten.svg
* DruckplatteOben.svg

* Den größeren der beiden Mäntel in Matel.svg

Die geschnittenen Platten sollten ungefähr so aussehen:

<p align="center">
<img src="/images/holzplatten.jpg" alt="holzplatten.jpg"/>
</p>

## Schritt für Schritt Anleitung

#### 1. Verkablen der drei Drucksensoren
In diesem Schritt werden die Drucksensoren verkabelt und über eine Platine verbunden, so dass sie später einfacher mit dem Arduino verbunden werden können.

Benötigte Materialien für diesen Schritt:
  * Kabel
  * Die drei Drucksensoren
  * Streifenrasterplatine
  * 5 Pin Stiftleiste
  * 2x 6 Pin Stiftleiste
  * 5 x 10 kΩ Widerstände
  * Lötkolben

Als erstes sollten Sie die drei Drucksensoren mit Kabeln verlöten.

<p align="center">
<img src="/images/KabelSensor.png" alt="KabelSensor.png"/>
</p>

Danach bauen Sie eine Steckplatine um alle drei Drucksensoren später mit dem Arduino zu verbinden. Die obere waagerechte Steckleiste ist für die Grounds. An den linkesten Stecker dieser Steckleiste wird der Ground des Arduinos befästigt.
An alle anderen Pins werden die Grounds von den drei Drucksensoren befästigt (die zwei zusätzlichen Stecker dienen nur als Ersatz). Der Ground ist mit jeweils einem Widerstand mit jeder der anderen Grounds verbunden. Die Input Pins des Arduinos werden mit den Pins auf der exakt gegenüberliegenden Seite der Grounds verbunden. Die linke horizontale Steckerleiste wird benutzt um alle Sensoren mit dem 5V Eingang des Arduinos zu verbinden.

<p align="center">
<img src="/images/SensorSteckplatten.png" alt="SensorSteckplatten.png"/>
</p>

#### 2. Fertigung der Bodenplatte mit Sensoren
