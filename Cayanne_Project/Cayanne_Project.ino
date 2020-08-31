#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "www.interactiverobotics.club";
char wifiPassword[] = "cilibur2019";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "c7205250-eb1b-11ea-883c-638d8ce4c23d";
char password[] = "72ea1a5206e5a4824db72722bc6fd7c88f151b34";
char clientID[] = "e81a6630-eb1b-11ea-a67f-15e30d90bbf4";

#define RELAY1 D5

void setup() {
	Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
	Cayenne.loop();
}

// This function is called when data is sent from Cayenne.
CAYENNE_IN(1)
{
  // Write value to turn the relay switch on or off. This code assumes you wire your relay as normally open.
  if (getValue.asInt() == 0) {
    digitalWrite(RELAY1, HIGH);
  }
  else {
    digitalWrite(RELAY1, LOW);
  }
}

// This function is called at intervals to send data to Cayenne and keep the device online.
// Will create a temporary green widget on Channel 0, make it permanent by clicking on '+'. 
CAYENNE_OUT(2)
{
  CAYENNE_LOG("Send data for Virtual Channel 0");
  int data1=random(0,10);
  Cayenne.virtualWrite(2, data1);
}

CAYENNE_OUT(3)
{
  CAYENNE_LOG("Send data for Virtual Channel 0");
  int data2=random(0,10);
  Cayenne.virtualWrite(3, data2);
}

 
