#include "FiniteStateMachine.h"
#include "State.h"
#include "ForceSensors.h"
#include "Clock.h"
#include "Memory.h"

FiniteStateMachine::FiniteStateMachine(State * initial, NeoPatterns* ring, ForceSensors* forceSensors, Clock* clock, Memory* memory) {
    this->ring = ring;
    this->memory = memory;
    this->clock = clock;
    this->forceSensors = forceSensors;
    this->current_state = initial;
    this->current_state->initFsm(this);
    this->current_state->initRing(ring);
    this->current_state->initMemory(memory);
    ring->setBrightness(50);
    this->current_state->initForceSensors(forceSensors);
};

void FiniteStateMachine::setup() {
    this->current_state->setup();
};

void FiniteStateMachine::loop() {
    this->current_state->loop();
};

void FiniteStateMachine::changeState(State * next) {

    delete this->current_state; // delete old state in runtime since we get memory leaks else
    this->current_state = NULL;
    this->current_state = next; 
    this->current_state->initFsm(this);
    this->current_state->initRing(ring);
    this->current_state->initMemory(memory);
    ring->setBrightness(50);
    this->current_state->initForceSensors(forceSensors);
    this->current_state->setup();
};





