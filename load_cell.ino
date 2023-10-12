#include <Arduino.h>
#include "HX711.h"

//  any digital pins can be used
const int LOADCELL_DOUT_PIN = 12;
const int LOADCELL_SCK_PIN = 13;

HX711 scale;

void setup() {
  Serial.begin(57600);
  Serial.println("setup begin");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.print("pre-calibration read: \t\t");
  Serial.println(scale.read());

//  calibration_factor = (reading)/(known weight)
//  float calibration_factor = -282642 / 11;
//  scale.set_scale(calibration_factor);
//  scale.tare();

  Serial.print("post-calibration read: \t\t");
  Serial.println(scale.get_units(), 1);
  Serial.println("setup done");
}

void loop() {
  Serial.print("read:\t");
  Serial.println(scale.get_units(), 1);

  delay(1000);
}
