// IR SENSORS (LEFT -> RIGHT)
#define IR1 19    // 1st left
#define IR2 34    // 2nd middle
#define IR3 35    // 3rd right    // middle

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
  //pinMode(IR4, INPUT);

  // LEFT MOTOR
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // RIGHT MOTOR
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  Serial.begin(9600);

  int topSpeed = 255;
}

void SpinForward(int INA, int INB, int PWM, int speed)
{
    digitalWrite(INA, LOW);
    digitalWrite(INB, HIGH);
    analogWrite(PWM, speed);
}

void SpinBackward(int INA, int INB, int PWM, int speed)
{
    digitalWrite(INA, HIGH);
    digitalWrite(INB, LOW);
    analogWrite(PWM, speed);
}

void StopRotation(int INA, int INB)
{
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);
}

void loop() {

  int IR1_value = digitalRead(IR1);
  int IR2_value = digitalRead(IR2);
  int IR3_value = digitalRead(IR3);
  //int IRM = digitalRead(IR4);
  
  Serial.println("IR1: " + IR1_value);
  Serial.println("IR2: " + IR2_value);
  Serial.println("IR3: " + IR3_value);
  //Serial.println("IRM: " + IR4);

  //int leftSpeed = topSpeed;
  //int rightSpeed = topSpeed;

  if (IR1_value > IR3_value){ //

  }else if(IR1_value < IR3_value){

  }else if(IR1_value == IR3_value){

  }

}
