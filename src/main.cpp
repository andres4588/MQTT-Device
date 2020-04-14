
#include "Arduino.h"
#include <constants.h>
#include <mqtt_connect.h>
#include <WiFi101.h>
#include <MQTT.h>



WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;


void setup()
{
   Serial.begin(115200);
  WiFi.begin(ssid, pass);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin(BROKER, net);
 

  connect();
}

void loop()
{
  
   client.loop();

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    lient.publish(String(MQTT_ID)+"/report", "hola world"));
  }
}