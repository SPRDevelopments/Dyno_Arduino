String inputString = "A";         // a string to hold incoming data
String revs;
String setupLine;
boolean found ;
int rev = 7200;
void setup() {
  pinMode(13, OUTPUT);
  // initialize serial:
  Serial.begin(115200);
  inputString = "";

  //wait for "ff" and send a reply of "ff"
  while (found == false)
  {
    getFf();
  }
  
  inputString = "";
  found = false;
  while (found == false)
  {
    readLine();
  }
  Serial.print("Revs are ");
  Serial.println(setupLine);
  revs = setupLine;
  rev = revs.toInt();
  Serial.print("Rev is ");
  Serial.println(rev);
}
void loop()
{
  int x;
 
  for (x = 600; x < rev ; x = x + 200);
  {
    Serial.println( x);
    delay(10);
  }
  for ( x = rev; x >= 600 ; x = x - 100)
  {
    Serial.println(x);
    delay(20);
  }
}
//Functions
void readLine()
{
  String x;
  while (Serial.available())
  {
    x = Serial.readString();
    setupLine = setupLine + x;
  }
  if (setupLine.length() > 0)
  {
    found = true;
  }
  else
  {
    found = false;
  }
}
void getFf()
{

  char x;
  while (Serial.available() > 0 )
  {
    x = Serial.read();
    inputString = inputString + x;
  }

  if (inputString != "ff")
  {
    Serial.println(inputString);
    inputString = "";
    found = false;
  }
  else
  {

    Serial.println(inputString);
    //inputString = "";
    found = true;
  }

}

/*

*/



