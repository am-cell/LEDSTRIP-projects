
void loop() {

  if (irrecv.decode(&results)) {                // Check if an IR signal is received

    Serial.println(results.value, HEX);           // Display buttons RAW values in Serial monitor

    RGB_Remote(); // Functions of remote in the next tab
    delay(100);                                       //  short delay
    irrecv.resume();                                 //  Ready to receive the next input

  } 
}                                               //  End of void loop
