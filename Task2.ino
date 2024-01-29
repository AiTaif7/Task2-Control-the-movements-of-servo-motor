/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial
*/
#include <Servo.h>

int flag = 0;
Servo myservo;
int pos = 90;  // Starting position

void setup() {
  myservo.attach(8);
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  int sensorVal = digitalRead(7);

  if (sensorVal == LOW) {  // Button is pressed
    delay(50);  // Debounce delay to avoid multiple readings on a single press

    if (flag == 0) {
      // Move right
      for (pos = 90; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      flag = 1;
    } else {
      // Move left
      for (pos = 180; pos >= 90; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
      flag = 0;
    }

    // Optional: Add a delay to avoid rapid multiple movements on a single button press
    delay(500);
  }

  // Uncomment the next line if you want to return the servo to the starting position when the button is not pressed
  // myservo.write(90);
}
