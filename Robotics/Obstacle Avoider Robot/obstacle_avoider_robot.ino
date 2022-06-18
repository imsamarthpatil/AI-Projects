void init_motors(){
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void forward(){
  digitalWrite(4, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void reverse(){
  digitalWrite(4, LOW);
  digitalWrite(12, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}

void right(){
  digitalWrite(4, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
}

void left(){
  digitalWrite(7, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(8, LOW);
}

void left_forward(){
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
}

void right_forward(){
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
}

void right_reverse(){
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(4, LOW);
}

void left_reverse(){
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(4, LOW);
  digitalWrite(12, LOW);
}

void stop(){
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(4, LOW);
  digitalWrite(12, LOW);
}

void setup(){
  // put your setup code here, to run once:
  pinMode(11, INPUT);
  init_motors();
}
void loop(){
  // put your main code here, to run repeatedly:
  if(digitalRead(11)==HIGH){
    forward();
  }else{
    reverse();
    delay(1000);
    left();
    delay(3000);
  }
}
