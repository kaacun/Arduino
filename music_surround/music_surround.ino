//PIN SETTINGS
#define SPEEKER_PIN 13
#define CDS_IN 0
#define BUTTON_PIN 1

//明るさレベル分割数
#define BRIGHTNESS_LEVEL 3
#define DARK 500
#define BRIGHT 1023

#define BEEP_HIGH 300
#define BEEP_LOW 500

int rec_val = 0;  // 現在の状態（HIGH, LOW）
int old_val = 0;  // 一つ前の状態（HIGH, LOW）
int button_flg  = 0;  // BUTTONステータス

void setup()
{
  pinMode(SPEEKER_PIN, OUTPUT);
//  Serial.begin(9600);
}

void loop()
{
  int beep;
  int brightness,i;
  int brightness_low, brightness_high;
  
  //ボタン状態の確認
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
  
  brightness = analogRead(0);
//  Serial.print(brightness, DEC);
//  Serial.print("\n");
  
  for(i=0;i<BRIGHTNESS_LEVEL;i++){
    brightness_low = i * (BRIGHT - DARK + 1) / BRIGHTNESS_LEVEL + DARK;
    brightness_high = (i + 1) * (BRIGHT - DARK + 1) / BRIGHTNESS_LEVEL + DARK;
    if(brightness_low < brightness && brightness < brightness_high){
      beep = BEEP_LOW - i * (BEEP_LOW - BEEP_HIGH)/2;
      digitalWrite(SPEEKER_PIN, HIGH);
      delayMicroseconds(beep);
      digitalWrite(SPEEKER_PIN, LOW);
      delayMicroseconds(beep);
    }
  }
}
