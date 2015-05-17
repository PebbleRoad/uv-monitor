#include <Wire.h>
#include "Adafruit_SI1145.h"

Adafruit_SI1145 uv = Adafruit_SI1145();

const int pinRed = 6;
const int pinGreen = 5;
const int pinBlue = 3;

int green[3] = {56, 255, 0};
int yellow[3] = {255, 255, 0};
int orange[3] = {230, 110, 26};
int red[3] = {255, 15, 0};
int purple[3] = {112, 47, 160};
int blue[3] = {0, 0, 160};
int off[3] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  
  if (!uv.begin()) {
    Serial.println("Didn't find Si1145");
    while (1);
  }

  // set the digital pins as outputs
  pinMode (pinRed, OUTPUT);
  pinMode (pinGreen, OUTPUT);
  pinMode (pinBlue, OUTPUT);

  Serial.println("======= READY =======");

}

void loop() {

  float uvIndex = uv.readUV();
  uvIndex /= 100.0;
  uvIndex = round(uvIndex);
  // Serial.print("UV: ");  Serial.println(round(uvIndex));
  Serial.print("UV: ");  Serial.println(uvIndex);

  if (uvIndex >= 11) {
    setColour (purple);
  }
  else if (uvIndex >= 8) {
    setColour (red);
  }
  else if (uvIndex >= 6) {
    setColour (orange);
  }
  else if (uvIndex >= 3) {
    setColour (yellow);
  }
  else if (uvIndex >= 0) {
    setColour (green);
  }
  else {
    setColour (blue);
  }

  delay(1000);
}

void setColour (int colour[3]) {
  analogWrite (pinRed, colour[0]);
  analogWrite (pinGreen, colour[1]);
  analogWrite (pinBlue, colour[2]);
}