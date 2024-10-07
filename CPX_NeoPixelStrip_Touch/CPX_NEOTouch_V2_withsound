#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define CPLAY_NEOPIXELPIN 10
#define NUMPIXELS 30

// to access touch capabilities
int capsense[10];  //10

void setup() {
  CircuitPlayground.begin();

  // Define our NeoPixels
  CircuitPlayground.strip = Adafruit_CPlay_NeoPixel();
  CircuitPlayground.strip.updateType(NEO_GRB + NEO_KHZ800);
  CircuitPlayground.strip.updateLength(NUMPIXELS);
  CircuitPlayground.strip.setPin(CPLAY_NEOPIXELPIN);
  
  // Start the NeoPixels
  CircuitPlayground.strip.begin();
  CircuitPlayground.strip.show();
  CircuitPlayground.strip.setBrightness(50);
  CircuitPlayground.strip.clear();
}

void loop() {
  // Make the pins we specify active for touch - we have used 10 for the NeoPixel Strip
  capsense[0] = CircuitPlayground.readCap(9);
  capsense[1] = CircuitPlayground.readCap(2);
  capsense[2] = CircuitPlayground.readCap(0);
  capsense[3] = CircuitPlayground.readCap(1);
  capsense[4] = CircuitPlayground.readCap(12);
  capsense[5] = CircuitPlayground.readCap(6);

  // What to do if a touch is detected?
  if (capsense[0] > 100) {
    respondToTouch(262);  // Play a C4 note and show color
  } else if (capsense[1] > 100) {
    respondToTouch(294);  // Play a D4 note and show color
  } else if (capsense[2] > 100) {
    respondToTouch(330);  // Play an E4 note and show color
  } else if (capsense[3] > 100) {
    respondToTouch(349);  // Play an F4 note and show color
  } else if (capsense[4] > 100) {
    respondToTouch(392);  // Play a G4 note and show color
  } else if (capsense[5] > 100) {
    respondToTouch(440);  // Play an A4 note and show color
  }
}

void respondToTouch(int frequency) {
  CircuitPlayground.clearPixels();  // Clear existing pixels

  // Play sound
  CircuitPlayground.playTone(frequency, 200);  // Shorter tone for faster response

  // Show random colors
  int myRandomColor1 = random(20, 255);
  int myRandomColor2 = random(20, 255);
  int myRandomColor3 = random(20, 255);

  for (int i = 0; i < NUMPIXELS; i++) {  // For each pixel...
    CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.strip.Color(myRandomColor1, myRandomColor2, myRandomColor3));
  }
  CircuitPlayground.strip.show();  // Update pixels once at the end to minimize delay
}
