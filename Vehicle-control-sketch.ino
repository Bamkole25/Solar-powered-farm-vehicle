/**Code written by BAMKOLE ADEBOYE
 * Date: 19/August/2022
**/
#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(A0,A1);  // (Rx,Tx  > Tx,Rx)
String voice;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor(4);

int i=100;
int x=130;

#define echoPin A2
#define trigPin A3
long duration;
float distance;

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
 mySerial.begin(9600);
 motor.setSpeed(i);
 motor1.setSpeed(i);
 motor2.setSpeed(i);
 motor.run(RELEASE);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  //Serial.println(distance);
 if (mySerial.available()>0){ //Check if there is an available byte to read
 voice="";
 delay(2); //Delay added to make thing stable

 
 voice = mySerial.readString(); //Conduct a serial read
 delay(2);
 Serial.println(voice);

 if(voice == "turn left" or voice == "LS") {
  left();
  }
 else if(voice == "turn right" or voice == "RS") {
 right();
 }
 else if(voice == "move backward" or voice == "BS"){
  backward();
 }
 else if(voice == "stop"){
  Stop();
 }
 }
 else if(voice == "move forward" or voice == "FS"){
  if(distance <19){
    Stop();
  }
  else
  forward();
 }
 
}

void forward(){
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  voice = mySerial.readString();
  if(distance <19 or voice == "stop"){
    Stop();
    voice=""; 
  }
  else{
  motor.run(FORWARD);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(2000);
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  }
}

void backward(){
  motor.run(BACKWARD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(1500);
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void left(){
  motor.setSpeed(x);
  motor1.setSpeed(x);
  //motor2.setSpeed(x);
  motor.run(FORWARD);
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  delay(2000);
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(2000); 
}

void right(){
  motor.setSpeed(x);
  //motor1.setSpeed(x);
  motor2.setSpeed(x);
  motor.run(FORWARD);
  motor2.run(BACKWARD);
  motor1.run(RELEASE);
  delay(2000);
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(2000);
}

void Stop(){
    motor.run(RELEASE);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
}
