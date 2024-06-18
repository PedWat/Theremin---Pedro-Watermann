#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 8

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  
  distance = (duration / 2) / 29.1;
  
  // Mapeamento da distância para frequência do tom
  int frequency = map(distance, 0, 20, 200, 1500); // Ajuste os valores conforme necessário
  
  if (distance > 0 && distance <= 20) {
    tone(BUZZER_PIN, frequency); // Produz um tom proporcional à distância medida
  } else {
    noTone(BUZZER_PIN); // Desliga o buzzer se a mão estiver longe
  }
  
  delay(50); // Atraso para evitar leituras muito rápidas
}
