void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  analogWrite(5, 255);
  delay(1000);
  analogWrite(5, 180);
}
