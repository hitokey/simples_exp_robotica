void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}
void loop() {
  char c = Serial.read();
  if (c == 'S') {
    digitalWrite(9, 1);
    delay(95);
    digitalWrite(9, 0);
    //delay(3000);
  }
  if (c == 'R') {

    int valores_01 = analogRead(A0);
    int valores_02 = analogRead(A1);
    Serial.print("Valores = ");
    Serial.print(valores_01);
    Serial.print(" ");
    Serial.println(valores_02);
    Serial.print("Location = ");
    if (valores_02 < 700) {
      Serial.print(1);
    }
    else {
      Serial.print(0);
    }
    if (valores_01 < 700)
    {
      Serial.println(1);
    }
    else {
      Serial.println(0);
    }
  }
}
