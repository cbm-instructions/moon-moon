#include <Arduino.h>
#include "State.h"
#include "AnimationCompletedHandler.h"

#ifndef TTMEIN_H
#define TTMEIN_H

class TimeInState : public State, public AnimationCompletedHandler  {
  
    public:
        void setup();
        void loop();
        void onAnimationCompleted();
            
};

#endif
