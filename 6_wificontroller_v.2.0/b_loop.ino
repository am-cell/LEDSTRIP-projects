
void loop() {
  /* If the server available, run the "checkClient" function */
  client = server.available();
  if (!client) return;
  data = checkClient ();


  Serial.println(data);           // Display buttons RAW values in Serial monitor

  RGB_Remote ();               // Functions of remote in the next tab
  delay(100);                                       //  short delay


}
//  End of void loop
String checkClient (void)
{
  while (!client.available()) delay(1);
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length() - 9, 9);
  return request;
}
