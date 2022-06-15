#include <BoltIoT-Arduino-Helper.h>

void init_motors(){
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void Forward(){
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
}

void Reverse(){
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(8, HIGH);
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

void Left_Forward(){
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
}

void Right_Forward(){
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}

void Right_Reverse(){
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, HIGH);
}

void Left_Reverse(){
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}

void Stop(){
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}

String doMotion(String *data){
  if(data[0] == "q"){
    Left_Forward();
  }
  if(data[0] == "w"){
    Forward();
  }
  if(data[0] == "e"){
    Right_Forward();
  }
  if(data[0] == "a"){
    Left();
  }
  if(data[0] == "d"){
    Right();
  }
  if(data[0] == "z"){
    Left_Reverse();
  }
  if(data[0] == "x"){
    Reverse();
  }
  if(data[0] == "c"){
    Right_Reverse();
  }
  if(data[0] == "s"){
    Stop();
  }
  delay(2000);
  Stop();
  return "Done";
}

void setup(){
  // put your setup code here, to run once:
  init_motors();
  boltiot.begin(Serial);
  boltiot.setCommandString("doMotion", doMotion, 1);
  pinMode(11, INPUT);
}

void loop(){
  // put your main code here, to run repeatedly:
  // boltiot.handleCommand();
  if(digitalRead(11)==HIGH){
    Forward();
    if(boltiot.handleCommand()){
      delay(20000);
    }
  }
  else{
    Reverse();
    delay(1000);
    Left();
    delay(1000);
  }
}     
