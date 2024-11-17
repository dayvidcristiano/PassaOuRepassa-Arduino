int b1 = 4;
int b2 = 3;
int b3 = 2;
int e1 = 0, e2 = 0, e3 = 0;
int led1 = 12;
int led2 = 8;
int buzzer = 9;
int trava = 0;
unsigned long tempoAtivacao = 0;
unsigned long tempoBuzzer = 0;
bool buzzerAtivo = false;

void setup() {
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  e1 = digitalRead(b1);
  e2 = digitalRead(b2);
  e3 = digitalRead(b3);

  if ((e1 == 1) && (trava == 0)) {
    digitalWrite(led1, HIGH);
    tempoAtivacao = millis();
    trava = 1;
    buzzerAtivo = false;
  }

  if ((e2 == 1) && (trava == 0)) {
    digitalWrite(led2, HIGH);
    tempoAtivacao = millis();
    trava = 1;
    buzzerAtivo = false;
  }

  if (e3 == 1) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(buzzer, LOW);
    trava = 0;
    buzzerAtivo = false;
  }

  if (trava == 1 && (millis() - tempoAtivacao >= 13000) && !buzzerAtivo) {
    digitalWrite(buzzer, HIGH);
    tempoBuzzer = millis();
    buzzerAtivo = true;
  }

  if (buzzerAtivo && (millis() - tempoBuzzer >= 3000)) {
    digitalWrite(buzzer, LOW);
    trava = 0;
  }
}
