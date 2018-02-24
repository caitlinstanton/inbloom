
#include <Servo.h>


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
//int button4;



// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  int servo1_on=0;
int servo2_on=0;
int servo3_on=0;
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);

//buzzer
pinMode(2, OUTPUT);
  
  myservo1.attach(servopin1);
  myservo2.attach(servopin2);
  myservo3.attach(servopin3);
 
}

// the loop function runs over and over again forever
void loop() {
 unsigned long CurrentTime = millis();
 unsigned long ElapsedTime = (CurrentTime - StartTime)/1000;

  int touch_sensor = digitalRead(3);

  if (touch_sensor==LOW){
    StartTime = CurrentTime;
    ElapsedTime=0;
    
  }
 else if (ElapsedTime >= 15 && ElapsedTime <=16 && touch_sensor==HIGH){
    tone(2, 1000,1000);
   digitalWrite(4, LOW);
 }
 else if (ElapsedTime >= 30 && ElapsedTime <=32 && touch_sensor==HIGH){
    tone(2, 2000,2000);
    digitalWrite(4, LOW);
 }
 else if (ElapsedTime >= 60 && ElapsedTime <=63 && touch_sensor==HIGH){
    tone(2, 3000,3000);
    digitalWrite(4, LOW);
 }
 else{
   digitalWrite(4, HIGH);
 }
    // myservo.write(0);
  button1=digitalRead(11);
  button2=digitalRead(12);
  button3=digitalRead(13);


 // button4=digitalRead(10);
  
  
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
    myservo1.write(90);
    servo1_on=2;
  }
  if(servo2_on==1){
    myservo2.write(90);
        servo2_on=2;
  }
  if(servo3_on==1){
    myservo3.write(90);
    servo3_on=2;
  }
//    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
                     // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);    
  
  //else{
    //  myservo1.write(0);
   //  digitalWrite(led, LOW); 
     // wait for a second
 //}
}
