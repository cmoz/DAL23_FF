#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define CPLAY_NEOPIXELPIN 10
#define NUMPIXELS 30

void setup() {
  CircuitPlayground.begin();

  //define our neoPixels
  CircuitPlayground.strip = Adafruit_CPlay_NeoPixel();
  CircuitPlayground.strip.updateType(NEO_GRB + NEO_KHZ800);
  CircuitPlayground.strip.updateLength(NUMPIXELS);
  CircuitPlayground.strip.setPin(CPLAY_NEOPIXELPIN);
  // start the NeoPixels
  CircuitPlayground.strip.begin();
  CircuitPlayground.strip.show();
  CircuitPlayground.strip.setBrightness(50);
  CircuitPlayground.strip.clear();
}

void loop() {
  CircuitPlayground.clearPixels();

  delay(500);

  CircuitPlayground.setPixelColor(0, 255,   0,   0);
  CircuitPlayground.setPixelColor(1, 128, 128,   0);
  CircuitPlayground.setPixelColor(2,   0, 255,   0);
  CircuitPlayground.setPixelColor(3,   0, 128, 128);
  CircuitPlayground.setPixelColor(4,   0,   0, 255);
  
  CircuitPlayground.setPixelColor(5, 0xFF0000);
  CircuitPlayground.setPixelColor(6, 0x808000);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  CircuitPlayground.setPixelColor(8, 0x008080);
  CircuitPlayground.setPixelColor(9, 0x0000FF);

  delay(2000);

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    //Serial.println("for");
    CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.strip.Color(100, 255, 255));
    CircuitPlayground.strip.show();
    delay(50);
   }
 
  delay(5000);
}
