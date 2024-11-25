//#include <MyRGBcolors.h>            //  My RGB color library for WS2812b strip
#include <MyGRBcolors.h>          //  My GRB color library for WS2811 strip
#include <Adafruit_NeoPixel.h>      //  Library for WS2811/WS2812b Led strips
long a;
#define  Turquoise        240, 30, 191     //  turquoise
#define  D_BLUE        50, 0, 200     //  turquoise
#define GOLD            147, 255, 31
#define GRAY            147, 147, 152
#define PEARL            224, 234, 200
#define TEAL            120, 0, 128
#define LED_PIN               12    //  Data Pin of Led strip
#define LED_COUNT            23//  Number of LEDs in your strip
#define StatusLed_PIN         2    //  [OPTIONAL] Pin of the status Led
#define SPEED                 65   //Speed of each Color Transition (in ms)
#define NOW                   2    //  Transition happen instantly
#define RAINBOW_SPEED         10  //  Rainbow Transition speed
#define RAINBOW_REPEAT        1    //  How many times the Rainbow Cycle is repeated
#define BRIGHTNESS            30  //  Initial Brightness
#define BRIGHTNESS_INCREMENT   5   //  Increase/Decrease Brightness by this value
#define MIN_BRIGHTNESS         2    //  Minimum Brightness
#define MAX_BRIGHTNESS       255   //  Maximum Brightness

int currentBrightness     =    30;              //  This will save the current Brightness
int buttonPushCounterA    =    0;   //  Counts how many times the button has been pushed
int buttonStateA          =    0;   //  Current state of the button
int lastButtonStateA      =    0;
int ip = A0;

int val = 0;
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
String data;             //String to store app data state.
// 400 - 1023.


const char* ssid = "Irfan";
const char* password = "asim1234";
ESP8266WebServer server(80);

void setup() {


  Serial.begin(9600);
  strip.setBrightness(BRIGHTNESS);            //  Set Initial Brightness

  strip.begin();                              //  Initialize the strip
  strip.show();                               //  Update the strip

  digitalWrite(StatusLed_PIN, HIGH);
  pinMode (ip, INPUT);
  // Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Starting WEB-server
  server.on ( "/", HTTP_handleRoot );
  server.onNotFound ( HTTP_handleRoot );
  server.begin();
  colorWipe(strip.Color(GREEN), SPEED);

}

