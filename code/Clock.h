#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>

class Clock {

    private:
      long sleepTime;
      long wakeTime;
      long hoursInDay;
      long minutesInHour;
      long secondsInMinute;
      long millisInSecond;
  
    public:
        Clock();
        void setHoursInDay(long time);
        void setMinutesInHour(long time);
        void setSecondsInMinute(long time);
        void setMillisInSecond(long time);
        void setSleepTime(long time);
        long getSleepTime();
        long getTimeRunning();
        long getSecondsRunning();
        long getMinutesRunning();
        long getHoursRunning();
        long getDaysRunning();
        long getMilliOfSecond();
        long getSecondOfMinute();
        long getMinuteOfHour();
        long getHourOfDay();
        bool isSleepTime();

    long getOptimalSleepLength();
};

#endif