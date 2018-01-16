//
// Created by Adrian Endrich on 15.01.18.
//

#include "RateState.h"
#include <Arduino.h>
#include "Memory.h"
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "StandbyState.h"
#include "SleepState.h"
#include "HistoryState.h"
#include "RateStandbyState.h"
#include "SleepingTimeState.h"

void RateState::setup() {
    this->ring->Rate();
    long x = millis();
    this->memory->setSleptEnough((millis() - this->memory->sleepStartedAt) > 10000);
    Serial.print("Set SleptEnaugh: ");
    Serial.println((x - this->memory->sleepStartedAt) > 10000);
};

void RateState::loop() {
    //do not check for touches directly

    if (this->getRunningTime() > 500 && this->forceSensors->wasTouched()) {
        // write rating to history

        switch (this->forceSensors->getDominantSensor()) {
            case 2:
                this->memory->setCurrentMood(false);
                Serial.print("Set CurrentMood: ");
                Serial.println(false);
                this->memory->persistCurrentDayInfo();
                this->changeState(new HistoryState());
                break;
            case 1:
                this->memory->setCurrentMood(true);
                Serial.print("Set CurrentMood: ");
                Serial.println(true);
                this->memory->persistCurrentDayInfo();
                this->changeState(new HistoryState());
                break;
        }

    }

    if (this->clock->isSleepTime()) {
        this->memory->setCurrentMood(false);
        Serial.print("Set CurrentMood: ");
        Serial.println(false);
        this->memory->persistCurrentDayInfo();
        this->changeState(new SleepingTimeState());
    }

    if (this->getRunningTime() > 10000) {
        this->changeState(new RateStandbyState());
    }

};
