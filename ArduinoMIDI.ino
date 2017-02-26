
#include "MIDI.h"
#include "Rotary.h"

// Encoder 1 is connected to pins 12 and 13
Rotary e1 = Rotary(12, 13);

// Encoder 2 is connected to pins 10 and 11
Rotary e2 = Rotary(10, 11);

int v1 = 0;
int v2 = 0;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Start midi with channel 1
  MIDI.begin(1);
}

void loop() {
  int encoderResult = e1.process();
  if (encoderResult) {
    v1 += encoderResult == DIR_CW ? 1 : -1;
    // Send control change event with control 16
    MIDI.sendControlChange(1, v1, 16);
  }

  encoderResult = e2.process();
  if (encoderResult) {
    v2 += encoderResult == DIR_CW ? 1 : -1;
    // Send control change event with control 15
    MIDI.sendControlChange(1, v2, 15);
  }
}

