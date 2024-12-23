
#include <MyRGBcolors.h>            //  My RGB color library for WS2812b strip
//#include <MyGRBcolors.h>          //  My GRB color library for WS2811 strip
#include <Adafruit_NeoPixel.h>      //  Library for WS2811/WS2812b Led strips
#include "IRremote.h"               //  Library for IR Remote
#define  Turquoise        70, 200, 170     //  turquoise
#define  D_BLUE        0, 50, 200     //  turquoise
#define GOLD            255, 147, 31
#define IR_Receiver           11    //  Pin 1 of IR receiver to Arduino digital Pin 11
#define LED_PIN               4    //  Data Pin of Led strip
#define LED_COUNT             15    //  Number of LEDs in your strip
#define StatusLed_PIN         13    //  [OPTIONAL] Pin of the status Led
#define SPEED                 70    //  Speed of each Color Transition (in ms)
#define NOW                    0    //  Transition happen instantly
#define RAINBOW_SPEED         8    //  Rainbow Transition speed
#define RAINBOW_REPEAT        10    //  How many times the Rainbow Cycle is repeated
#define BRIGHTNESS            40    //  Initial Brightness
#define BRIGHTNESS_INCREMENT  5    //  Increase/Decrease Brightness by this value
#define MIN_BRIGHTNESS         2    //  Minimum Brightness
#define MAX_BRIGHTNESS       255    //  Maximum Brightness
CRGBArray<LED_COUNT> leds;
uint8_t hue[LED_COUNT];
int currentBrightness;              //  This will save the current Brightness
int buttonPushCounterA    =    0;   //  Counts how many times the button has been pushed
int buttonStateA          =    0;   //  Current state of the button
int lastButtonStateA      =    0;   //  Previous state of the button

//  Initialize Led Strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//  Initialize IR Receiver
IRrecv irrecv(IR_Receiver);         //  create instance of 'irrecv'
decode_results results;             //  create instance of 'decode_results'
