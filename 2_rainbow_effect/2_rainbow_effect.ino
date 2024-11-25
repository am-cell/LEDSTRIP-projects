#include "FastLED.h"

#define PIN 4
#define NUM_LEDS 15  //Number of LEDs in the strip

CRGBArray<NUM_LEDS> leds;
uint8_t hue[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    hue[i] = 255 / NUM_LEDS * i;
  }


}

void loop() {
  //Rainbow Effect
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue[i]++, 255, 175);
  }
  FastLED.show();
  delay(6);
}
