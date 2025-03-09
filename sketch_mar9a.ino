// IR SENSORS (LEFT -> RIGHT)
#define IR1 19    // 1st
#define IR2 34    // 2nd
#define IR3 35    // 3rd
#define IR4     // middle

// LEFT MOTOR PINS
#define IN1 26
#define IN2 25
#define ENA 27

// RIGHT MOTOR PINS
#define IN3 33
#define IN4 32
#define ENB 14

void setup() {

  // IR SENSORS
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);

  // LEFT MOTOR
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // RIGHT MOTOR
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  Serial.begin(100);

  int topSpeed = 255;
}

void loop() {

  int IR1 = digitalRead(IR1);
  int IR2 = digitalRead(IR2);
  int IR3 = digitalRead(IR3);
  int IRM = digitalRead(IR4);
  
  Serial.println("IR1: " + IR1);
  Serial.println("IR2: " + IR2);
  Serial.println("IR3: " + IR3);
  Serial.println("IRM: " + IR4);

  int leftSpeed = topSpeed;
  int rightSpeed = topSpeed;

  if (IR1 > )


}
