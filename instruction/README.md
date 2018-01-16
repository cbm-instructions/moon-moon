## Materialien und Werkzeuge

### Materialien
* Arduino Uno
* 3x Force Resistance Sensor
* 1 Neopixel LED Ring (4/4)
* Sperrholzplatte 4x460x61 mm
* Kabel
* Streifenrasterplatine
* 5 Pin Stiftleiste
* 2x 6 Pin Stiftleiste
* 5 x 10 kΩ Widerstände
* Holzleim
* Klebeband
* Rundstab 12 x 12 mm 0,5m (Buche)
* Schmirgelpapier

### Werkzeuge
* Laser Cutter
* Dremel
* Lötkolben
* Zange
* Heißklebepistole

## Vorbereitung

### Benötigte Vorkenntnisse

* Grundlegende handwerkliche Kentnisse
* Arduino Kentnisse
* Löten
* C++ (alles)

### Zusammenlöten des LED-Rings

### Drucken der Platten

Als erstes werden die SVG-Dateien für den Laser Cutter benötigt. Diese können [hier](https://github.com/cbm-instructions/moon-moon/tree/master/lasercutter/) heruntergeladen werden.

Es müssen folgende SVG-Dateien geschnitten werden hierzu wird die Sperrholzplatte 4x460x61 mm benutzt:

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

Danach bauen Sie eine Steckplatine um alle drei Drucksensoren später mit dem Arduino zu verbinden. Die obere waagerechte Steckleiste ist für die Grounds. An den linkesten Stecker dieser Steckleiste wird der Ground des Arduinos befestigt.
An alle anderen Pins werden die Grounds von den drei Drucksensoren befestigt (die zwei zusätzlichen Stecker dienen nur als Ersatz). Der Ground ist mit jeweils einem Widerstand mit jeder der anderen Grounds verbunden. Die Input Pins des Arduinos werden mit den Pins auf der exakt gegenüberliegenden Seite der Grounds verbunden. Die linke horizontale Steckerleiste wird benutzt um alle Sensoren mit dem 5V Eingang des Arduinos zu verbinden.

<p align="center">
<img src="/images/SensorSteckplatten.png" alt="SensorSteckplatten.png"/>
</p>

#### 2. Fertigung der Bodenplatte mit Sensoren

In diesem Schritt werden die Sensoren an die Bodenplatte geklebt und die Stelzenhalterplatte befestigt.

Benötigte Materialien für diesen Schritt:
  * Stelzenhalterplatte
  * Bodenplatte
  * Die drei Drucksensoren
  * Holzleim
  * Rundstab 12 x 12 mm 0,5m (Buche)
  * Klebeband
  * Heißklebepistole

Schnittreste vom Laser Cutter:
<p align="center">
<img src="/images/kleineStuetzeb.jpg" alt="kleineStuetzeb.jpg"/ width ="200px" height ="180">
</p>


Als erstes sollten Sie die Stelzenhalterplatte mittig auf die Bodenplatte legen und die Stellen markieren an denen die Löcher sind. Auf diese Stellen werden nun die Drucksensoren geklebt (diese haben bereits eine Klebefläche). Danach kann die Stelzenhalterplatte wie vorher auf die Bodenplatte gelegt werden. Wir haben die runden Schnittreste des Laser Cutters als Zwischenstücke benutzt um die Bodenplatte mit der Stelzenhalterplatte zu befästigen, so dass diese nicht die Sensoren berührt. Schneiden Sie drei gleichlange Stücke vom Rundstab (je 70 mm) ab . Kleben Sie diese wie auf dem unteren Bild leicht versetzt zu den Drucksensoren auf die Stelzenhalterplatte (Mit Holzleim oder Heißklebepistole).
Am Schluss kann man noch die Kabel mit Klebeband fixieren.


<p align="center">
<img src="/images/bodenFertig.jpg" alt="bodenFertig.jpg">
</p>


#### 3. Fertigung der LED-Ring Platte


#### 4. Fertigung der Druckplatte

In diesem Schritt wird die Druckplatte erstellt auf die später das Handy gelegt werden soll.

Benötigte Materialien für diesen Schritt:
  * DruckplatteOben
  * DruckplatteUnten
  * Rundstab 12 x 12 mm 0,5m (Buche)
  * Heißklebepistole
  * Holzleim
  * Dremel oder Schmirgelpapier

Als erstes kleben Sie die DruckplatteOben und die DruckplatteUnten mit Holzleim so zusammen das drei der Löcher exakt übereinande liegen. In die drei von der oberen Platte verschlossen Löcher werden nun drei gleich große Holzstäbe (78 mm) festgeklebt (Holzleim oder Heißklebepistole). Die unteren Enden der Holzstäbe können mit Schmirgelpapier oder einem Dremel an den Seiten verkleinert werden so das diese die Drucksensoren besser treffen.

<p align="center">
<img src="/images/druckplatte.jpg" alt="druckplatte.jpg"/>
</p>
