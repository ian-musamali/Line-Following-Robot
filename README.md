# Line-Following-Robot

# Fire Truck Robot

This is a line-following, fire-fighting robot that follows a line, detects light (simulated fire), and activates a water pump with a sweeping servo to extinguish it.

## Pin Configuration

### Motor Driver (L298N)
| Function       | Arduino Pin | Description                  |
|----------------|-------------|------------------------------|
| enA            | 10          | Right motor speed (PWM)      |
| in1, in2       | 9, 8        | Right motor direction        |
| in3, in4       | 7, 6        | Left motor direction         |
| enB            | 5           | Left motor speed (PWM)       |

### IR Sensors
| Sensor        | Pin | Purpose                    |
|---------------|-----|----------------------------|
| ir_L (Left)   | A0  | Line following             |
| ir_M (Middle) | A1  | Light detection (fire)     |
| ir_R (Right)  | A2  | Line following             |

### Peripherals
| Device       | Pin | Function                    |
|--------------|-----|-----------------------------|
| Servo Motor  | A4  | Controls sprinkler sweep     |
| Water Pump   | A5  | Turns pump on/off           |

## Behavior Logic

1. **Line Following**
   - If left IR detects line → veer left
   - If right IR detects line → veer right
   - Otherwise, go straight

2. **Fire Detection**
   - If forward-facing sensor detects bright light:
     - Stop
     - Turn on pump
     - Sweep sprinkler left to right
   - Else, keep driving
     
## Assembly Instructions
1. Join the blue chassis by connecting the Velcro.
2. Place the motors in the front and attach the front wheels.
3. Attach the back wheels using the provided rod.
4. Place Velcro in the middle and front of the chassis for the 11.1V battery and H-bridge.
5. Connect the H-bridge to the motors, ensuring the orange wire is on top and the grey wire is on the bottom.
6. Connect the positive 11.1V lead to the H-bridge, and connect the 5V output to the Arduino's input to power it.
7. Place Velcro on top of the 11.1V battery and mount the motherboard on top.
8. Use the pin configuration to wire everything, including the sensors, pump, and servo.
9. Place the sensors into the sensor slots and tape them down.
10. Place the pump at the back of the robot.
11. Connect everything to ground.
12. Close everything with the top chassis.

## How to Use
1. Once fully assembled, connect the 5V output from the H-bridge to the Arduino.
2. A 5-second delay will begin, giving you time to position the robot and close the chassis.
3. The robot will begin to follow the line laid before it.
4. You can shine a light on the photoresistor to make the robot stop and activate the pump.
5. To stop it, shine a light on the photoresistor again or simply pick it up and disconnect the 5V output.

## Demo

https://drive.google.com/file/d/1TSt5JfWD8-oTP9I-w90VdRtnBKjMMEVX/view
skip to 2:48 for demo


---
