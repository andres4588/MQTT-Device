void connect(){
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect(MQTT_ID, MQTT_USER, MQTT_PASSWORD)) {
    uart.print(".");
    delay(1000);
  }
  Serial.println("\nconnected!");
  client.subscribe(String(MQTT_ID)+"/#");
}