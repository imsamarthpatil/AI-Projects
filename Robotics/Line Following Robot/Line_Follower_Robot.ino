void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(4, OUTPUT);
pinMode(12, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
int a = analogRead(A0);
int b = analogRead(A1);

// Forward
if(a<100 && b<100){
  Forward();
}
// Right
if(a>100 && b<100){
  Right();
}
// Left
if(a<100 && b>100){
  Left();
}
// Stop
if(a>100 && b>100){
  Stop();
}
}

void Forward(){
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
}

void Right(){
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
}

void Left(){
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, HIGH);
}

void Stop(){
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}
