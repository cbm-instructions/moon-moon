
# Bauanleitung

In diesem Abschnitt befindet sich die komplette Anleitung zum Bau von Halexa. Der Code für den Arduino befindet sich [hier](code/).

## Materialien und Werkzeuge

### Materialien
* Arduino Uno
* 3x Force Resistance Sensor
* 4 Neopixel LED 1/4 Ringe mit jeweils 15 Pixeln, insgesamt also 60 Pixel
* Sperrholzplatte 4x460x61 mm
* Kabel
* 1 x Streifenrasterplatine
* 5 Pin Stiftleiste
* 3x 6 Pin Stiftleiste
* 2x 8 Pin Stiftleiste
* 5 x 10 kΩ Widerstände
* Holzleim
* Klebeband
* Rundstab 12 x 12 mm 0,5m (Buche)
* Schmirgelpapier
* Doppelseitiges Klebeband
* milchige Plexiglassscheibe 170x170 mm
* Lötzinn
* Gummiband oder Schnur

### Werkzeuge
* Laser Cutter
* Dremel
* Lötkolben
* Zange
* Heißklebepistole
* Teppichmesser

## Vorbereitung

### Benötigte Vorkenntnisse

* Grundlegende handwerkliche Kenntnisse
* Arduino Kenntnisse
* Löten
* C++: Pointer, Klassen, Speicheralloziierung und Grundlagen sollten bekannt sein
* Das Konzept eines Zustandsautomaten sollte bekannt sein

### Zusammenlöten des LED-Rings

Die 4 Viertelringe müssen zu einem Ring zusammengelötet werden und es müssen die drei notwendigen Leitungen als Litzen herausgelegt werden.
Das folgende Bild zeigt einen zusammengelöteten Ring ohne Litzen.

<p align="center">
<img src="/images/Neopixel.jpg" alt="Neopixel.jpg"/>
</p>

An einen der vier GND, IN und VCC Kontakte müssen jetzt noch Litzen mit einer Länge von circa 10cm angelötet werden.

### Schneiden der Platten

Als erstes werden die SVG-Dateien für den Laser Cutter benötigt. Diese können [hier](../lasercutter/) heruntergeladen werden. Wichtig dabei, ist die Schnittreste des Cutters nicht wegzuwerfen. Sie werden später benötigt.

Es müssen folgende SVG-Dateien geschnitten werden hierzu wird die Sperrholzplatte (4x460x61 mm) benutzt:

* Grundplatte.svg
* Stelzenhalter.svg
* LedRingHalterung.svg
* Kabelplatte.svg
* DruckplatteUnten.svg
* DruckplatteOben.svg
* Den größeren der beiden Mäntel in Mantel.svg

**Tipp:** Beim Schneiden des Mantels ist es wichtig die Stärke des Lasers zu erhöhen, da dieser sonst nicht komplett durchschneidet und der Mantel leicht bricht.

**Tipp:** Die .dxf Datei erlaubt es die technische Zeichnung im Rohformat zu öffnen. Hierzu kann z.B. LibreCad verwendet werden.

Die geschnittenen Platten sollten ungefähr so aussehen:

<p align="center">
<img src="/images/holzplatten.jpg" alt="holzplatten.jpg"/>
</p>

Als letztes wird noch einmal die LedRingHalterung benötigt aber diesmal mit der Plexiglassscheibe (170x170 mm). Diese liegt später auf dem LED-Ring.

<p align="center">
<img src="/images/plexiglassscheibe.jpg" alt="plexiglassscheibe.jpg"/>
</p>



## Schritt für Schritt Anleitung

#### 1. Verkablen der drei Drucksensoren
In diesem Schritt werden die Drucksensoren verkabelt und über eine Platine verbunden, so dass sie später einfacher mit dem Arduino verbunden werden können.

**Benötigte Materialien für diesen Schritt:**
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

Danach bauen Sie eine Steckplatine um alle drei Drucksensoren später mit dem Arduino zu verbinden. Die obere waagerechte Steckleiste ist für die Grounds. An den vertikalen Stecker dieser Steckleiste wird der Ground des Arduinos befestigt.
An alle anderen Pins werden die Grounds von den drei Drucksensoren befestigt (die zwei zusätzlichen Stecker dienen nur als Ersatz). Der Ground ist über jeweils einen Widerstand mit jedem der anderen Grounds verbunden. Die Input Pins des Arduinos werden mit den Pins auf der exakt gegenüberliegenden Seite der Grounds verbunden. Die linke horizontale Steckerleiste wird benutzt um alle Sensoren mit dem 5V Eingang des Arduinos zu verbinden.

