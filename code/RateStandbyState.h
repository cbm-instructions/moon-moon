//
// Created by Adrian Endrich on 15.01.18.
//

#ifndef ARDUINO_RATESTANDBYSTATE_H
#define ARDUINO_RATESTANDBYSTATE_H

#include <Arduino.h>
#include "State.h"

class RateStandbyState : public State {

public:
    void setup();
    void loop();

};


#endif //ARDUINO_RATESTANDBYSTATE_H
