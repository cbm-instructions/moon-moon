#ifndef FORCE_SENSORS_H
#define FORCE_SENSORS_H

#include <Arduino.h>

class ForceSensors {

    private:
      int sensorPinA;
      int sensorPinB; 
      int sensorPinC;
  
    public:
        ForceSensors(int sensorPinA, int sensorPinB, int sensorPinC);
        void setup();
        void loop();
        boolean isPhoneThere();
        long getPhoneIsThereTime();
        boolean wasTouched();

    int getDominantSensor();
};

#endif



