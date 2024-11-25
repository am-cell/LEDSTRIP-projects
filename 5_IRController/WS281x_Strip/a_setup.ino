
void setup() {

  Serial.begin(9600);                         //  Start Serial Monitor, Baud 9600
  Serial.println("Starting Serial Monitor");  //  Print Message
  irrecv.enableIRIn();                        //  Start the IR_Receiver

  strip.setBrightness(BRIGHTNESS);            //  Set Initial Brightness

  strip.begin();                              //  Initialize the strip
  strip.show();                               //  Update the strip

  digitalWrite(StatusLed_PIN, HIGH);          //  Turn on Green LED when the program is ready
FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LED_COUNT);
  for(int i = 0; i< LED_COUNT; i++){
    hue[i] = 255/LED_COUNT * i;
  }
}
