// IR Sensors 
#define IR1 19
#define IR2 34
#define IR3 35
#define IR4 39

// LEFT Motor PINS
#define IN1 26
#define IN2 25
#define ENA 27

// RIGHT Motor PINS
// Does NOT make sense but probably works
#define IN3 33
#define IN4 32
#define ENB 14


void setup() {
  // put your setup code here, to run once:
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  Serial.begin(9600);

  // LEFT MOTOR
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // RIGHT MOTOR
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

int speed = 70;

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

void StopAll()
{
  StopRotation(IN1, IN2);
  StopRotation(IN3, IN4);
}

void TurnLeft(int ir1_value, int INA, int INB) {
  int ir1_value = digitalRead(IR1);
  while( ir1_value != 0){
    SpinForward(IN3, IN4, ENB, speed);
    SpinBackward(IN1, IN2, ENA, speed);
  }

  while( ir1_value != 0){
    SpinForward(IN3, IN4, ENB, speed);
    SpinBackward(IN1, IN2, ENA, speed);
  }
}

void hardLeft(){
  int ir1_valueTurn = digitalRead(IR1);
  while(ir1_valueTurn == 1){
    SpinForward(IN3, IN4, ENB, speed);
    SpinBackward(IN1, IN2, ENA, speed);
  }
  int ir2_valueTurn = digitalRead(IR2);
  while(ir2_valueTurn == 0){
    SpinForward(IN3, IN4, ENB, speed);
    SpinBackward(IN1, IN2, ENA, speed);
  }
}

void hardRight(){
  int ir3_valueTurn = digitalRead(IR3);
  while(ir3_value == 1){
    SpinForward(IN1, IN2, ENA, speed);
    SpinBackward(IN3, IN4, ENB, speed);
  }
  int ir2_valueTurn = digitalRead(IR2);
  while(ir2_valueTurn == 0){
    SpinForward(IN1, IN2, ENA, speed);
    SpinBackward(IN3, IN4, ENB, speed);
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  int ir1_value = digitalRead(IR1); // * 1000;
  int ir2_value = digitalRead(IR2);
  int ir3_value = digitalRead(IR3);
  int ir4_value = digitalRead(IR4);
  int IR[4] = {ir1_value, ir2_value, ir3_value, ir4_value};
  Serial.print("IR values: ");
  Serial.println(ir1_value + 2*ir2_value + 4*ir3_value + 8*ir4_value, BIN);
  int sum = 0;
  for(int i = 0; i < 4; i++){
    sum += IR[i] * (1<<i);
  }
  Serial.print("IR Array values: ");
  Serial.println(ir1_value + 2*ir2_value + 4*ir3_value + 8*ir4_value, BIN);

  // digitalWrite(IN1, HIGH);
  // digitalWrite(IN2, LOW);
  // analogWrite(ENA, 255);

  // digitalWrite(IN3, HIGH);
  // digitalWrite(IN4, LOW);
  // analogWrite(ENB, 255);

  if (ir1_value == 0 && ir2_value == 1 && ir3_value > 0) {
    SpinForward(IN1, IN2, ENA, speed);
    SpinForward(IN3, IN4, ENB, speed);
  } else if(ir1_value == 1 && ir3_value == 0) {
    //SpinForward(IN3, IN4, ENA, speed);
    //StopRotation(IN1, IN2);
     hardLeft();
  } else if (ir1_value == 0 && ir3_value == 1) {
    hardRight();
    //SpinForward(IN1, IN2, ENA, speed);
    //StopRotation(IN3, IN4);
  } else if (ir1_value == 0 && ir2_value == 1 && ir3_value == 1) {
    hardRight();
  } else if (ir1_value == 1 && ir2_value == 1 && ir3_value == 0) {
    hardLeft();
  } else {
    //hardRight();
    SpinForward(IN1, IN2, ENA, speed);
    SpinForward(IN3, IN4, ENB, speed);
  }
}