int pwmA = 13;
int in1A = 12;
int in2A = 14;

int pwmB = 2;
int in1B = 0;
int in2B = 4;
int MotorSpeed1 = 0;


void setup()

{
  Serial.begin(9600);
  // Set all the motor control pins to outputs

  pinMode(pwmA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);

   
}

void loop() {
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  analogWrite(pwmA,255);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  analogWrite(pwmA,255);
  Serial.println("one side"); 

  delay(2000);
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  analogWrite(pwmA,255);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, HIGH);
  analogWrite(pwmB,255);
  
  Serial.println("another side");
  delay(2000);
  
  
}
