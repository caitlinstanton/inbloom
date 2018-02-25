#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

#include <Servo.h>

#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>





unsigned long StartTime = millis();

int servopin1=6;
int servopin2=7;
int servopin3=8;
Servo myservo1;
Servo myservo2;
Servo myservo3;
int servo1_on=0;
int servo2_on=0;
int servo3_on=0;


int button1;
int button2;
int button3;




// the setup function runs once when you press reset or power the board
void setup() {
    lcd.begin(16, 2);
    lcd.setRGB(255, 255, 255);
    Serial.begin(9600);

    
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(3, INPUT);


    //buzzer
    pinMode(2, OUTPUT);
  
    myservo1.attach(servopin1);
    myservo2.attach(servopin2);
    myservo3.attach(servopin3);

  
}

// the loop function runs over and over again forever
void loop() {

  lcd.noDisplay();
  lcd.display();
  unsigned long CurrentTime = millis();
  unsigned long ElapsedTime = (CurrentTime - StartTime)/1000;
  int touch_sensor = digitalRead(3);

  if (touch_sensor==LOW){
    lcd.clear();
    lcd.noDisplay();
    lcd.display();
    StartTime = CurrentTime;
    ElapsedTime=0;
    lcd.setCursor(0, 1); 
  }
  
 else if (ElapsedTime >= 15 && ElapsedTime <=17 && touch_sensor==HIGH){
    lcd.noDisplay();
    lcd.display();
    lcd.setRGB(255, 255, 0);
    tone(2, 1000,1000);
    int touch_sensor = digitalRead(3);
    lcd.setCursor(0, 1);
    lcd.print("Usage time: 15s!");

 }

 else if (ElapsedTime >= 30 && ElapsedTime <=32 && touch_sensor==HIGH){
    tone(2, 2000,2000);
    lcd.noDisplay();
    lcd.display();
    lcd.setRGB(0, 255, 0);
    delay(25);
    lcd.setCursor(0, 1);
    lcd.print("Usage time: 30s!");
 }

 else if (ElapsedTime >= 60 && ElapsedTime <=63 && touch_sensor==HIGH){
     tone(2, 3000,3000);
     delay(100);
     lcd.setRGB(255, 0, 0);
     lcd.noDisplay();
     delay(25);
     lcd.display();
     lcd.setCursor(0, 1);
     lcd.print("Usage time: 60s!");
     delay(100);
     lcd.setRGB(255, 255, 255);
 }
    
 else{
    lcd.setRGB(255, 255, 255);
    lcd.noDisplay();
    lcd.display();
    lcd.setCursor(0, 1);
    lcd.print("                 ");

 }

  button1=digitalRead(11);
  button2=digitalRead(12);
  button3=digitalRead(13);
  
  if (button1){
    servo1_on=1;
  }
  if(button2){
    servo2_on=1;
  }
  if(button3){
    servo3_on=1;
  }
  if(servo1_on==1){
    myservo1.write(179);
    servo1_on=2;
  }
  if(servo2_on==1){
    myservo2.write(179);
        servo2_on=2;
  }
  if(servo3_on==1){
    myservo3.write(179);
    servo3_on=2;
  }
}
