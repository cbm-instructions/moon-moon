# How to make Halexa

<p align="center">
<img src="images/halexa.gif" alt="halexa.gif"/>
</p>

## Einleitung
Halexa hilft dem Nutzer dabei einen gesünderen Schlafrythmus zu bekommen, indem sie den Nutzer motiviert abends das Handy rechtzeitig wegzulegen.
Zusätzlich wird die Stimmung des Nutzers nach dem Schlaf abgefragt, um zusammen mit den gesammelten Schlafdaten, einen Rückschluss auf das Schlafverhalten des Nutzers zu schließen.
Das Ergebnis ist eine Statistik, die Laune, Schlafdauer und rechtzeitiges Schlafen in Relation setzt, um dem Nutzer zu zeigen, dass seine Tageslaune von der Schlafqualität abhängt.

## Challenge

> In einer Gesellschaft mit steigender Lebenserwartung, mangelnder Bewegung, sowie
steigendem Übergewicht sind Lösungen gefragt die langfristig helfen die
Gesundheitskosten zu reduzieren, indem sie Menschen zu einem gesünderen Leben
anhalten. Auch Technologie kann hier einen wertvollen Beitrag leisten, indem sie
Menschen dabei unterstützt sich mehr zu bewegen, mehr mit anderen Menschen
gemeinsam zu unternehmen, gesünder zu essen, ein anderes Schlafverhalten zu
entwickeln etc.
Inspiriert von dieser Entwicklung ist es das Ziel Ihrer Challenge, Ideen für „Health and
Well-being“ zu entwickelten und zu lauffähigen Demonstratoren umzusetzen. Diese
sollen zu einer Verbesserung von Wohlbefinden und Gesundheit beitragen. Es ist
dabei Ihre Aufgabe, „smarte“ Objekte zu erschaffen die das Wohlbefinden ihrer
Nutzer nachhaltig verbessern. Diese könne für Kinder, Berufstätige, Studierende,
Senioren oder andere Nutzergruppen sein. Zu diesen Objekten zählen
Außenanlagen, Möbel, Gebäude, Deko-Objekte, usw. Jedes dieser Objekte kann
durch Technologie erweitert werden und so Information sammeln, verbreiten oder
anzeigen. Dabei dürfen die Objekte auch spielerische Elemente besitzen. Eine
Anbindung dieser Objekte an Apps oder Fitnesstracker ist denkbar, steht aber nicht
im Mittelpunkt. Der Fokus Ihres Beitrags soll auf den „smarten Objekten“ liegen.

Daraus ergibt sich folgende Challenge:

> Wie könnten Menschen durch die Interaktion mit intelligenten
> Objekten mehr Wohlbefinden und/oder Gesundheit erlangen?


Zu dieser Challenge haben wir mehrere Interviews geführt, aus denen hervorging, dass viele Studenten zu wenig Schlafen. Einer der Gründe hierfür war, dass die Studenten viel Zeit an Smartphones vor dem Einschlafen verbringen. Das Gerät hält den Studenten durch Licht und Inhalt vom Schlafen ab. Das führt zu einem ungesunden Schlafrythmus und zur Müdigkeit am nächsten Tag. Diese kann zu weiteren Effekten führen, wie z.b. Motivationslosigkeit und einem späteren Einschlafen.

Aufgrund dieser Erkentnisse haben wir den folgenden POV formuliert.

### POV

  > Wie können wir verhindern, dass Studenten vor dem Einschlafen zu lange ihre Zeit,
  in der sie schlafen könnten, mit elektronischen Geräten verschwenden umso ihren
  Schlafrhythmus zu verbessern.

## Bauanleitung

Die Anleitung so wie liste aller benötigten Materialien befindet sich [hier](INSTRUCTIONS.md).

## Code

Der Code für das Projekt wurde in C++ geschrieben und befindet sich [hier](code/).

### Zustandsautomat und die Bedienung

<p align="center">
<img src="/images/zustandsautomat.jpg" alt="zustandsautomat.jpg"/>
</p>

Halexa benutzt einen Zustandsautomaten als Basis. Jeder Zustand hat eine eigene Anzeige und mögliche Aktionen.
Halexa beginnt im Standby-Zustand. Dieser Zustand zeigt lediglich die Bereitschaft von Halexa.