void RGB_Remote()  {                           //  Functions for IR Remote





  if (data == "vup") {
    Serial.println("     BRIGHTNESS UP");            //  Increase Brightness
    currentBrightness += BRIGHTNESS_INCREMENT;
    if (currentBrightness > MAX_BRIGHTNESS)
    {
      currentBrightness = MAX_BRIGHTNESS;
    }

    strip.setBrightness(currentBrightness);          //  Set current Brightness
    Serial.print("Current Brightness: ");
    Serial.println(currentBrightness);               //  Print current Brightness
    strip.show();
    delay(1000);
  }

  else if (data == "vdown" ) {
    Serial.println("     BRIGHTNESS DOWN");          //  Decrease Brightness
    currentBrightness -= BRIGHTNESS_INCREMENT;
    if (currentBrightness < MIN_BRIGHTNESS)
    {
      currentBrightness = MIN_BRIGHTNESS;
    }

    strip.setBrightness(currentBrightness);          //  Set current Brightness
    Serial.print("Current Brightness: ");
    Serial.println(currentBrightness);               //  Print current Brightness
    strip.show();
    delay(1000);
  }

  else if (data == "off" ) {
    Serial.println("     OFF");
    colorWipe(strip.Color(OFF), SPEED);              //  BLACK
  }
  else if (data == "auto" ) {
    Serial.println("     AUTO");
    val = 0 ;
    val = analogRead(ip);

    Serial.println(val);

    if (val > 100)

    {

      colorWipe(strip.Color(SKY_BLUE), SPEED);
      delay(2000);
    }

    else

    {

      colorWipe(strip.Color(OFF), NOW);

    }


  }


  else if (data == "white" ) {
    Serial.println("     ON");
    colorWipe(strip.Color(GREY), SPEED);              //  White
  }

  else if (data == "red") {
    Serial.println("     RED");
    colorWipe(strip.Color(RED), SPEED);              //  Red
  }
  else if (data == "orange" ) {
    Serial.println("     ORANGE");
    colorWipe(strip.Color(ORANGE), SPEED);              //  Red

  }
  else if (data == "pearl" ) {
    Serial.println("     PEARL");
    colorWipe(strip.Color(PEARL), SPEED);              //  Red
  }
  else if (data == "beige" ) {
    Serial.println("     BEIGE");
    colorWipe(strip.Color(BEIGE), SPEED);              //  Red
  }
  else if (data == "teal" ) {
    Serial.println("     TEAL");
    colorWipe(strip.Color(TEAL), SPEED);              //  Red
  }


  else if (data == "green") {
    Serial.println("     GREEN");
    colorWipe(strip.Color(GREEN), SPEED);            //  Green
  }

  else if (data == "skyblue" ) {
    Serial.println("     SKY BLUE");
    colorWipe(strip.Color(SKY_BLUE), SPEED);             //  Blue
  }

  else if (data == "tuquoise" ) {
    Serial.println("     TURQUOISE");
    colorWipe(strip.Color(Turquoise), SPEED);            //  White
  }

  else if (data == "gold" ) {
    Serial.println("     GOLDEN LIGHT");
    colorWipe(strip.Color(GOLD), SPEED);           //  Orange
  }

  else if (data == "grey" ) {
    Serial.println("     GREY");
    colorWipe(strip.Color(GRAY), SPEED);             //  Mint
  }

  else if (data == "darkblue" ) {
    Serial.println("     DARK BLUE");
    colorWipe(strip.Color(D_BLUE), SPEED);        //  Dark Blue
  }

  else if (data == "mode1" ) {

    Serial.println("     * candle effect *");

    candle();

    Serial.println("END");
  }

  else if (data == "pink" ) {
    Serial.println("     PINK");
    colorWipe(strip.Color(PINK), SPEED);            //  Brown
  }

  else if (data == "topaz" ) {
    Serial.println("     TOPAZ");
    colorWipe(strip.Color(TOPAZ), SPEED);             //  Aqua
  }

  else if (data == "purple" ) {
    Serial.println("     PURPLE");
    colorWipe(strip.Color(PURPLE), SPEED);           //  Purple
  }

  else if (data == "mode2" ) {
    Serial.println("     * rainbow *");
    rainbowCycle(RAINBOW_SPEED);
    Serial.println("     END");
  }

  else if (data == "error ") {
    Serial.println("     BEIGE");
    colorWipe(strip.Color(BEIGE), SPEED);            //  Beige
  }

  else if (data == "nothing" ) {
    Serial.println("     TOPAZ");
    colorWipe(strip.Color(TOPAZ), SPEED);            //  Topaz
  }

  else if (data == "more" ) {
    Serial.println("     FUCHSIA");
    colorWipe(strip.Color(FUCHSIA), SPEED);          //  Fuchsia
  }

  else if (data == "mode3" ) {
    Serial.println("     * CylonBounce   *");
    CylonBounce  (GREEN, 4, 10, 50);

    Serial.println("     END");
  }

  else if (data == "yellow" ) {
    Serial.println("     YELLOW");
    colorWipe(strip.Color(YELLOW), SPEED);           //  Yellow
  }



  else if (data == "mode4" ) {
    Serial.println("     * FLASHING RAINBOW COLORS *");
    theaterChaseRainbow(SPEED);                      //   Theatre chase random colors
    Serial.println("     END");
    delay(1000);
  }
  else if (data == "mode5" ) {

    Serial.println("     * bounce *");

    CylonBounce          (RED, 4, 10, 50);

    Serial.println("END");
  }
  else if (data == "mode6" ) {

    Serial.println("     * sparkle *");

    Sparkle              (random(255), random(255), random(255), 0);
    Sparkle              (random(255), random(255), random(255), 0);
    Sparkle              (random(255), random(255), random(255), 0);
    colorWipe(strip.Color(OFF), 0);
    Serial.println("END");
  }
  else if (data == "mode7" ) {

    Serial.println("     * running lights *");

    RunningLights        (GOLD, SPEED);

    Serial.println("END");
  }
  else if (data == "mode8" ) {

    Serial.println("     * Strobe  *");

    Strobe               (WHITE, 10, 50, 1000);

    Serial.println("END");
  }
  else if (data == "mode9" ) {

    Serial.println("     *  SnowSparkle *");

    SnowSparkle          (GREY, 20, random(100, 100)); //  Random time

    Serial.println("END");
  }
  else if (data == "mode10" ) {

    Serial.println("     * twinkle*");

    TwinkleRandom        (20, 50, false);

    Serial.println("END");
  }
  else if (data == "mode11" ) {

    Serial.println("     * bouncingballs*");
    byte colors[3][3] = { {0xff, 0, 0},
      {0xff, 0xff, 0xff},
      {0   , 0   , 0xff}
    };

    BouncingColoredBalls(3, colors);

    Serial.println("END");
  }
  else if (data == "mode12" ) {

    Serial.println("     * fade*");

    RGBLoop();
    Serial.println("END");
  }
  else if (data == "mode13" ) {

    Serial.println("     * meteor*");

    meteorRain(0xff, 0xff, 0xff, 10, 64, true, 30);
    Serial.println("END");
  }
  else if (data == "mode14" ) {

    Serial.println("     * fire*");

    Fire(120, 55, 15);
    Serial.println("END");

  }
  else if (data == "mode15" ) {

    Serial.println("     * orange flame*");

    orangeflame();

    Serial.println("END");

  }
  else if (data == "mode16" ) {

    Serial.println("     * purple flame*");

    purpleflame();

    Serial.println("END");

  }
  else if (data == "mode17" ) {

    Serial.println("     * green flame*");

    greenflame();

    Serial.println("END");

  }
}



void loop() {
  server.handleClient();

  data = server.arg("State");
  RGB_Remote ();

}

void HTTP_handleRoot(void) {

  if ( server.hasArg("State") ) {
    Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(2);
}
