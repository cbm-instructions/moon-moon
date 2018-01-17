#ifndef FSM_H
#define FSM_H

#include "State.h"
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "Clock.h"
#include "Memory.h"

class NeoPatterns;
class ForceSensors;
class Clock;
class Memory;
class State;

class FiniteStateMachine {
  
    private:
    
        State * current_state;
        NeoPatterns* ring;
        ForceSensors* forceSensors;
        Clock* clock;
        Memory* memory;

    public:
    
        FiniteStateMachine(State * initial, NeoPatterns* ring, ForceSensors* forceSensors, Clock* clock, Memory* memory);

        void setup();

        void loop();
        
        void changeState(State * next);
        
};

#endif




