#ifndef MEMORY_H
#define MEMORY_H

#include "DayInfo.h"

class Memory {

    private:

      int writePos = 0;
      int readPos = 59;

      DayInfo* currentDayInfo;


    public:
    DayInfo* dayInfo;
        Memory();
    long sleepStartedAt;
       DayInfo* writeLast60DayInfo(DayInfo *res);
       void setCurrentMood(bool mood);
       void setCurrentOnTime(bool onTime);
       void persistCurrentDayInfo();

    void setSleptEnough(bool sleptEnough);
};

#endif
