#include <SoftwareSerial.h>
SoftwareSerial espSerial(A2, A3);
String str;
void setup(){
Serial.begin(115200);
espSerial.begin(115200);
pinMode(A6,INPUT);

delay(2000);
}
void loop()
{
bool dat=digitalRead(A6);
espSerial.write(dat);

delay(1500);
}
