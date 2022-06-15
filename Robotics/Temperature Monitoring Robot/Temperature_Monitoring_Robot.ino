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

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
const int LM35 = A0;  

void setup(){
  // put your setup code here, to run once:
  pinMode(11, INPUT); // for IR sensor 
  init_motors();
  Serial.begin(9600);
  mySerial.begin(115200);
}

void loop(){
  // put your main code here, to run repeatedly:
  int ADC;
  float temp;
  ADC = analogRead(LM35);  
  temp = (ADC * 4.88); // Convert value equ. Voltage
  temp = (temp / 10); // LM35 gives 10mV/*C
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println(" *C");
  mySerial.println(temp);
  delay(1000);
  
  if(digitalRead(11)==HIGH){
    Forward();
  }else{
    Reverse();
    delay(1000);
    Left();
    delay(500);
  }
}
