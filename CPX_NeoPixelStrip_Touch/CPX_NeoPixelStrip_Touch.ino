#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define CPLAY_NEOPIXELPIN 10
#define NUMPIXELS 30

// to access touch capabilities
int capsense[10];  //10

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
  // make the pins we specify active for touch - we have used 10 for the NeoPixel Strip
  capsense[0] = CircuitPlayground.readCap(9);
  capsense[1] = CircuitPlayground.readCap(2);
  capsense[2] = CircuitPlayground.readCap(0);
  capsense[3] = CircuitPlayground.readCap(1);
  capsense[4] = CircuitPlayground.readCap(12);
  capsense[5] = CircuitPlayground.readCap(6);

  CircuitPlayground.clearPixels();

  delay(500);

   // what to do if a touch is detected?
    if (capsense[0] > 100) {
    neoColor();
  } else if (capsense[1] > 100) {
    neoColor();
  } else if (capsense[2] > 100) {
    neoColor();
  } else if (capsense[3] > 100) {
    neoColor();
  } else if (capsense[4] > 100) {
    neoColor();
  } else if (capsense[5] > 100) {
    neoColor();
  }
  delay(10);
}

void neoColor() {
  CircuitPlayground.clearPixels();
  int myRandomColor1 = random(20, 255);
  int myRandomColor2 = random(20, 255);
  int myRandomColor3 = random(20, 255);
  // int pinNum1 = random(0, 10);
  // int pinNum2 = random(0, 10);
  // int pinNum3 = random(0, 10);
  // CircuitPlayground.setPixelColor(pinNum1, 0, 255, 255);  // green blue
  // CircuitPlayground.setPixelColor(pinNum2, 255, 255, 0);  //
  // CircuitPlayground.setPixelColor(pinNum3, 255, 0, 255);  //red blue

    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.strip.Color(myRandomColor1, myRandomColor2, myRandomColor3));
    CircuitPlayground.strip.show();
    delay(10);
   }
   delay(100);
}