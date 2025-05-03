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
1. Join the blue chasis by connecting the velco
2. place the motors in the front and attatch the front wheels
3. attatch the back wheels with the provided rod
4. place velco on the middle and at the front of the chasis for the 11.1v battery and h-bridge
5. connect the h-bridge to the motors making the orange wire goes on top and the grey on the bottom.
6. connect the positive 11.1v lead to the h-bridge, and connect the 5v output to the input for the adurdino as it will power it.
7. place velcro on top of the 11v battery and plcae the motherboard on top of it.
8. use pin config to wire everything up, inlcuding the sensors, pump, and servo. 
9. place sensors in the sensor holes and tape them down.
10. place pump at the back of the robot
12. connect everything to ground.
13. close everything with the top chasis.

## How to Use
1.  once fully assembled. connect the 5v output comming from the h-bridge to the arduino,
2.  a 5 second delay will begin, giving you time to position the robot and close the chasis.
3.  the robot will begin to follow the line layed before it
4.  you can shine a light on the photoresistor to make the robot stop and activate its pumps.
5.  to stop it,shine a light on the photoresistor or simply pick it up and disconnect the 5v output.

## Demo

https://drive.google.com/file/d/1TSt5JfWD8-oTP9I-w90VdRtnBKjMMEVX/view
skip to 2:48 for demo


---
