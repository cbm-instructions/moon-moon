#include <Arduino.h>
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "StandbyState.h"
#include "SleepingTimeState.h"
#include "HistoryState.h"

void StandbyState::setup() {
    this->ring->RainbowCycle(50, FORWARD);

};

void StandbyState::loop() {
    //do not check for touches directly
    if (this->getRunningTime() > 500 && this->forceSensors->wasTouched()) {
        this->changeState(new HistoryState());
    }

    if (this->clock->isSleepTime()) {
        this->changeState(new SleepingTimeState());
    }

};



