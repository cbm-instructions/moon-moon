#define NEOPIXEL_PIN 6
#define FS_A_PIN A0
#define FS_B_PIN A1
#define FS_C_PIN A2

#include "FiniteStateMachine.h"
#include "StandbyState.h"
#include "HistoryState.h"
#include "RateState.h"
#include "NeoPatterns.h"
#include "ForceSensors.h"
#include "Memory.h"

FiniteStateMachine* fsm;
NeoPatterns* ring;
ForceSensors* forceSensors;
Clock* clock;
Memory* memory;

void setup() {
  Serial.begin(9600);

  forceSensors = new ForceSensors(FS_A_PIN, FS_B_PIN, FS_C_PIN);
  forceSensors->setup();
  
  ring = new NeoPatterns(60, NEOPIXEL_PIN, NEO_RGBW + NEO_KHZ800);
  ring->begin();
  ring->RainbowCycle(3, FORWARD);
  ring->Update();

  clock = new Clock();
  memory = new Memory();

  fsm = new FiniteStateMachine(new StandbyState(), ring, forceSensors, clock, memory);
  fsm->setup();
  
}

void loop() {
  forceSensors->loop();
  ring->Update();
  fsm->loop();
  //Serial.println(freeRam());
}

int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}



