#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int overload = 0;
const int relay = 8;
const int voltagePin = A0;
const int currentPin = A1;

float voltageCalibration = 2.5;
float currentCalibration = 0.030;

float voltageOffset = 512.0;
float currentOffset = 525.0;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Energy Meter");
  delay(2000);
  lcd.clear();
}

void loop() {

  long voltageSum = 0;
  long currentSum = 0;

  int samples = 1000;

  for (int i = 0; i < samples; i++)
  {
    int adcV = analogRead(voltagePin);
    int adcI = analogRead(currentPin);

    float v = adcV - voltageOffset;
    float c = adcI - currentOffset;

    voltageSum += v * v;
    currentSum += c * c;

    delayMicroseconds(200);
  }

  float Vrms = sqrt(voltageSum / samples) * voltageCalibration;
  float Irms = sqrt(currentSum / samples) * currentCalibration;

  // Remove small noise current
  if (Irms < 0.05) {
    Irms = 0;
  }
  if (Irms > 0.55) {
    overload = 1;   // remember overload happened
  }
  float power = Vrms * Irms;
  if (overload == 1) {
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WARNING");
    lcd.setCursor(0, 1);
    lcd.print("HIGH CURRENT!");
  }
  else {
    digitalWrite(relay, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("V:");
    lcd.print(Vrms);
    lcd.print("V ");
    lcd.print("I:");
    lcd.print(Irms);
    lcd.print("A");

    lcd.setCursor(0, 1);
    lcd.print("P:");
    lcd.print(power);
    lcd.print("W ");
  
  }

  Serial.print("Voltage: ");
  Serial.print(Vrms);
  Serial.print(" V   ");

  Serial.print("Current: ");
  Serial.print(Irms);
  Serial.print(" A   ");

  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" W");

  delay(1000);
}