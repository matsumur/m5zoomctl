#include <M5Stack.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "main.h"

void setup() {
  M5.begin();
  delay(1000);

  M5.Lcd.printf("Connecting to %s\n", SSID);
  WiFi.begin(SSID, PASSWD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  M5.Lcd.clearDisplay();

  M5.Lcd.drawBitmap(0, 0, 320, 240, BUTTONIMG);

  if(DEBUG){
    M5.Lcd.printf("WiFi Connection established.\n SSID: %s\n", SSID);
    M5.Lcd.print("IP: ");
    M5.Lcd.println(WiFi.localIP());
  }
}

void loop() {
  M5.update();
  if (M5.BtnA.wasPressed()) {
    sendCmd(SERVER, AUDIO);
  }
  if (M5.BtnB.wasPressed()) {
    sendCmd(SERVER, ACTIVATE);
  }
  if (M5.BtnC.wasPressed()) {
    sendCmd(SERVER, VIDEO);
  }
  delay(100);
}

void sendCmd(const char host[], int mode) {
  HTTPClient http;
  switch(mode){
    case AUDIO:
      http.begin(String(host) + "/a");
      break;
    case VIDEO:
      http.begin(String(host) + "/v");
      break;
    case ACTIVATE:
      http.begin(String(host) + "/z");
      break;
    default:
      return;
  }
  http.GET();
  http.end();
  return;
}