#include <Stepper.h>
// Number of steps per revolution for 28BYJ-48 stepper motor
const int stepsPerRevolution = 2048;
// ULN2003 input pins connected to Arduino
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;
// Initialize the stepper (pin order matters!)
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
void setup() {
  myStepper.setSpeed(10); // speed in RPM
  Serial.begin(9600);
  Serial.println("Stepper ready!");
  Serial.println("Type commands: rotate <angle> left OR rotate <angle> right");
}
void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // read input line
    command.trim(); // remove spaces/newline
    if (command.startsWith("rotate")) {
      int space1 = command.indexOf(' ');
      int space2 = command.indexOf(' ', space1 + 1);
      if (space1 > 0 && space2 > space1) {
        int angle = command.substring(space1 + 1, space2).toInt();
        String direction = command.substring(space2 + 1);
        // Convert degrees to steps
        int steps = (int)(angle * (stepsPerRevolution / 180.0));
        if (direction == "left") {
          Serial.print("Rotating left ");
          Serial.print(angle);
          Serial.println(" degrees");
          myStepper.step(-steps); // CCW
        }
        else if (direction == "right") {
          Serial.print("Rotating right ");
          Serial.print(angle);
          Serial.println(" degrees");
          myStepper.step(steps); // CW
        }
        else {
          Serial.println("Invalid direction! Use 'left' or 'right'");
        }
      } else {
        Serial.println("Invalid format. Try: rotate 90 left");
      }
    } else {
      Serial.println("Unknown command. Use: rotate <angle> <direction>");
    }
  }
}
