// Init pin numbers we used for components
int ledPin = 9; // We used 9 because it supports analog write
int potentiometerPin = A5; // We use analog because we read values of potentiometer from 0 to 1023

void setup() {
  pinMode(ledPin, OUTPUT); // set led pin as output
  pinMode(potentiometerPin, INPUT); // set potentiometer pin as input
  Serial.begin(9600); // Init debugger
}

void loop() {
  int potentiometerValue = analogRead(potentiometerPin); // We read value from potentiometer, it's in [0, 1023] range
  int delayTime = map(potentiometerValue, 0, 1023, 100, 500); // We map the value to [100, 500] range,
  // so our minimum delay is 100 milliseconds, and maximum is 500 milliseconds
  
  Serial.print(potentiometerValue); // We log read value
  Serial.print("\t");
  Serial.print(delayTime); // And mapped value
  Serial.print("\n");

  digitalWrite(ledPin, HIGH); // We turn on the LED
  delay(delayTime); // for set amount of time
  digitalWrite(ledPin, LOW); // and then turn it off
  delay(delayTime); // for the same amount of time
}
