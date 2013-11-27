/**
 *Reading button presses on a combo LDC/button shield
 **/
#include <LiquidCrystal.h>

const int RS = 8;
const int RW = 11;
const int Enable = 9;
LiquidCrystal lcd(RS, RW, Enable, 4, 5, 6, 7);

String newest = "";
String last = "";

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Button Tests");
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  newest = keyPress();
  delay(150);
  if (newest != last) {
    lcd.setCursor(0,1);
  
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print(newest);
    last = newest;
  }
}

String keyPress() 
{
  int value = floor(analogRead(0)/10);
  switch (value) {
  case 101:
  case 100:
    return "none";
  case 73:
  case 72:
    return "select";
  case 49:
  case 48:
    return "left";
  case 32:
  case 31:
    return "down";
  case 14:
  case 13:
    return "up";
  case 1:
  case 0:
    return "right";

  default:
    return String(value);
  }
}

