#include <Arduino.h>
#include "State.h"
#include "NeoPatterns.h"
#include "AnimationCompletedHandler.h"

#ifndef SLEEP_STATE_H
#define SLEEP_STATE_H


class SleepState : public State, public AnimationCompletedHandler {
    private:
        boolean fadingOut = false;
    public:
        void setup();
        void loop();
        void onAnimationCompleted();
            
};

#endif


