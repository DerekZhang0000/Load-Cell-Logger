#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 12;
const int LOADCELL_SCK_PIN = 13;

HX711 scale;

void setup() {
  Serial.begin(57600);
  Serial.println("setup begin");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.print("pre-calibration read: \t\t");
  Serial.println(scale.read());

  float calibration_val = 0;
//  scale.set_scale(calibration_number);
//  scale.tare();               // reset the scale to 0

  Serial.print("post-calibration read: \t\t");
  Serial.println(scale.read());
  Serial.println("setup done");
}

void loop() {
  Serial.print("read:\t");
  Serial.println(scale.get_units(), 1);

  delay(1000);
}
