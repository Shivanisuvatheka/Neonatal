#define BLYNK_TEMPLATE_ID "TMPL3zOTXfFP8"                                   // Add your blynk template id
#define BLYNK_TEMPLATE_NAME "MAX30100"                                      // Add your blynk template name
#define BLYNK_AUTH_TOKEN "D56u83-j8IH9g-qA6NGTLLv1qyKjFpnS"                 // Add your blynk auth token



#define BLYNK_PRINT Serial

#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <Wifi.h>
#include <WifiClient.h>
//#include <DNT.h>

char ssid[] = "Enter your wifi name"; 
char pass[] = "Enter your password";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V0, value);
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
}

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V0, millis() / 1000);
}

#define REPORTING_PERIOD_MS     1000

// Create a PulseOximeter object
PulseOximeter pox;

// Time at which the last beat occurred
uint32_t tsLastReport = 0;

// Callback routine is executed when a pulse is detected
void onBeatDetected() {
    Serial.println("♥ Beat!");
}


void setup() {
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    Serial.print("Initializing pulse oximeter..");

    // Initialize sensor
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }

  // Configure sensor to use 7.6mA for LED drive
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

    // Register a callback routine
    pox.setOnBeatDetectedCallback(onBeatDetected);
    timer.setInterval(1000L, myTimerEvent);
}

void loop() {
    Blynk.run();
    // Read from the sensor
    pox.update();

    // Grab the updated heart rate and SpO2 levels
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");
        Blynk.virtualWrite(V0, pox.getSpO2());
        Blynk.virtualWrite(V1, pox.getHeartRate());
        tsLastReport = millis();
        if (pox.getHeartRate()<120 || pox.getHeartRate()>180){
          Blynk.logEvent("heart_rate_alert",String("Heart rate is abnormal"));
        }
        if (pox.getSpO2()<89){
          Blynk.logEvent("low_spo2",String("SpO2 level less than 90%"));
        }
    }
}
