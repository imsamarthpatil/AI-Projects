#include <BoltIoT-Arduino-Helper.h>

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

int l1=-1, l2=-1, l3=-1, l4=-1;

String getData(String *data){
  String message = "";
  String stringl1 = String(l1);
  String stringl2 = String(l2);
  String stringl3 = String(l3);
  String stringl4 = String(l4);
  message = stringl1 + "," +stringl2 + "," + stringl3 + "," + stringl4;
  return message;
}

unsigned long next_motion_time;
int next_motion_number;

void setup(){
  // put your setup code here, to run once:
  init_motors();
  boltiot.begin(Serial);
  boltiot.setCommandString("RD\r", getData);
  next_motion_time = 0;
  next_motion_number = -1;
}

void loop(){
  // put your main code here, to run repeatedly:
  boltiot.handleCommand();
  unsigned long current_time = millis();
  if(next_motion_time > current_time){
    return;
  }
  if(next_motion_number == -1){
    forward();
    next_motion_time = current_time + 1000;
    next_motion_number =1;
  }
  else if(next_motion_number == 1){
    l1 = analogRead(A0);
    right();
    next_motion_time = current_time + 500;
    next_motion_number =2;
  }
  else if(next_motion_number == 2){
    forward();
    next_motion_time = current_time + 1000;
    next_motion_number =3;
  }
  else if(next_motion_number == 3){
    l2 = analogRead(A0);
    right();
    next_motion_time = current_time + 500;
    next_motion_number =4;
  }
  else if(next_motion_number == 4){
    forward();
    next_motion_time = current_time + 1000;
    next_motion_number =5;
  }
  else if(next_motion_number == 5){
    l3 = analogRead(A0);
    right();
    next_motion_time = current_time + 500;
    next_motion_number =6;
  }
  else if(next_motion_number == 6){
    forward();
    next_motion_time = current_time + 1000;
    next_motion_number =7;
  }
  else if(next_motion_number == 7){
    l4 = analogRead(A0);
    right();
    next_motion_time = current_time + 500;
    next_motion_number =8;
  }
  else if(next_motion_number == 8){
    stop();
    next_motion_time = current_time + 300000;
    next_motion_number =-1;
  }
}
