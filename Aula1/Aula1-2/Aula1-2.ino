//AULA 1: Fazer o LED acompanhar o estado do botão

#define LED_PIN 9
#define BUT_PIN 7

void setup () {
  pinMode(LED_PIN, OUTPUT);     // Enable pin 9 for digital output
  pinMode(BUT_PIN, INPUT);      // Enable pin 7 for digital input
}

void loop () {
  int but = digitalRead(BUT_PIN); // Read button state
  digitalWrite(LED_PIN, but);     // Copy state to LED
}
