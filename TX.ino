#include <SoftwareSerial.h>
SoftwareSerial GSerial(11,12); 
void setup() 
{
  delay(1000);
  Serial.begin(9600);
  Serial.println("Lifi PC-PC Tx");
  GSerial.begin(400);
}

void loop() 
{
  if (Serial.available()) 
  {
    // read the next key
    char c = Serial.read();
    GSerial.print(c);
  }
}

