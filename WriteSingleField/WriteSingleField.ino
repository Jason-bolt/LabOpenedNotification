#include <WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

char ssid[] = "iotdevlab+virus";   // your network SSID (name) 
char pass[] = "m,./@1234";   // your network password
WiFiClient  client;
long trig=26; // 8; Blue
long echo=18; // 9; Violet
long Zeit;
long distance;
// VCC = green
// Gnd = White

unsigned long myChannelNumber = 1638914;
const char * myWriteAPIKey = "SNVNKCNLQE2ZI6TI";


void setup() {
  Serial.begin(115200);  //Initialize serial
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

//  ######################## GET DISTANCE READINGS #######################
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  Zeit = pulseIn(echo,HIGH);
  distance=Zeit*0.017;
  
  Serial.print("Entfernung in cm:   ");
  Serial.println(distance);
  
//  #################################################


  int x = ThingSpeak.writeField(myChannelNumber, 1, distance, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }


  delay(20000);
  
}
