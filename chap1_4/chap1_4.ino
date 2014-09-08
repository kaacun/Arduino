#define LED_PIN1 9
#define LED_PIN2 10
void setup()
{
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop()
{
  analogWrite(LED_PIN1, 255);
  analogWrite(LED_PIN2, 40);
}
