int led_pins[] = {9,10,11};

void setup()
{
  int i;
  for(i=0;i<3;i++){
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop()
{
  int i;
  for(i=0;i<3;i++){
    digitalWrite(led_pins[i], LOW);
    delay(500);
    digitalWrite(led_ping[i], HIGH);
    delay(500);
  }
}
