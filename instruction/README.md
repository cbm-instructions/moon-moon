## Materialien und Werkzeuge

### Materialien
* Arduino Uno
* 3x Force Resistance Sensor
* 1 Neopixel LED Ring (4/4)
* Sperrholzplatte 4x460x61
* Kabel

### Werkzeuge
* Laser Cutter
* Lötkolben

## Vorbereitung

### Benötigte Vorkenntnisse

* Grundlegende handwerkliche Kentnisse
* Arduino Kentnisse
* Löten
* C++ (alles)

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

Als erstes sollten Sie die drei Drucksensoren mit Kabeln verlöten.

<p align="center">
<img src="/images/KabelSensor.png" alt="KabelSensor.png"/>
</p>

Danach bauen Sie eine Steckplatine um alle drei Drucksensoren miteinaden zu verbinden.
