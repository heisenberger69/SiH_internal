#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int gear = 0;
int up_pin = 1;
int down_pin = 2;
int solenoid_up = 4;
int solenoid_down = 3;

void setup() {
  lcd.begin(16, 2);
  pinMode(up_pin, INPUT_PULLUP);  
  pinMode(down_pin, INPUT_PULLUP); 
  pinMode(solenoid_up,OUTPUT);
  pinMode(solenoid_down,OUTPUT);
}

void loop() 
  {
  int a = digitalRead(up_pin);
  int b = digitalRead(down_pin);

  lcd.clear();
  digitalWrite(solenoid_up,LOW);
  digitalWrite(solenoid_down,LOW);
  delay(500);
 
 

  if (a == LOW && gear < 4) {
    gear++;
    digitalWrite(solenoid_up,HIGH);
    
  }

  if (b == LOW && gear > 0) {
    gear--;
    digitalWrite(solenoid_down,HIGH);
  }


  lcd.setCursor(0, 0); 
  lcd.print(gear);

  
  delay(1500);
}
