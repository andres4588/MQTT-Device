#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <constants.h>
#include <connect.h>
#include <llp.h>
#include <lm_sensor.h>
DataPack input = DataPack();
LmSensor sensor_lm= LmSensor(0x80, 1, 500);


WiFiClient net;
MQTTClient client;



long reportTimer = millis();
long alarmTimer = millis();

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, SSID_PASSWORD);
  client.begin(BROKER, net);
  connect(Serial, net, client);
  sensor_lm.init(4);
}

void loop() {
  client.loop();
  delay(10);

  if (!client.connected()) {
    connect(Serial, net, client);
  }

  if(millis()-reportTimer >= REPORT_FREQ){
    reportTimer=millis();
    client.publish(String(MQTT_ID)+"/temp", String(sensor_lm.read()));
  }
}