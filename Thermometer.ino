#include <SevSeg.h>

#include <DHT.h>

#include "DHT.h"

// INSERT THE PIN CONNECTED TO THE SENSOR.
#define DHTPIN A5

// INSERT THE TYPE OF SENSOR.
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

SevSeg sevseg;

void setup() {

  // INSERT THE NUMBER OF DIGITS IN YOUR DISPLAY.
  byte numDigits = 4;
  
  // INSERT THE PINS CONNECTED TO THE DIGITS.
  byte digitPins[] = {10, 11, 12, 13};

  // INSERT THE PINS CONNECTED TO THE SEGMENTS.
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = false;

  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(50);
}

void loop() {
  int t = dht.readTemperature();
  
  sevseg.setNumber(t);
  sevseg.refreshDisplay();
}
