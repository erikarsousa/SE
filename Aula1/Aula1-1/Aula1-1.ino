//AULA 1: Piscar o LED a cada 1 segundo

#define LED_PIN 13

void setup () {                 // Enable pin 13 for digital output
  pinMode(LED_PIN, OUTPUT);
}

void loop () {
  digitalWrite(LED_PIN, HIGH);  // Turn on the LED
  delay(1000);                  // Wait one second
  digitalWrite(LED_PIN, LOW);   // Turn off the LED
  delay(1000);                  // Wait one second
}
