#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include "FiniteStateMachine.h"
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "Clock.h"
#include "Memory.h"

class FiniteStateMachine;
class NeoPatterns;
class ForceSensors;
class Clock;
class Memory;

class State {

    private:
      FiniteStateMachine* fsm;

    protected:
      NeoPatterns* ring;
      ForceSensors* forceSensors;
      Clock* clock;
      Memory* memory;
      long startTime;
     
    public:

        State();

        void initFsm(FiniteStateMachine* fsm);
        void initRing(NeoPatterns* ring);
        void initForceSensors(ForceSensors* forceSensors);
        void initClock(Clock* clock);
        void initMemory(Memory* memory);

        void changeState(State* next);

        long getRunningTime();
        
        virtual void setup() = 0;

        virtual void loop() = 0;
        
};

#endif



