// Motor control pins (connected to L298N H-Bridge motor driver)
#define enA 10    // Enable pin for right motor (PWM pin)
#define in1 9     // Controls direction of right motor 1
#define in2 8     // Controls direction of right motor 2
#define in3 7     // Controls direction of left motor 1
#define in4 6     // Controls direction of left motor 2
#define enB 5     // Enable pin for left motor (PWM pin)

// IR sensor pins
#define ir_L A0   // Left IR sensor (pointing down — for line following)
#define ir_M A1   // Middle IR sensor (pointing forward/up — for light detection)
#define ir_R A2   // Right IR sensor (pointing down — for line following)

// Peripheral control pins
#define servo A4  // Servo motor control pin (PWM signal to sweep sprinkler)
#define pump A5   // Digital output pin to control water pump (via MOSFET or relay)

// Motor speed (0–255). Higher means faster.
int Speed = 125;

// Variables to hold sensor readings
int val_L, val_M, val_R;

void setup() {
  // Initialize serial monitor for debugging
  Serial.begin(9600);

  // Set IR sensors as inputs
  pinMode(ir_L, INPUT);
  pinMode(ir_M, INPUT);
  pinMode(ir_R, INPUT);

  // Set all motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  // Set servo and pump pins as outputs
  pinMode(servo, OUTPUT);
  pinMode(pump, OUTPUT);

  // Set initial motor speeds for both sides
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  // Brief delay before starting
  delay(5000);
}

void loop() {
  // Read analog values from IR sensors
  val_L = analogRead(ir_L);  // Left sensor (line follower)
  val_M = analogRead(ir_M);  // Middle sensor (light detection)
  val_R = analogRead(ir_R);  // Right sensor (line follower)

  // Print sensor values to serial monitor
  Serial.print("L: ");
  Serial.print(val_L);
  Serial.print(" M: ");
  Serial.print(val_M);
  Serial.print(" R: ");
  Serial.println(val_R);

  // ---- LINE FOLLOWING LOGIC (LEFT AND RIGHT SENSORS) ----
  if (val_L > 500 && val_R <= 500) {
    turnLeft(); // Veer left to get back on the line
  }
  else if (val_R > 500 && val_L <= 500) {
    turnRight(); // Veer right to get back on the line
  }
  else if (val_M > 400){
    stop();
  }
  else {
    forward(); // Both sensors show similar readings: go straight
  }

  // ---- LIGHT DETECTION LOGIC (MIDDLE SENSOR) ----
  if (val_M > 400) {
    digitalWrite(pump, HIGH); // Turn on water pump
    sweepServo();             // Move the sprinkler back and forth
  } else {
    digitalWrite(pump, LOW);  // Turn off the pump when light is low
  }

  // Small delay to reduce CPU load and prevent jitter
  delay(50);
}

// Moves the robot forward by setting motor directions
void forward() {
  // Right motor configuration (forward)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left motor configuration (forward) -- corrected for O3 model
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

//  stops robot
void stop() {
  // Right motor configuration (forward)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Left motor configuration (forward) -- corrected for O3 model
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// Turns the robot slightly left (adjusted for line following)
void turnLeft() {
  // Right motor moves forward; left motor stops
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Turns the robot slightly right (adjusted for line following)
void turnRight() {
  // Left motor moves forward; right motor stops
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Rotates the sprinkler servo back and forth
void sweepServo() {
  // Sweep right
  for (int angle = 90; angle <= 140; angle += 5) {
    servoPulse(servo, angle);
  }
  // Sweep left
  for (int angle = 140; angle >= 40; angle -= 5) {
    servoPulse(servo, angle);
  }
  // Return to center
  for (int angle = 40; angle <= 90; angle += 5) {
    servoPulse(servo, angle);
  }
}

// Sends a pulse to the servo motor based on the given angle
void servoPulse(int pin, int angle) {
  int pwm = (angle * 11) + 500; // Convert angle to pulse width in microseconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(pin, LOW);
  delay(20);
}