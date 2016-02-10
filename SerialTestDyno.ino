/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and
  clears it.

  A good test for this is to try it with a GPS receiver
  that sends out NMEA 0183 sentences.

  Created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/SerialEvent

*/

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  inputString = "";

  // send "tt" and wait for a reply of "tt"

  while (inputString != "tt")
  {
    inputString = "";
    delay(10);
    Serial.println("tt");
    while (Serial.available())
    {
      char x = Serial.read();
      //Serial.println(x);
      inputString += x;
    }
  }
  //Serial.println("Input Setup");
  
  // Read and print setup
  
  //delay(1000);
  inputString = "";
  while (inputString != "ss")
  {
    inputString = "";
    while (Serial.available())
    {
      char x = Serial.read();
      inputString += x;
      //Serial.println(inputString);
    }
    //Serial.print("Complete setup line ");
    Serial.println(inputString);
    //delay(1000);
  }

}


void loop() 
{
for(int x=600; x < 7201; x=x+100)
{
  Serial.println(x);
  delay(10);  
}

for(int x=7200; x > 601 ; x=x-50)
{
  Serial.println(x);
  delay(20);
  
}



}

/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
*/



