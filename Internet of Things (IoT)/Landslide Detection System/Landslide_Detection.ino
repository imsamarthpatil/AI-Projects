int vib_pin=2;
int led_pin=13;
int buz_pin=11;

void setup() { 
  // put your setup code here, to run once:
  pinMode(vib_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  pinMode(buz_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  val=digitalRead(vib_pin);
  if(val==1)
  {
    for (int i = 1; i <= 5; i++){ 
      digitalWrite(led_pin,LOW);
      digitalWrite(buz_pin,LOW);
      delay(100);
      digitalWrite(led_pin,HIGH);
      digitalWrite(buz_pin,HIGH);
      delay(100);
      }
   }
   else
   digitalWrite(led_pin,LOW);
   digitalWrite(buz_pin,LOW);
}
