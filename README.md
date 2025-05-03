# Line-Following-Robot

# Fire Truck Robot

Autonomous fire-fighting robot that follows a line, detects light (simulated fire), and activates a water pump with a sweeping servo to extinguish it.

## Features

- Line following with two downward-facing IR sensors (left/right)
- Light detection with a forward-facing IR sensor
- Water spraying using a pump and sweeping servo when light is detected
- Motor control via L298N H-Bridge (PWM speed adjustable)

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

## Notes

- `Speed = 125` by default (range 0–255)
- `val_M > 400` triggers fire response
- Uses basic PWM servo control without Servo.h
- Delay of 5 seconds at startup

## How to Use
1.  
## Demo

https://drive.google.com/file/d/1TSt5JfWD8-oTP9I-w90VdRtnBKjMMEVX/view
skip to 2:48 for demo


---
