// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(17, OUTPUT);
  pinMode(TXLED0, OUTPUT);
  Serial.begin(9600);


}

int val = 0;
char data[100];
char buff[10];


// the loop function runs over and over again forever
void loop() {
  digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(TXLED0, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(100);                       
  digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(TXLED0, LOW);    // turn the LED off by making the voltage LOW

  delay(100);

  val = analogRead(A0);  // read the input pin
  float voltage = val / 1024.0 * 3.3;
  dtostrf(voltage, 4, 6, buff);  //4 is mininum width, 6 is precision 
  sprintf(data, "%s V", buff);

  Serial.println(data);

}
