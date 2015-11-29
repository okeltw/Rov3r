#include <Servo.h>

Servo myservo;

int potpin = 0;
int val;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(52);
  bool isAttached = myservo.attached();
  
  //Set up monitor
  Serial.begin(9600);
  //Serial.print("test");
  if(isAttached)
    Serial.print("Servo attached successfully.\n");
  else
    Serial.print("Servo failed to attach.\n");

  myservo.writeMicroseconds(1500);
  delay(2000);

  //Test
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  Serial.print(val);
  Serial.print("\n");
  myservo.write(val);
  delay(15);
}
