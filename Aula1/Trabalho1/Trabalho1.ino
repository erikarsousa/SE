//AULA 1: Piscar o LED a cada 1 segundo.
//Caso o botão seja pressionado o LED deve apagar.

#define LED_PIN 9
#define BUT_PIN 7

void setup () {
  pinMode(LED_PIN, OUTPUT);     // Enable pin 9 for digital output
  pinMode(BUT_PIN, INPUT);      // Enable pin 7 for digital input
}

void loop () {
  digitalWrite(LED_PIN, HIGH);  // Turn on the LED
  delay(1000);                  // Wait one second
  digitalWrite(LED_PIN, LOW);   // Turn off the LED
  delay(1000);                  // Wait one second

  int but = digitalRead(BUT_PIN);

  if (but) {
    digitalWrite(LED_PIN, HIGH);
    while (1);
  }
}
