String inputString = "A";         // a string to hold incoming data
String revs;
String setupLine;
boolean found ;
int rev = 7200;
int x;
int increase;

void setup() {
  pinMode(13, OUTPUT);
  // initialize serial:
  Serial.begin(115200);
  inputString = "";
  increase = 1;
  //wait for "ff" and send a reply of "ff"
  while (found == false)
  {
    getFf();
  }
  Serial.flush();
  Serial.println(inputString);
  delay(100);
}

void loop()
{
  GetRevs();
//  Serial.println("Help");
  found = false;
  while (found == false)
  {
    GetStop();
//    Serial.println("Help2");
    if (increase == 1)
    {
      x = x + 111;
      Serial.println(x);
      delay(10);
      if (x >= rev)
      {
        increase = 0;
      }
    }
    if (increase == 0)
    {
      x = x - 100;
      Serial.println(x);
      delay(10);
      if (x <= 51)
      {
        increase = 1;
      }
    }
  }  
}

//Functions//
void readLine()
{
  if (Serial.available())
  {
    setupLine = Serial.readString();
    if (setupLine.length() > 0)
    {
      found = true;
    }
  }

  else
  {
    found = false;
  }
}
void getFf()
{
  if (Serial.available() > 0 )
  {
    inputString = Serial.readString();
    if (inputString = "ff")
    {
      
      //inputString = "";
      found = true;
    }
  }
  else
  {
    found = false;
  }
}

void GetRevs()
{
  inputString = "";
  found = false;
  while (found == false)
  {
    readLine();
  }
  revs = setupLine;
  rev = revs.toInt();
  Serial.flush();
  Serial.println(rev);
  // delay(3000);
}

void GetStop()
{
  if (Serial.available() > 0 )
  {
    inputString = Serial.readString();
    if (inputString = "aa")
    {
      found = true;
      Serial.flush();
    }
  }
  else
  {
    found = false;
  }
}

