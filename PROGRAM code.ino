#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int alcoholSensor = A0;
int sensorValue;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Alcohol Detect");
  delay(2000);
  lcd.clear();
}

void loop() {
  sensorValue = analogRead(alcoholSensor);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  lcd.setCursor(0, 0);
  lcd.print("Value: ");
  lcd.print(sensorValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);

  if (sensorValue > 400) {
    lcd.print("Alcohol Found ");
    Serial.println("Alcohol Detected!");
  } else {
    lcd.print("No Alcohol    ");
    Serial.println("No Alcohol");
  }

  delay(1000);
}
