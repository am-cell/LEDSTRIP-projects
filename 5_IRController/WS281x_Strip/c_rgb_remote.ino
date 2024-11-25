
void RGB_Remote()  {                           //  Functions for IR Remote

  int currentButtonStateA = digitalRead(IR_Receiver);
      lastButtonStateA = currentButtonStateA;
    digitalWrite(StatusLed_PIN, LOW);          //  Blink the Status LED when an input is received
    delay(70);
    digitalWrite(StatusLed_PIN, HIGH);


  switch(results.value)  {                           //  IR Remote buttons

  case 0xE0E0E01F:
    Serial.println("     BRIGHTNESS UP");            //  Increase Brightness
    currentBrightness += BRIGHTNESS_INCREMENT;
    if (currentBrightness > MAX_BRIGHTNESS)
    {   currentBrightness = MAX_BRIGHTNESS;  }
    lastButtonStateA = currentButtonStateA;
    strip.setBrightness(currentBrightness);          //  Set current Brightness
    Serial.print("Current Brightness: ");
    Serial.println(currentBrightness);               //  Print current Brightness
    strip.show();
    break;

  case 0xE0E0D02F:
    Serial.println("     BRIGHTNESS DOWN");          //  Decrease Brightness
    currentBrightness -= BRIGHTNESS_INCREMENT;
    if (currentBrightness < MIN_BRIGHTNESS)
    {  currentBrightness = MIN_BRIGHTNESS;  }
    lastButtonStateA = currentButtonStateA;
    strip.setBrightness(currentBrightness);          //  Set current Brightness
    Serial.print("Current Brightness: ");
    Serial.println(currentBrightness);               //  Print current Brightness
    strip.show();
    break;

  case 0xE0E040BF:
    Serial.println("     OFF");
    colorWipe(strip.Color(0, 0, 0), SPEED);          //  Turn Led strip OFF
    digitalWrite(StatusLed_PIN, LOW);                //  Turn Status Led OFF
    break;

  case 0xE0E01DE2:
    Serial.println("     ON");
    colorWipe(strip.Color(GREY), NOW);              //  White
    break;

  case 0xE0E020DF:
    Serial.println("     RED");
    colorWipe(strip.Color(RED), SPEED);              //  Red
    break;

  case 0xE0E0A05F:
    Serial.println("     GREEN");
    colorWipe(strip.Color(GREEN), SPEED);            //  Green
    break;

  case 0xE0E0609F:
    Serial.println("     SKY BLUE");
    colorWipe(strip.Color(SKY_BLUE), SPEED);             //  Blue
    break;

  case 0xE0E010EF:
    Serial.println("     TURQUOISE");
    colorWipe(strip.Color(Turquoise), SPEED);            //  White
    break;

  case 0xE0E0906F:
    Serial.println("     GOLDEN LIGHT");
    colorWipe(strip.Color(GOLD), SPEED);           //  Orange
    break;

  case 0xFF58A7:
    Serial.println("     MINT");
    colorWipe(strip.Color(MINT), SPEED);             //  Mint
    break;

  case 0xE0E030CF:
    Serial.println("     DARK BLUE");
    colorWipe(strip.Color(D_BLUE), SPEED);        //  Dark Blue
    break;

  case 0xE0E0FC03:
  
    Serial.println("     * random sparkle *");
     for(int j = 0; j < 100 ; j++){
    int dot = random(0,23); 
    int hue = random(0,256);
    leds[dot] = CHSV(hue,255,175);
    FastLED.show();
    delay(50);
    leds[dot] = CRGB::Black;
  }Serial.println("     END");
    break;

  case 0xE0E08877:
    Serial.println("     PINK");
    colorWipe(strip.Color(PINK), SPEED);            //  Brown
    break;

  case 0xE0E0B04F:
    Serial.println("     TOPAZ");
    colorWipe(strip.Color(TOPAZ), SPEED);             //  Aqua
    break;

  case 0xE0E0708F:
    Serial.println("     PURPLE");
    colorWipe(strip.Color(PURPLE), SPEED);           //  Purple
    break;

  case 0xE0E0A45B:
    Serial.println("     * rainbow *");
    rainbowCycle(RAINBOW_SPEED); 
    Serial.println("     END");
    break;

  case 0xFF50AF:
    Serial.println("     BEIGE");
    colorWipe(strip.Color(BEIGE), SPEED);            //  Beige
    break;

  case 0xFF7887:
    Serial.println("     TOPAZ");
    colorWipe(strip.Color(TOPAZ), SPEED);            //  Topaz
    break;

  case 0xFF708F:
    Serial.println("     FUCHSIA");
    colorWipe(strip.Color(FUCHSIA), SPEED);          //  Fuchsia
    break;

  case 0xE0E0F906:
    Serial.println("     * CylonBounce   *");
    CylonBounce  (RED, 4, 10, 50);                     //  Rainbow colors
    Serial.println("     END");
    break;

  case 0xE0E050AF:
    Serial.println("     YELLOW");
    colorWipe(strip.Color(YELLOW), SPEED);           //  Yellow
    break;

  

  case 0xE0E06897:
    Serial.println("     * FLASHING RAINBOW COLORS *");
    theaterChaseRainbow(SPEED);                      //   Theatre chase random colors
    Serial.println("     END");
    break;

  case 0xFFFFFFFF:                                   //   Ignore this value
  Serial.println(" ");
    break;

  
     
  }
    
} //  End of My Remote   */
