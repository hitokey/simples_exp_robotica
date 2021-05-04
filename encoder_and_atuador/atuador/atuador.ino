char CS;
char POS;
char read_motor() {
  int valores_01 = analogRead(A0);
  int valores_02 = analogRead(A1);
  int pros_0 = 0;
  int pros_1 = 0;
  //Serial.print("Valores = ");
  //Serial.print(valores_01);
  //Serial.print(" ");
  //Serial.println(valores_02);
  //Serial.print("Location = ");
  Serial.print("Bit Encoder: ");
  if (valores_02 < 700) {
    Serial.print(1);
    pros_1 = 1;
  }
  else {
    Serial.print(0);
    pros_1 = 0;
  }
  if (valores_01 < 700)
  {
    Serial.print(1);
    pros_0 = 1;
  }
  else {
    Serial.print(0);
    pros_0 = 0;
  }
  if ((pros_0 == 0) && (pros_1 == 0)) {
    Serial.print(" Quard: ");
    Serial.println('A');
    return 'A';
  }
  if ((pros_0 == 1) && (pros_1 == 0)) {
    Serial.print(" Quard: ");
    Serial.println('B');
    return 'B';
  }
  if ((pros_0 == 0) && (pros_1 == 1)) {
    Serial.print(" Quard: ");
    Serial.println('C');
    return 'C';
  }
  if ((pros_0 == 1) && (pros_1 == 1)) {
    Serial.print(" Quard: ");
    Serial.println('D');
    return 'D';
  }
}

char rodar(char p) {
  digitalWrite(9, 1);
  delay(95);
  digitalWrite(9, 0);
  delay(200);
  p = read_motor();

  return p;
  
}

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  CS = read_motor();
  POS = read_motor();
}
void loop() {
  char p;
  CS = read_motor();
  delay(500);
  if (Serial.available() > 0) {
    p = Serial.read();
    if (p == 'A' || p == 'B' || p == 'C' || p == 'D'){
      POS = p;
    }
  }
  if (CS != POS){
    CS = rodar(CS);
  }
  //Serial.println(POS);
  //Serial.println(CS);
}
