#include <Arduino.h>
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "HistoryState.h"
#include "StandbyState.h"
#include "Memory.h"
#include "DayInfo.h"
#include "SleepingTimeState.h"

void HistoryState::setup() {

    DayInfo history[60];

    for (int i = 0; i < 60; i = i + 1) {
        history[i].empty = true;
        history[i].onTime = false;
        history[i].mood = false;
        history[i].sleptEnough = false;
    }


    this->memory->writeLast60DayInfo(history);

    this->ring->History(history);

};

void HistoryState::loop() {


    if (this->getRunningTime() > 5000) {
        this->changeState(new StandbyState());
    }

    if (this->clock->isSleepTime()) {
        this->changeState(new SleepingTimeState());
    }

};



