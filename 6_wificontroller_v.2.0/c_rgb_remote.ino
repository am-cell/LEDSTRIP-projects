
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
  }

  else if (data == "off" ) {
    Serial.println("     OFF");
    colorWipe(strip.Color(0, 0, 0), SPEED);          //  Turn Led strip OFF
    digitalWrite(StatusLed_PIN, LOW);                //  Turn Status Led OFF
  }

  else if (data == "white" ) {
    Serial.println("     ON");
    colorWipe(strip.Color(GREY), SPEED);              //  White
  }

  else if (data == "red" ) {
    Serial.println("     RED");
    colorWipe(strip.Color(RED), SPEED);              //  Red
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
    
    Serial.println("END");}
  
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
    CylonBounce  (RED, 4, 10, 50);
   
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
  }

 



}

//  End of My Remote   */
