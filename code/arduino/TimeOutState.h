#include <Arduino.h>
#include "State.h"

#ifndef TTMEOUT_H
#define TTMEOUT_H

class TimeOutState : public State, public AnimationCompletedHandler  {

public:
    void setup();
    void loop();
    void onAnimationCompleted();

};

#endif
