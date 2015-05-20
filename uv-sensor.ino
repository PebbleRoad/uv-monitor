#include <Wire.h>
#include "Adafruit_SI1145.h"
#include <LiquidCrystal.h>

Adafruit_SI1145 uv = Adafruit_SI1145();

// const int pinRed = 6;
// const int pinGreen = 5;
// const int pinBlue = 3;

// int green[3] = {56, 255, 0};
// int yellow[3] = {255, 255, 0};
// int orange[3] = {230, 110, 26};
// int red[3] = {255, 15, 0};
// int purple[3] = {112, 47, 160};
// int blue[3] = {0, 0, 160};
// int off[3] = {0, 0, 0};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 7, 8, 9, 10);

const int contrastPin = 3;

void setup() {
  Serial.begin(9600);
  
  analogWrite(contrastPin, 190); // 190 for battery, 10 for usb..
  lcd.begin(16, 2);
  lcd.print("PebbleRoad");
  
  if (!uv.begin()) {
    Serial.println("Didn't find Si1145");
    lcd.print("sensor not found");
    while (1);
  }

  // set the digital pins as outputs
  // pinMode (pinRed, OUTPUT);
  // pinMode (pinGreen, OUTPUT);
  // pinMode (pinBlue, OUTPUT);

  Serial.println("======= READY =======");

}

void loop() {

  float uvIndex = uv.readUV();
  uvIndex /= 100.0;
  // uvIndex = round(uvIndex);
  // Serial.print("UV: ");  Serial.println(round(uvIndex));
  Serial.print("UV: ");  Serial.println(uvIndex);

  // if (uvIndex >= 11) {
  //   setColour (purple);
  // }
  // else if (uvIndex >= 8) {
  //   setColour (red);
  // }
  // else if (uvIndex >= 6) {
  //   setColour (orange);
  // }
  // else if (uvIndex >= 3) {
  //   setColour (yellow);
  // }
  // else if (uvIndex >= 0) {
  //   setColour (green);
  // }
  // else {
  //   setColour (blue);
  // }
  
  lcd.setCursor(0, 1);
  lcd.print("UV Index: ");
  lcd.print(uvIndex);

  delay(1000);
}