#include <Arduino.h>
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "SleepingTimeState.h"
#include "TimeInState.h"
#include "HistoryState.h"

void SleepingTimeState::setup() {
    this->ring->TheaterChase(this->ring->Color(25, 25, 25), this->ring->Color(0, 255, 0), 200, FORWARD);
};

void SleepingTimeState::loop() {

    if (this->getRunningTime() / 1000 > 20) {
        this->memory->setCurrentOnTime(false);
        Serial.print("Set OnTime: ");
        Serial.println(false);
        this->changeState(new HistoryState());
    }

    //do not check for touches directly
    if (this->getRunningTime() > 500 && this->forceSensors->wasTouched()) {
        this->changeState(new TimeInState());
    }
};



