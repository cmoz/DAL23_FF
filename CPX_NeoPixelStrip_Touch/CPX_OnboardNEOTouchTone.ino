#include <Adafruit_CircuitPlayground.h>  // Include only the Circuit Playground library

#define RAINBOW_SPEED 10  // Speed of the rainbow animation

// To access touch capabilities
int capsense[10];
int rainbowOffset = 0;  // Variable to control the rainbow color offset

void setup() {
  CircuitPlayground.begin();            // Initialize the Circuit Playground
  CircuitPlayground.setBrightness(50);  // Set brightness for built-in NeoPixels
}

void loop() {
  // Read capacitive touch inputs
  capsense[0] = CircuitPlayground.readCap(9);
  capsense[1] = CircuitPlayground.readCap(2);
  capsense[2] = CircuitPlayground.readCap(0);
  capsense[3] = CircuitPlayground.readCap(1);
  capsense[4] = CircuitPlayground.readCap(12);
  capsense[5] = CircuitPlayground.readCap(6);

  // Check if any touch is detected
  bool touchDetected = false;
  for (int i = 0; i < 6; i++) {
    if (capsense[i] > 100) {
      showSolidColorFromRainbow(i);  // Show a solid color based on the touch index
      touchDetected = true;
      break;  // Exit the loop if any touch is detected
    }
  }

  // Show rainbow on the built-in NeoPixels if no touch is detected
  if (!touchDetected) {
    showRainbowOnBuiltInPixels();
  }
}

void showSolidColorFromRainbow(int touchIndex) {
  // Clear the built-in pixels
  CircuitPlayground.clearPixels();

  // Calculate the color based on the touch index and rainbow offset
  int colorHue = (touchIndex * 256 / 10) + rainbowOffset;
  uint32_t solidColor = CircuitPlayground.colorWheel(colorHue & 255);  // Get the color from the color wheel

  // Set all built-in NeoPixels to the solid color
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, solidColor);
  }

  // Optionally play a sound or tone here if desired
  CircuitPlayground.playTone(262 + (touchIndex * 50), 200);  // Play a tone based on the touch index
}

void showRainbowOnBuiltInPixels() {
  // Show a rainbow pattern on the built-in NeoPixels of Circuit Playground
  for (int i = 0; i < 30; i++) {  // There are 10 built-in NeoPixels on Circuit Playground
    int pixelHue = (i * 256 / 10) + rainbowOffset;  // Calculate hue based on pixel index and offset
    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(pixelHue & 255));  // Set color using colorWheel function for built-in pixels
  }
  rainbowOffset++;  // Increment offset for the next rainbow frame
  delay(RAINBOW_SPEED);  // Small delay to control animation speed
}
