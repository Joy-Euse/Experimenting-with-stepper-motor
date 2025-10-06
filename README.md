# ExperimentingStepperMotor

This Arduino project demonstrates how to control a 28BYJ-48 stepper motor using an Arduino and a ULN2003 driver board. The motor can be rotated by a specified angle in either direction via serial commands.

## Hardware Requirements

- Arduino board (Uno, Nano, etc.)
- 28BYJ-48 stepper motor
- ULN2003 stepper motor driver board
- Jumper wires

### Wiring

| ULN2003 IN Pin | Arduino Pin |
|:--------------:|:-----------:|
| IN1            | 8           |
| IN2            | 9           |
| IN3            | 10          |
| IN4            | 11          |

## Usage

1. Upload `ExperimentingStepperMotor.ino` to your Arduino.
2. Open the Serial Monitor (baud rate: 9600).
3. Enter commands in the following format:

```
rotate <angle> left
rotate <angle> right
```

For example:
- `rotate 90 left`
- `rotate 180 right`

## How It Works

- The sketch uses the Arduino `Stepper` library.
- It listens for serial commands to rotate the motor by a specified angle.
- The direction can be either `left` (counterclockwise) or `right` (clockwise).

## Example Output

```
Stepper ready!
Type commands: rotate <angle> left OR rotate <angle> right
Rotating left 90 degrees
Rotating right 180 degrees
```

## Author

Done by Joyeuse IRADUKUNDA from RCA