Ein tippen auf die Fläche führt zum History-Zustand. Er zeigt den Verlauf der vergangenen Tage an. Ein blauer Punkt zeigt den aktuellen, unbewerteten Tag. Im Uhrzeigersinn vom blauen Punkt aus findet man die vergangenen Tage. Dabei ist der Punkt direkt neben dem blauen Punkt der gestrige Schlaf, der nächste der vorgestrige usw. Nach einer gewissen Zeit schaltet Halexa wieder in den Standby-Zustand.

Sobald die Schlafenszeit erreicht ist (aktuell im Quellcode festgelegt auf 10 Sekunden nach jeder vollen Minute), wechselt Halexa aus dem Standby- und History-Zustand in den SleepingTime-Zustand. Dieser macht den Nutzer darauf aufmerksam, dass er sein Handy weglegen sollte und schlafen gehen sollte. Legt der Nutzer sein Handy ab, wird über den TimeIn-Zustand, ein reiner Animations- und Verzögerungszustand, in den Sleep-State gewechselt.
Verpasst der Nutzer die Schlafenszeit, geht das Gerät in den Standby und wiederholt den Alarm nach einiger Zeit. Es ist zu beachten, dass Halexa das Verpassen speichert. Dieses fließt in die Bewertung als "zu spät schlafen gegangen" ein.

Wird nach dem Schlaf das Handy wieder hochgenommen, erkennt Halexa nach einer kurzen, abbrechbaren, TimeOut-Periode, das Ende des Schlafs und geht in den Bewertungs-Zustand.

Im Bewertungszustand, der ebenfalls einen Standby erlaubt, Hat der Nutzer die Möglichkeit durch Antippen des aufleuchtenden Sektors, seine Stimmung nach dem Schlaf zu bewerten. Fühlt er sich gut und ausgeschlafen, wählt er grün. Falls er müde und schlecht gelaunt ist, wählt er rot. Die Bewertung ist bis zum nächsten Schlafenszeitpunkt möglich. Wird dieser erreicht, geht Halexa wieder in den SleepingTime-Zustand und bewertet den Schlaf negativ. Das soll den Nutzer motivieren rechtzeitig, aber zu einem flexiblen Zeitpunkt, zu bewerten.

## Bewertung des Schlafs

Der Schlaf wird anhand folgender drei Kriterien bewertet:

* rechtzeitiges Schlafen gehen
* ausreichende Schlaflänge
* Laune nach dem Schlaf

Jedes der Kriterien kann der Schlafbewertung einen oder keinen Punkt hinzufügen. Somit sind die Punktzahlen null bis drei möglich.

Ein Schlaf mit drei Punkten wird als sehr positiv bewertet und erhält eine deutlich grüne Farbe in der Statistik.
Ein Schlaf mit weniger als drei Punkten wird als eher negativ betrachtet und resultiert in den rot wirkenden Farben: hellorange (zwei Punkte), dunkelorange (ein Punkt), rot (null Punkte).

Es entsteht also eine Darstellung, die tendenziell die zwei Gruppen "positiv" und "negativ" darstellt,aber in den Punktebereichen null bis zwei trotzdem eine Differenzierung erlaubt.

Ziel der halexa ist es dem Nutzer zu zeigen, dass das Einhalten der drei Schlafkriterien, zu einer besseren Stimmung führen kann. Im idealen Fall zeigt die Statistik eine allmählich grüner werdende Historie.

## Ideen zur Weiterentwicklung

1. Einsätzen eines Vibrationsmotors unter der obersten Platte für Vibrationsfeedback bei der Benutzung der Platte als Eingabegerät.

2. Erweiterung um Einstellungsmenü um Schlafenszeit, Weckzeit und länge des Schlafes einzustellen.

3. Hinzufügen von Kapazitiven Buttons um die oben erwähnten Einstellungen vorzunehmen (Drucksensoren zu ungenau).

4. Erweiterung der Nutzergruppe. Es können beispielsweise andere Ablenkungen, wie Zeitschriften und Bücher, weggelegt werden.

5. Technische Anbindung an Home-Automation z.B. IFTTT oder NFC-Trigger

#### Optische Verbesserungen

1. Absenken der obersten Platte, damit sie mit dem LED-Ring auf einer Höhe ist.

2. Die allgemeine Größe verringern.

3. Höherwertiges Material.

## Das Team

Adrian Endrich und Christopher Hansen
