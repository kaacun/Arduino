#define SPEEKER_PIN 13
#define BUTTON_PIN 1
#define DELAY_TIME 600

int rec_val = 0;  // 現在の状態（HIGH, LOW）
int old_val = 0;  // 一つ前の状態（HIGH, LOW）
int button_flg  = 0;  // BUTTONステータス

void setup()
{
  pinMode(SPEEKER_PIN, OUTPUT);
}

void loop()
{
  if(analogRead(BUTTON_PIN) < 10){
    rec_val = HIGH;
  } else {
    rec_val = LOW;
  }
  if (rec_val == HIGH && old_val == LOW) {
    button_flg = 1 - button_flg;
    delay(10);
  }  
  old_val = rec_val;
  if (!button_flg) return;
  
  digitalWrite(SPEEKER_PIN, HIGH);
  delayMicroseconds(DELAY_TIME);
  digitalWrite(SPEEKER_PIN, LOW);
  delayMicroseconds(DELAY_TIME);
}
