
#include <MyRGBcolors.h>            //  My RGB color library for WS2812b strip
//#include <MyGRBcolors.h>          //  My GRB color library for WS2811 strip
#include <Adafruit_NeoPixel.h>      //  Library for WS2811/WS2812b Led strips
#include <ESP8266WiFi.h>
#define  Turquoise        30, 241, 191     //  turquoise
#define  D_BLUE        0, 50, 200     //  turquoise
#define GOLD            255, 147, 31
#define GRAY            147, 149, 152

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

int currentBrightness;              //  This will save the current Brightness
int buttonPushCounterA    =    0;   //  Counts how many times the button has been pushed
int buttonStateA          =    0;   //  Current state of the button
int lastButtonStateA      =    0;   //  Previous state of the button
/* define port */
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "Irfan";
const char* password = "asim1234";

/* data received from application */
String  data = "";
//  Initialize Led Strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}
