//
// Created by Adrian Endrich on 15.01.18.
//

#include "RateStandbyState.h"
#include "RateState.h"
#include "SleepingTimeState.h"


void RateStandbyState::setup() {
    this->ring->RainbowCycle(50, FORWARD);
};

void RateStandbyState::loop() {
    //do not check for touches directly
    if (this->forceSensors->wasTouched()) {
        this->changeState(new RateState());
    }

    if (this->clock->isSleepTime()) {
        this->memory->setCurrentMood(false);
        Serial.print("Set CurrentMood: ");
        Serial.println(false);
        this->memory->persistCurrentDayInfo();
        this->changeState(new SleepingTimeState());
    }


};