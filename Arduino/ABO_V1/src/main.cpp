#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

const char* SSID     = "sylvain_a_0";
const char* PASSWORD = "1570thomas";

void setup() {

    Serial.begin(115200);
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) delay(500);

    configTime(-5 * 3600, 3600, "pool.ntp.org"); // UTC-5, DST +1h
    struct tm timeinfo;
    while (!getLocalTime(&timeinfo)) delay(500);

    Serial.println("WiFi connecté, heure synchronisée");
    
}

void loop() {
    struct tm timeinfo;
    getLocalTime(&timeinfo);
    Serial.println(&timeinfo, "%H:%M:%S");
    delay(1000);
}