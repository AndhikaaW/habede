#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int col = 16;
const int row = 2;

LiquidCrystal_I2C lcd(0x27, col, row);

int position = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(position, 0);
  lcd.print("semoga panjang umur sehat selalu"); 

  position += 1; 
  
  if(position >= col){
    lcd.scrollDisplayLeft();
  }
  delay(300);
}
