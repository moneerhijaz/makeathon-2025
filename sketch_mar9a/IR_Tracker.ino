// IR Sensors 
#define IR_1_PIN 19
#define IR_2_PIN 34
#define IR_3_PIN 35

// LEFT Motor PINS
#define IN1 26
#define IN2 25
#define ENA 27

// RIGHT Motor PINS
#define IN3 33
#define IN4 32
#define ENB 14


void setup() {
  // put your setup code here, to run once:
  pinMode(IR_1_PIN, INPUT);
  pinMode(IR_2_PIN, INPUT);
  pinMode(IR_3_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ir_1_value = digitalRead(IR_1_PIN); // * 1000;
  int ir_2_value = digitalRead(IR_2_PIN);
  int ir_3_value = digitalRead(IR_3_PIN);
  Serial.println(ir_1_value + 2*ir_2_value + 4*ir_3_value, BIN);
}
