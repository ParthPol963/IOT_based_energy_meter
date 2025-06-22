#include <LiquidCrystal.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "EmonLib.h"

char ssid[] = "GalaxyM31";
char pass[] = "Parth963";

LiquidCrystal lcd(13, 12, 14, 27, 26, 25);
EnergyMonitor emon;
BlynkTimer timer;

#define VOLTAGE_PIN 35
#define CURRENT_PIN 34
#define VCAL 83.3
#define CCAL 0.50

float kWh = 0;
unsigned long lastMillis = 0;

void sendReadings() {
  emon.calcVI(20, 2000);

  float voltage = emon.Vrms;
  float current = emon.Irms;
  float power = emon.apparentPower;

  // Energy (kWh) calculation
  unsigned long now = millis();
  kWh += power * (now - lastMillis) / 3600000000.0; // W × time(h)
  lastMillis = now;

  Serial.printf("V: %.2f V | I: %.4f A | P: %.2f W | E: %.5f kWh\n", voltage, current, power, kWh);

  // LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(voltage, 1);
  lcd.print(" I:");
  lcd.print(current, 2);

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(power, 1);
  lcd.print("W E:");
  lcd.print(kWh, 2);
  delay(2500);

  // Send to Blynk
  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, power);
  Blynk.virtualWrite(V3, kWh);
}

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("Starting...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  emon.voltage(VOLTAGE_PIN, VCAL, 1.7); // Voltage pin, calibration, phase shift
  emon.current(CURRENT_PIN, CCAL);     // Current pin, calibration

  timer.setInterval(5000L, sendReadings);

  lastMillis = millis();

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("IoT Energy");
  lcd.setCursor(5, 1);
  lcd.print("Meter");
  delay(2000);
  lcd.clear();
}

void loop() {
  Blynk.run();
  timer.run();
}
