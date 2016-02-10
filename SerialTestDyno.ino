/*
  
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
    
    Serial.println("tt");
    delay(10);
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
    delay(10);
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
  
*/



