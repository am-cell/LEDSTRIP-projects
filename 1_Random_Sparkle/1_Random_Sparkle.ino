#include "FastLED.h"

#define PIN 4
#define NUM_LEDS 15  //Number of LEDs in the strip

CRGBArray<NUM_LEDS> leds;
uint8_t hue[NUM_LEDS];

void setup(){
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
  for(int i = 0; i< NUM_LEDS; i++){
    hue[i] = 255/NUM_LEDS * i;
  }

 
}

void loop(){
   //Random RGB Sparkle Animation
  for(int j = 0; j < 100 ; j++){
    int dot = random(0,23); 
    int hue = random(0,256);
    leds[dot] = CHSV(hue,255,175);
    FastLED.show();
    delay(50);
    leds[dot] = CRGB::Black;
  }
}
