#include <Arduino.h>
#include "TimeOutState.h"
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "StandbyState.h"
#include "SleepState.h"
#include "RateState.h"


void TimeOutState::onAnimationCompleted() {
    this->changeState(new RateState());
};

void TimeOutState::setup() {
    this->ring->ActivePattern = NONE;
    this->ring->ColorSet(this->ring->Color(0,255,0));
    this->ring->ColorWipe(this->ring->Color(25,25,25), 37, FORWARD, this);
};

void TimeOutState::loop() {
  //do not check for touches directly 
  
  if(this->forceSensors->wasTouched()){
    this->changeState(new SleepState());
  }
};
