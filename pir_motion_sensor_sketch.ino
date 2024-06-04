int buzzer = A5;
int inputPin = A4;
int pirState = LOW;

void setup() {
  // put your setup code here, to run once:
 pinMode(buzzer, OUTPUT);
 pinMode(inputPin, INPUT);

 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 pirState = digitalRead(inputPin);
 Serial.println(pirState);
 if (pirState == HIGH){
  digitalWrite(buzzer, HIGH); // for active buzzers
  //tone(buzzer, 1000, 2000); // for passive buzzers 
 }
 else {
  digitalWrite(buzzer, LOW); // for active buzzers
  //noTone(buzzer); // for passive buzzers
 }
}
