#include "Memory.h"
#include "DayInfo.h"
#include <Arduino.h>



Memory::Memory() {

    this->dayInfo = (DayInfo *) malloc(60 * sizeof(DayInfo));
    this->currentDayInfo = (DayInfo *) malloc(sizeof(DayInfo));

    for( int i = 0; i < 60; i = i + 1) {
        this->dayInfo[i].empty = true;
        this->dayInfo[i].mood = false;
        this->dayInfo[i].onTime = true;
        this->dayInfo[i].sleptEnough =false;
    }

}

DayInfo* Memory::writeLast60DayInfo(DayInfo *res){

   for( int i = 59; i >=0; i = i - 1) {
       res[i].mood = this->dayInfo[(this->writePos + i) % 60].mood;
       res[i].onTime = this->dayInfo[(this->writePos + i) % 60].onTime;
       res[i].empty = this->dayInfo[(this->writePos + i) % 60].empty;
       res[i].sleptEnough = this->dayInfo[(this->writePos + i) % 60].sleptEnough;
   }

    return res;
}

void Memory::setCurrentMood(bool mood) {
    this->currentDayInfo->mood = mood;
}

void Memory::setSleptEnough(bool sleptEnough) {
    this->currentDayInfo->sleptEnough = sleptEnough;
}

void Memory::setCurrentOnTime(bool onTime) {
    this->currentDayInfo->onTime = onTime;
}

void Memory::persistCurrentDayInfo() {
    this->dayInfo[this->writePos % 60].empty = false;
    this->dayInfo[this->writePos % 60].mood = this->currentDayInfo->mood;
    this->dayInfo[this->writePos % 60].onTime = this->currentDayInfo->onTime;
    this->dayInfo[this->writePos % 60].sleptEnough = this->currentDayInfo->sleptEnough;
    this->writePos = this->writePos + 1;
    this->currentDayInfo->onTime = true;
}