Ein logischer Schaltplan und Aufbau befindet sich [hier](#logischer-schaltplan-und-aufbau).

<p align="center">
<img src="/images/SensorSteckplatten.png" alt="SensorSteckplatten.png"/>
</p>

#### 2. Fertigung der Bodenplatte mit Sensoren

In diesem Schritt werden die Sensoren an die Bodenplatte geklebt und die Stelzenhalterplatte befestigt.

**Benötigte Materialien für diesen Schritt:**
  * Stelzenhalterplatte
  * Bodenplatte
  * Die drei Drucksensoren
  * Holzleim
  * Rundstab 12 x 12 mm 0,5m (Buche)
  * Klebeband
  * Heißklebepistole

Zusätzlich muss man die Schnittreste des Laser Cutters benutzen:
<p align="center">
<img src="/images/kleineStuetzeb.jpg" alt="kleineStuetzeb.jpg"/ width ="200px" height ="180">
</p>

Als erstes sollten Sie die Stelzenhalterplatte mittig auf die Bodenplatte legen und die Stellen markieren an denen die Löcher sind. Auf diese Stellen werden nun die Drucksensoren geklebt (diese haben bereits eine Klebefläche). Danach kann die Stelzenhalterplatte wie vorher auf die Bodenplatte gelegt werden. Wir haben die runden Schnittreste des Laser Cutters als Zwischenstücke benutzt um die Bodenplatte mit der Stelzenhalterplatte zu befästigen, so dass diese nicht die Sensoren berührt. Schneiden Sie drei gleichlange Stücke vom Rundstab (je 70 mm) ab . Kleben Sie diese wie auf dem unteren Bild leicht versetzt zu den Drucksensoren auf die Stelzenhalterplatte (Mit Holzleim oder Heißklebepistole).
Am Schluss können Sie noch die Kabel mit Klebeband fixieren und die Kabel mit der bereits erstellten Steckplatine verbinden.


<p align="center">
<img src="/images/bodenFertig.jpg" alt="bodenFertig.jpg">
</p>


#### 3. Fertigung der LED-Ring Platte

In diesem Schritt wird die Platte die den LED-Ring hält erstellt, welche dann an der zuvor erstellten Bodenplatte befestigt wird.

**Benötigte Materialien für diesen Schritt:**
  * LedRingHalterung
  * Kabelplatte
  * Holzleim
  * Neopixel LED Ring
  * Doppelseitiges Klebeband
  * Die zuvor erstelle Bodenplatte
  * Holzstab

Kleben Sie die Kabelplatte mit Holzleim auf die LedRingHalterung, so dass sich alle sechs Löcher exakt überlappen. Nachdem der Leim getrocknet ist können Sie den LED-Ring wie im Bild, mit dem doppelseitigen Klebeband, auf den übergeblieben Rand kleben. Achten Sie darauf, dass die Kabel des LED-Rings durch eine der drei hierfür vorgesehenen Kabellöcher laufen.

Zusätzlich muss der Übergang vom 1. zum 60. Pixel exakt wie auf dem folgenden Bild ausgerichtet werden.

<p align="center">
<img src="/images/numbered.png" alt="numbered.png">
</p>

* (3) 0. Pixel des Rings (Der erste Pixel nach dem Anlötpunkt der IN-Leitung)
* (4) Lötstelle zwischen zwei Viertelringen muss eine exakte Verlängerung der Kabelführungskante (rot) sein
* (5) 59. Pixel des Rings

Sind (3) bis (5) korrekt ausgerichtet, dann gilt für (1) und (2)

* (1) Diese Stelze + Sensor ist für die Bewertungslogik ein "positiver" Sektor und der Sensor wird an A1 angeschlossen
* (2) Diese Stelze + Sensor ist für die Bewertungslogik ein "negativer" Sektor und der Sensor wird an A2 angeschlossen

Als letztes kleben Sie, mit Holzleim, die erstellte LED-Ring Platte auf die zuvor erstellte Bodenplatte wie im Bild unten zu sehen ist.

**ACHTUNG:** Achten Sie darauf, dass die Löcher, durch die später die Stelzen der Druckplatte laufen (nicht die Kabellöcher) exakt über den Drucksensoren liegen.

**Tipp:** Benutzen Sie den Rundstab als Fixierung.

<p align="center">
<img src="/images/mittelstueck.jpg" alt="mittelstueck.jpg">
</p>



#### 4. Fertigung der Druckplatte

In diesem Schritt wird die Druckplatte erstellt auf die später das Handy gelegt werden soll.

**Benötigte Materialien für diesen Schritt:**
  * DruckplatteOben
  * DruckplatteUnten
  * Rundstab 12 x 12 mm 0,5m (Buche)
  * Heißklebepistole
  * Holzleim
  * Dremel oder Schmirgelpapier

Als erstes kleben Sie die DruckplatteOben und die DruckplatteUnten mit Holzleim so zusammen das drei der Löcher exakt übereinande liegen. In die drei von der oberen Platte verschlossen Löcher werden nun drei gleich große Holzstäbe (78 mm) festgeklebt (Holzleim oder Heißklebepistole). Die unteren Enden der Holzstäbe können mit Schmirgelpapier oder einem Dremel an den Seiten verkleinert werden, so dass diese die Drucksensoren besser treffen.

<p align="center">
<img src="/images/druckplatte.jpg" alt="druckplatte.jpg"/>
</p>

**Tipp:** Die Druckplatte kann optional auf der Rückseite mit Gewichten versehen um so ein erhöhtes Grundgewicht zu erhalten. Dadurch arbeiten die Sensoren wesentlich besser da sie vor allem bei wenig Druck dazu neigen ungenau zu sein. Der Sensor kommt so in seinen optimalen Arbeitsbereich. Der Schwellwert im Programm muss dazu angepasst werden [phoneIsThereThreshold in ForceSensors.cpp](code/ForceSensors.cpp).

#### 5. Arduino Steckplatte

In diesem Schritt wird eine Steckplatte erstellt die mit den Drucksensoren und dem Led-Ring verbunden ist. Diese Steckplatte kann dann, wie ein Arduino Shield, später einfach auf den Arduino gesteckt werden und vereinfacht die Verkabelung.

**Benötigte Materialien für diesen Schritt:**
  * Streifenrasterplatine
  * Kabel
  * 1x 6 Pin Stiftleiste
  * 2x 8 Pin Stiftleiste
  * Arduino
  * Teppichmesser

Als erstes schneiden Sie eine Stück aus der Streifenrasterplatine aus, welches der Größe des Arduinos entspricht. Nehmen Sie den Arduino und Stecken Sie die 8 Pin Stiftleiste in Power die 6 Pin Stiftleiste in die Analogeingänge und die letzte 8 Pin Stiftleiste in die Digitaleingänge 0-7. Nun können Sie einfach die Streifenrasterplatine auf die Stiftleisten legen und diese festlöten. Achten Sie darauf, dass die Streifen von der einen Pinseite zu der anderen Pinseite des Arduinos verlaufen. Nachdem die Stiftleisten an der Streifenrasterplatine festgelötet sind, können sie die Platine abnehmen. Mit einem Teppichmesser können Sie nun wie im Bild in der mitte der Platine das Kupfer abkratzen um den Kontakt zu unterbrechen.

<p align="center">
<img src="/images/arduinoSteckplatte.png" alt="arduinoSteckplatte.png"/>
</p>

Löten Sie jeweils das Power-Kabel des LED-Rings und der Sensorsteckplatte an den 5V Streifen der Steckplatte. Genauso werden jeweils der Ground des LED-Rings und der Sensorsteckplatte an den Ground-Streifen der Steckplatte gelötet.
Zuletzt löten Sie die drei Inputkabel der Sensoren an die Analog Eingänge A0 - A2.
Bedenken Sie dabei die Ausrichtung aus Kapitel [Fertigung der LED-Ring Platte](#3-fertigung-der-led-ring-platte).
An A1 wird der Sensor angeschlossen, der im Uhrzeigersinn von LED 0 liegt. An A2 wird der Sensor angeschlossen, der gegen den Uhrzeigersinn von LED 0 liegt.

Ein logischer Schaltplan und Aufbau befindet sich [hier](#logischer-schaltplan-und-aufbau).

#### 6. Zusammensetzen

In diesem Schritt werden alle vorher erstellen Komponenten zusammengesetzt.

**Benötigte Materialien für diesen Schritt:**
  * Erstellte Bodenplatte
  * Erstellte Druckplatte
  * LED-Ring Platte
  * Holzmantel
  * Arduino und Steckplatte
  * Plexiglassscheibe
  * Doppelseitiges Klebeband
  * Dremel
  * Gummiband oder Schnur

Als erstes verkabeln Sie den LED-Ring und die Drucksensoren mit dem Arduino und befestigen diesen mit doppelseitigen Klebeband an der Bodenplatte.

<p align="center">
<img src="/images/verkabelung.jpg" alt="verkabelung.jpg"/>
</p>

Dann können Sie die Druckplatte in die dafür vorgesehenen Löcher stecken. Zwischen die Druckplatte und die LED-Ring Platte kommt die Plexiglassscheibe.

**Tipp:** Durch Klebeungenauigkeiten kann es sein, dass die Stelzen an einer der Führungsöffnungen reiben, oder die Stelzen nicht exakt die Sensoren berühren. In diesem Fall eignet es sich die Stelzen an den kritischen Stellen leicht mit dem Dremel anzupassen. So wird der reibungslose Ablauf ermöglicht.

<p align="center">
<img src="/images/zusammen.jpg" alt="zusammen.jpg"/>
</p>

Als letztes wird der Holzmantel um die Konstruktion gelegt. Aus Wartungszwecken haben wir den Mantel nur mit einem Gummiband befestigt. Hierzu können Sie mit einem Dremel vier Löcher in den Mantel bohren und dann mit einer Schnur oder einem Gummiband befestigen. Die bleibende Öffnung ist für das Stromkabel des Arduinos.

<p align="center">
<img src="/images/mantelbefestigung.jpg" alt="mantelbefestigung.jpg"/>
</p>

**Tipp:** Für eine saubere und permanente Ummantelung muss der Mantel ca 1cm länger gedruckt werden. Zusätzlich müssen Kabelöffnungen gebohrt werden und ein permanenter Befestigungsmechanismus gefunden werden.

Halexa kann nun in Betrieb genommen werden.

## Anpassung der Software und Entfernen der Demo-Daten

Aktuell gibt es noch keine Einstellungsmöglichkeiten. Die Software muss direkt bearbeitet werden und auf den Arduino gespielt werden.

Die [arduino.ino](code/arduino.ino) erlaubt das Bestimmen des Startzustands und der PIN Nummern.
in der setup Methode gibt es eine Reihe von handgeschriebenen Demo Daten, die entfernt werden sollten.

Parameter zur Druckplatte befinden sich in der [ForceSensors.cpp](code/ForceSensors.cpp). Hier können Schwellwerte für Handys und Berührungen gesetzt werden. Auch können die Sensoren gewichtet werden, damit sie gleichstarke Werte liefern.

Parameter zur Zeit befinden sich in der [Clock.cpp](code/Clock.cpp). Hier kann die Schlafenszeit definiert werden. Durch Anpassen der Logik in isSleepTime() kann (nach der Anbindung einer besseren Uhr) eine korrekte Schlafenszeit nach Stunde (hoursOfDay) und Minuten (minutesOfHour) erkannt werden.
Es kann auch eine optimale Schlafdauer festgelegt werden.

Die [NeoPatterns.cpp](code/NeoPatterns.cpp) erlaubt zusammen mit allen State-Klassen die Anpassung der Animationen und Farben.

Die [Memory.cpp](code/Memory.cpp) kann genutzt werden um einen echten persistenten Speicher anzubinden.

## Logischer Schaltplan und Aufbau

Zur Darstellung wurde ein LED Stripe genommen. Dieser hat die gleichen Anschlüsse wie der zu verwendende Ring

<p align="center">
<img src="/fritzing/cbm_Schaltplan.png" alt="cbm_Schaltplan.png"/>
</p>

<p align="center">
<img src="/fritzing/cbm_Steckplatine.png" alt="cbm_SteckPlatine.png"/>
</p>
