#include "Clock.h"
#include <Arduino.h>

/*
 * For demonstration purposes we assume that the real current time stamp in the user's world is the current running time
 * stamp of the arduino
 */

Clock::Clock() {
    this->hoursInDay = 24;
    this->minutesInHour = 60;
    this->secondsInMinute = 60;
    this->millisInSecond = 1000;
}

bool Clock::isSleepTime() {
    /*
     * TODO This is demo code it alarms us every 2 minutes

     */

    if(this->getMinuteOfHour() == 0) {
        return false;
    } else if (this->getMinuteOfHour() % 2 == 0) {
        return true;
    } else return false;

}

long Clock::getOptimalSleepLength() {
    return 10000;
}

void Clock::setHoursInDay(long time) {
  this->hoursInDay = time;
}

void Clock::setMinutesInHour(long time) {
  this->minutesInHour = time;
}


void Clock::setSecondsInMinute(long time) {
  this->secondsInMinute = time;
}


void Clock::setMillisInSecond(long time) {
  this->millisInSecond = time;
}

long Clock::getTimeRunning() {
  return millis();
}

long Clock::getSecondsRunning() {
  return this->getTimeRunning() / this->millisInSecond; //getTimeRunning is currentTime for demonstration
}

long Clock::getMinutesRunning() {
  return this->getSecondsRunning() / this->secondsInMinute;
}

long Clock::getHoursRunning() {
  return this->getMinutesRunning() / this->minutesInHour;
}

long Clock::getDaysRunning() {
  return this->getHoursRunning() / this->hoursInDay;
}

long Clock::getMilliOfSecond() {
  return millis() % 1000; //getTimeRunning is currentTime for demonstration
}

long Clock::getSecondOfMinute() {
  return (millis()/1000) % 60;
}

long Clock::getMinuteOfHour() {
  return (millis()/60000) % 60;
}

long Clock::getHourOfDay() {
    return (millis() / 60000) % 24;

}