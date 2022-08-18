#include <Arduino.h>
  #include "FastLED.h"

#define DATA_PIN 2
#define NUM_LEDS 30

CRGB leds[NUM_LEDS];

void setup() 
{ 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(150);
}

uint16_t time = 0;

uint8_t HUE = 47;
uint8_t BRIGHT = 200;
uint8_t SATUR = 255;

uint8_t noiseData[NUM_LEDS];

void loop()
{ 
    memset(noiseData, 0, NUM_LEDS);

    fill_raw_noise8(noiseData, 30, 1, 0, 250, time);

    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CHSV(HUE, SATUR, noiseData[i]);
    }
    FastLED.show();
    time++;
}