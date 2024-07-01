#define BLYNK_TEMPLATE_ID "TMPL3zOTXfFP8"                                // Add your blynk template id
#define BLYNK_TEMPLATE_NAME "MAX30100"                                   // Add your blynk template name
#define BLYNK_AUTH_TOKEN "D56u83-j8IH9g-qA6NGTLLv1qyKjFpnS"              // Add your blynk template auth token
 
 
#include <Wire.h>
#include <MPU6050.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "D56u83-j8IH9g-qA6NGTLLv1qyKjFpnS";       // You should get Auth Token in the Blynk App.
char ssid[] = "Enter your wifi name";                   // Your WiFi name
char pass[] = "Enter your wifi password";               // Your WiFi password

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  
  Blynk.begin(auth, "YourWiFiSSID", "YourWiFiPassword");
}

void loop() {
  Blynk.run();
  float ax, ay, az;
  float gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Print the accelerometer and gyroscope values
  Serial.print("Accel: ");
  Serial.print(ax);
  Serial.print(" / ");
  Serial.print(ay);
  Serial.print(" / ");
  Serial.print(az);
  Serial.print(" | Gyro: ");
  Serial.print(gx);
  Serial.print(" / ");
  Serial.print(gy);
  Serial.print(" / ");
  Serial.println(gz);

  // Send the accelerometer and gyroscope values to Blynk
  Blynk.virtualWrite(V2, ax);
  Blynk.virtualWrite(V3, ay);
  Blynk.virtualWrite(V4, az);
  Blynk.virtualWrite(V5, gx);
  Blynk.virtualWrite(V6, gy);
  Blynk.virtualWrite(V7
  , gz);

  delay(1000); // You can adjust the delay based on your needs
}
