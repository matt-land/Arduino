#include <LiquidCrystal.h>
#include <stdlib.h>
int RS = 8;
int RW = 11;
int Enable = 9;
LiquidCrystal lcd(RS, RW, Enable, 4, 5, 6, 7);


int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}


void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}

void loop() {
  //;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  int number = millis() / 1000;
  int digits = numDigits(number);
  int pos = rand() % (16 - digits) - 1;
  int row = rand() % 2 - 0;
  delay(1000);
  lcd.clear();
  lcd.setCursor(pos, row);
  // print the number of seconds since reset:
   
  lcd.print( number);
}

