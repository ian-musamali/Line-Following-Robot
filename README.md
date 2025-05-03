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
     
## Instructions for Assembly
1. Attach the blue chassis to form the body by connecting the Velcro.
2. Secure the motors at the front, and take off the front wheels.
3. Secure the back wheels by using the rod provided.
4. Velcro should be on the middle and front chassis for the 11.1V battery and H-bridge.
5. Connect the H-bridge to the motors with the orange wire on top and the grey wire on the bottom.
6. Connect the positive lead of the 11.1V to the H-bridge and connect the 5V output to the input on the Arduino to turn it on.
7. Use Velcro on the top of the 11.1V battery and mount the motherboard on top of the battery.
8. Follow the pin-out to wire everything, including the sensors, pump, and servo.
9. Insert the sensors into the sensor slots and tape down.
10. The pump will be placed at the back of the robot.
11. Connect everything to ground.
12. Close everything up with the top chassis.


## Usage Instructions
1. Once fully assembled connect the 5V output on the H-bridge to the arduino.
2. A 5 second wait timer will start that allows you to position the robot and close the chassis.
3. The robot will follow the line you laid before it.
4. You can shine a light on the photoresistor to make the robot stop and turn on the pump.
5. To turn off the robot simply shine a light on the photoresistor again or pick it up and unplug the 5V output.


## Demo

https://drive.google.com/file/d/1TSt5JfWD8-oTP9I-w90VdRtnBKjMMEVX/view
skip to 2:48 for demo
