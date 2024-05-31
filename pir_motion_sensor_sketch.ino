int buzzer = A5;
int inputPin = A4;
int pirState = LOW;
void setup() {
  // put your setup code here, to run once:
 pinMode(buzzer, OUTPUT);
 pinMode(inputPin, OUTPUT);

 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 val = digitalRead(iputPin);
 if (val == HIGH){
 //digitalWrite(buzzer, HIGH); // for active buzzers
tone(buzzer, 1000, 200); // for passive buzzers 
 }
}
