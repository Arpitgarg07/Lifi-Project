#include <SoftwareSerial.h>
SoftwareSerial GSerial(11, 12);

char charset[2][25] = {{ '?', '^', '', ']', '6', '\\', '', '_', '7', 'J', '', 'I', '$', 'H', '', 'O', '#', 'N', '', 'E', '"', 'D', '', 'G', '!'},
  { 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
};

void setup()
{
  delay(1000);
  Serial.begin(9600);
  Serial.println("Lifi PC-PC Rx");
  GSerial.begin(400);
}

void loop()
{
  if (GSerial.available())
  {
    // read the next key
    char c = GSerial.read();
   
    //Serial.print(c);
    if(c==char(0xDF)) Serial.print('a');
    for(int i=0;i<25;i++){
      if(charset[0][i]==c){
        Serial.print(charset[1][i]);
      }
    }
    
  }
}
