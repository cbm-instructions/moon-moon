#include "FiniteStateMachine.h"
#include <Arduino.h>

State::State() {
  this->startTime = millis();
};

void State::initFsm(FiniteStateMachine* fsm) {
  this->fsm = fsm;
}

void State::initMemory(Memory* memory) {
  this->memory = memory;
}

void State::initRing(NeoPatterns* ring) {
  this->ring = ring;
}

void State::initForceSensors(ForceSensors* forceSensors) {
  this->forceSensors = forceSensors;
}

void State::initClock(Clock* clock) {
  this->clock = clock;
}

long State::getRunningTime() {
  return (millis() - this->startTime);
}

void State::changeState(State* next) {
  this->fsm->changeState(next);  
}
        





