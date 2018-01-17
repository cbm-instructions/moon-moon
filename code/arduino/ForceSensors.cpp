#include "ForceSensors.h"

const int phoneIsThereThreshold = 200; //minimal force needed to recognize phone
const int phoneIsThereTimeThreshold = 3000; //minimal time a phone needs to be on the pressure sensor to recognize it as there or gone
const float weightA = 1;
const float weightB = 1;
const float weightC = 1;
const int numReadings = 10;
const int delayTime = 10;

boolean phoneIsThere = false;
float readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
float total = 0;                  // the running total
float average = 0;                // the average
int phoneIsThereTime = 0;

ForceSensors::ForceSensors(int sensorPinA, int sensorPinB, int sensorPinC) {
    this->sensorPinA = sensorPinA;
    this->sensorPinB = sensorPinB;
    this->sensorPinC = sensorPinC;
}

void ForceSensors::setup() {
    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
        readings[thisReading] = 0;
    }
}

boolean ForceSensors::wasTouched() {
    return average > phoneIsThereThreshold;
}

int ForceSensors::getDominantSensor() {

    float minDiff = 100.0;
    float a = weightA * analogRead(this->sensorPinA);
    float b = weightB * analogRead(this->sensorPinB);
    float c = weightC * analogRead(this->sensorPinC);

    if ((a - b) > minDiff && (a - c) > minDiff) {
        return 0;
    } else if ((b - a) > minDiff && (b - c) > minDiff) {
        return 1;
    } else if ((c - b) > minDiff && (c - a) > minDiff) {
        return 2;
    } else return 3;

}

void ForceSensors::loop() {

    // subtract the last reading:
    total = total - readings[readIndex];
    // read from the sensor:
    readings[readIndex] = (weightA * analogRead(this->sensorPinA) + weightB * analogRead(this->sensorPinB) +
                           weightC * analogRead(this->sensorPinC)) / 3;
    // add the reading to the total:
    total = total + readings[readIndex];
    // advance to the next position in the array:
    readIndex = readIndex + 1;

    // if we're at the end of the array...
    if (readIndex >= numReadings) {
        // ...wrap around to the beginning:
        readIndex = 0;
    }

    // calculate the average:
    average = total / numReadings;

    Serial.println(average);

    if (average > phoneIsThereThreshold) {
        phoneIsThereTime += delayTime;
        if (phoneIsThereTime >= phoneIsThereTimeThreshold) {
            phoneIsThereTime = phoneIsThereTimeThreshold;
            phoneIsThere = true;
        }
    } else {
        phoneIsThereTime -= delayTime;
        if (phoneIsThereTime <= 0) {
            phoneIsThereTime = 0;
            phoneIsThere = false;
        }
    }

}

boolean ForceSensors::isPhoneThere() {
    return phoneIsThere;
}

long ForceSensors::getPhoneIsThereTime() {
    return phoneIsThereTime;
}
