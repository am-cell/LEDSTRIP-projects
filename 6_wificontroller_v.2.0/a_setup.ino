
void setup() {

  Serial.begin(9600);                         //  Start Serial Monitor, Baud 9600
  Serial.println("Starting Serial Monitor");  //  Print Message
  server.begin();
  connectWiFi();
  strip.setBrightness(BRIGHTNESS);            //  Set Initial Brightness

  strip.begin();                              //  Initialize the strip
  strip.show();                               //  Update the strip

  digitalWrite(StatusLed_PIN, HIGH);          //  Turn on Green LED when the program is ready
  
  }
