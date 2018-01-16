#ifndef STANDBY_STATE_H
#define STANDBY_STATE_H

#include <Arduino.h>
#include "State.h"

class StandbyState : public State {
  
    public:
        void setup();
        void loop();
            
};

#endif



