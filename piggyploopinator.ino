#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

// IR sensor pins (line following only)
#define ir_L A0
#define ir_R A2

int Speed = 85;

int val_L, val_R;

void setup() {
  Serial.begin(9600);

  pinMode(ir_L, INPUT);
  pinMode(ir_R, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  delay(5000);
}

void loop() {
  val_L = analogRead(ir_L);
  val_R = analogRead(ir_R);

  Serial.print("L: ");
  Serial.print(val_L);
  Serial.print(" R: ");
  Serial.println(val_R);

  if (val_L > 500 && val_R <= 500) {
    turnLeft();
  }
  else if (val_R > 500 && val_L <= 500) {
    turnRight();
  }
  else {
    forward();
  }

  delay(50);
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
