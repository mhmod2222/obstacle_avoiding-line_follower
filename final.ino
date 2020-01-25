const int trig = 11;
const int echo = 12;

const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 6;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 5;

int L_S = 2;
int R_S = 3;

int RSpd = 90;
int LSpd = 70;
int trnSpd = 100;
int setdist = 12;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  //Serial.begin(9600);
  delay (3000);
}

void loop() {
  int distance;
  distance = getDistance();
  //Serial.println(distance);
  if(distance>setdist){ // 0 is white, and 1 is black
    if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 0)){goForward();}
    if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
    if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
    if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 1)){while (1) Stop();}
    
  }
  else{
    turnRight();
    delay(300);
    goForward();
    delay(250);
    turnLeft();  
    delay(300);
    goForward();
  }
}

int getDistance() {
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);   //wait for HIGH 
  return (duration/2) / 29.15;  //calculate the distance in cm
}  

void goForward ()
{
  analogWrite(ENA, LSpd);
  analogWrite(ENB, RSpd); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft ()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, trnSpd); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight ()
{
  analogWrite(ENA, trnSpd);
  analogWrite(ENB, 0); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void goBackward ()
{
  analogWrite(ENA, RSpd);
  analogWrite(ENB, LSpd);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
