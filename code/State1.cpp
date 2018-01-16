#include <Arduino.h>
#include "State1.h"
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "StandbyState.h"

void State1::setup() {
    this->ring->Scanner(this->ring->Color(0,255,0), 55);
};

void State1::loop() {
  if(this->getRunningTime() > 10000){
    this->changeState(new StandbyState());
  }
};



