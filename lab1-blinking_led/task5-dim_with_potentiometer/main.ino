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
  int potentiometerValueMapped = map(potentiometerValue, 0, 1023, 0, 255); // We map the value to [0, 255] range
                                                                           //because analog output is 8-bit
  Serial.print(potentiometerValue); // We log read value
  Serial.print("\t"); // We make this so it's prettier
  Serial.print(potentiometerValueMapped); // And mapped value
  Serial.print("\n");
  analogWrite(ledPin, potentiometerValueMapped); // We write mapped value to led pin so we can dim it
}
