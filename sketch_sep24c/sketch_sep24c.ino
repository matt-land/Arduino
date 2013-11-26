#include <LiquidCrystal.h>
#include <stdlib.h>
const int width = 16;
const int height = 2;
const int RS = 8;
const int RW = 11;
const int Enable = 9;
LiquidCrystal lcd(RS, RW, Enable, 4, 5, 6, 7);


//setup the LCD display
int myLcd [width][height];


void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(width, height);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      //assign a random value to each display position
      myLcd[i][j] = rand() % 10; 
    }  
  }
}

int updateValue(int& value) {
  if (value < 8) {
    return value++;
  } else {
    return value = 0;
  }
}

void updateLcdDisplay()
{
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      updateValue(myLcd[i][j]);

      lcd.setCursor(i, j);
      lcd.print(updateValue(myLcd[i][j]));
      delay(70);
    }
  }
}
  
void loop() 
{
  updateLcdDisplay();
  
}

