// Circuit is using 2 Servos
// You can use 1 servo if you want
// Servos on Pins 3 and 10
// @cmoz

// Input is for 6 items max with this circuit

// Other pins are for input, croc clip or wire to leaf or other
// input, must be conductive to work - e.g. dry plants not good
// sound can be turned off
// colour can be turned off or the color altered
// motor movement can be altered


#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
uint8_t pixeln = 0;
int capsense[10];  //10
int pos = 0;
int pos2 = 0;

void setup() {
  CircuitPlayground.begin();
  servo2.attach(3);
  servo1.attach(10);
  Serial.begin(9600);
}

void loop() {
  capsense[0] = CircuitPlayground.readCap(9);
  capsense[1] = CircuitPlayground.readCap(2);
  capsense[2] = CircuitPlayground.readCap(0);
  capsense[3] = CircuitPlayground.readCap(1);
  capsense[4] = CircuitPlayground.readCap(12);
  capsense[5] = CircuitPlayground.readCap(6);

  Serial.print("0   ");
  Serial.println(capsense[0]);
  Serial.print("1   ");
  Serial.println(capsense[1]);
  Serial.print("2   ");
  Serial.println(capsense[2]);
  Serial.print("3   ");
  Serial.println(capsense[3]);
  Serial.print("4   ");
  Serial.println(capsense[4]);
  Serial.print("5   ");
  Serial.println(capsense[5]);

  int frequency = 0;
  pos = random(10, 180);
  pos2 = random(10, 180);

  if (capsense[0] > 100) {
    frequency = 523;
    neoColorServoPos();
  } else if (capsense[1] > 100) {
    frequency = 587;
    neoColorServoPos();
  } else if (capsense[2] > 100) {
    frequency = 659;
    neoColorServoPos();
  } else if (capsense[3] > 100) {
    frequency = 698;
    neoColorServoPos();
  } else if (capsense[4] > 100) {
    frequency = 784;
    neoColorServoPos();
  } else if (capsense[5] > 100) {
    frequency = 880;
    neoColorServoPos();
  }
  delay(10);

  // If you want NO sound, comment out with // at the start of the code
  CircuitPlayground.playTone(frequency, 200);

  servo1.write(0);
  delay(10);
  servo2.write(0);
  delay(10);
}


void neoColorServoPos() {
  CircuitPlayground.clearPixels();
  int pinNum1 = random(0, 10);
  int pinNum2 = random(0, 10);
  int pinNum3 = random(0, 10);
  CircuitPlayground.setPixelColor(pinNum1, 0, 255, 255);  // green blue
  CircuitPlayground.setPixelColor(pinNum2, 255, 255, 0);  //
  CircuitPlayground.setPixelColor(pinNum3, 255, 0, 255);  //red blue

  //servo position
  servo1.write(pos);
  delay(10);
  servo2.write(pos2);
  delay(10);
  Serial.println("randPosition: ");
  Serial.println(pos);
  Serial.println("randPosition2: ");
  Serial.println(pos2);
}
