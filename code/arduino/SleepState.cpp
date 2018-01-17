#include <Arduino.h>
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "SleepState.h"
#include "TimeOutState.h"

void SleepState::onAnimationCompleted() {
    if (!this->fadingOut) {
        this->ring->ActivePattern = NONE;
        this->ring->ColorSet(this->ring->Color(0, 10, 0));
        this->ring->show();
    } else {
        this->changeState(new TimeOutState());
    }
};


void SleepState::setup() {
    this->fadingOut = false;
    this->ring->Fade(this->ring->Color(0, 255, 0), this->ring->Color(0, 10, 0), 255, 1, FORWARD, this);
    this->memory->sleepStartedAt = millis();
};

void SleepState::loop() {

    //do not check for touches directly
    if (this->getRunningTime() > 500 && !this->forceSensors->wasTouched() && !this->fadingOut) {
        this->fadingOut = true;
        this->ring->Fade(this->ring->Color(0, 10, 0), this->ring->Color(0, 255, 0), 255, 1, FORWARD, this);
    }

};
