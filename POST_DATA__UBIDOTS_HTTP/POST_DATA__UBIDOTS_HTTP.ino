#include "Ubidots.h"
 
const char* UBIDOTS_TOKEN = "BBFF-UGk6AUiIwiS4FAVBlsGZkoLrzVOfUO";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "www.interactiverobotics.club";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "cilibur2019";      // Put here your Wi-Fi password 

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

void setup() {                       

  Serial.begin(9600);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  ubidots.get("2cf43277897a", "kelembaban");
  // ubidots.setDebug(true);  // Uncomment this line for printing debug  messages                     
}

void loop() {
  float suhu = random(0, 9) * 10;
  float kelembaban = random(0, 9) * 100;
  ubidots.add("suhu", suhu);// Change for your variable name  
  ubidots.add("kelembaban", kelembaban);
  
  bool bufferSent = false;
  bufferSent = ubidots.send(); // Will send data to a device label that matches the device Id
  delay(1000);
}
