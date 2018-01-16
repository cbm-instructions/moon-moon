#include <Arduino.h>
#include "TimeInState.h"
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "StandbyState.h"
#include "SleepState.h"
#include "SleepingTimeState.h"

void TimeInState::onAnimationCompleted() {
    this->changeState(new SleepState());
};

void TimeInState::setup() {
    this->ring->ActivePattern = NONE;
    this->ring->ColorSet(this->ring->Color(25, 25, 25));
    this->ring->ColorWipe(this->ring->Color(0, 255, 0), 3000 / 60, FORWARD, this);
};

void TimeInState::loop() {
    if (!this->forceSensors->wasTouched()) {
        this->changeState(new SleepingTimeState());
    }
};
