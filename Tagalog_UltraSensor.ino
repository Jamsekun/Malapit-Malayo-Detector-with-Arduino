//code is in tagalog version

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin =9;
const int echoPin = 10;

long duration;
int distanceCm, distanceInch;


void sobrangLapit() {


}


void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);

 // lcdi2c display code below
 if (distanceCm > 200) {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Distance: ");
   lcd.print(distanceCm);
   lcd.print(" cm");
   delay(10);
   lcd.setCursor(0,1);
   lcd.print("Malayo");
   delay(1000);
 } 
 else if (distanceCm > 70) {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Distance: ");
   lcd.print(distanceCm);
   lcd.print(" cm");
   delay(10);
   lcd.setCursor(0,1);
   lcd.print("Medyo abot");
   delay(1000);
 }
 else {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Distance: ");
   lcd.print(distanceCm);
   lcd.print(" cm");
   delay(10);
   lcd.setCursor(0,1);
   lcd.print("Malapit!");
   delay(1000);
 }


}
