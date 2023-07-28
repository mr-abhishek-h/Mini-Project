#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPLWtlijl8g"
#define BLYNK_TEMPLATE_NAME "led"
#define BLYNK_AUTH_TOKEN "tuwEsd7z3TD95v-4Tpr6Xk7y4gh2K4s5"
SoftwareSerial mySerial(D8, D7); // RX pin: D8, TX pin: D7

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[ ] = "lansolo";
char pass[ ] = "sherlock";
void setup() {
  Serial.begin(115200); // Serial monitor baud rate
  mySerial.begin(115200); // SoftwareSerial baud rate
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

while (!Serial) {;
// wait for serial port to connect. Needed for native USB port only
}}

void loop() {Blynk.run();
  if (mySerial.available()) {
    // Read data from SoftwareSerial
//    String receivedChar = mySerial.readString();
    bool num = mySerial.read();
    // Print the received data
    Serial.print("Received data: ");
    Serial.println(num);
    String s;
   if (num==0)
   {s="Motion Detected!!";}
   else {s="No Motion Detected";}
  Blynk.virtualWrite(V4,s);
  
Blynk.virtualWrite(V5,num);
delay(1000);
  }
}
