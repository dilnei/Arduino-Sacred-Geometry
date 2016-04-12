/***************************************************
  This is an example of how to create the flower of 
  life in a Display Lcd Tft 1,44 128x128 Spi Nokia 
  Arduino Pic.
  Written by Dilnei Cunha.  
 ****************************************************/

#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

// Color definitions
//#define BLACK   0x0000 not necessary
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#define __CS 10
#define __DC 9

TFT_ILI9163C display = TFT_ILI9163C(__CS, 8, __DC);

void setup(void) {
  display.begin();
}

void loop() {
  // for each row the number of character is 21 characters in display 128x128 SPI.
  testfillrects(BLUE, YELLOW);
  delay(5000);

  createFlowerOfLife(0);
  delay(2000);  
}

void testfillrects(uint16_t color1, uint16_t color2) {
  display.clearScreen();
  for (int16_t x=display.height()-1; x > 6; x-=6) {
    display.fillRect((display.width()-1)/2 -x/2, (display.height()-1)/2 -x/2 , x, x, color1);
    display.drawRect((display.width()-1)/2 -x/2, (display.height()-1)/2 -x/2 , x, x, color2);
  }
}

void createFlowerOfLife(bool fill){
  display.clearScreen();
  display.setCursor(12,0);
  display.setTextColor(GREEN);
  display.print("Geometria Sagrada");
  display.setCursor(0,15);
  display.print("    Flor da vida!");
  delay(1000);
  

  uint8_t k,c;
  uint8_t x = 0;
  uint8_t y = 0;
  uint8_t r = 0;
  boolean pass = false;
  for (k = 0; k < display.height(); k++) {
    for (c = 0; c < display.height()/2; c++) {
      if(x == display.width()/2 && y == display.width()/2){
        x = display.width()/2 + 12; 
        y = display.height()/2; 
        r = 12;
        display.drawPixel(x, y, GREEN);
      } else if (x == display.width()/2 + 12 && y == display.height()/2){
        x = display.width()/2 + 6; 
        y = display.height()/2 - 11; 
        r = 12;
        display.drawPixel(x, y, GREEN); 
      } else if (x == display.width()/2 + 6 && y == display.height()/2 - 11){
        x = display.width()/2 - 6; 
        y = display.height()/2 - 11; 
        r = 12;
        display.drawPixel(x, y, GREEN);
      } else if (x == display.width()/2 - 6 && y == display.height()/2 - 11){
        x = display.width()/2 - 12; 
        y = display.height()/2; 
        r = 12;
        display.drawPixel(x, y, GREEN); 
     } else if (x == display.width()/2 - 12 && y == display.height()/2){
        x = display.width()/2 - 6; 
        y = display.height()/2 + 11; 
        r = 12;
        display.drawPixel(x, y, GREEN);
      } else if (x == display.width()/2 - 6 && y == display.height()/2 + 11){
        x = display.width()/2 + 6; 
        y = display.height()/2 + 11; 
        r = 12;
        display.drawPixel(x, y, GREEN);
        pass = true;
      } else if (pass){
        x = display.width()/2; 
        y = display.height()/2; 
        r = 25;
        display.drawPixel(x, y, GREEN);
      } else {
        x = display.width()/2; 
        y = display.height()/2; 
        r = 12;
        display.drawPixel(x, y, GREEN);
        Serial.println("x tem valor: " + x);
      }

//      if (x - r <  0) r = x;
//      if (x + r > (display.width()-1)) r = (display.width() - 1) - x;
//      if (y - r <  0) r = y;
//      if (y + r > (display.height()-1)) r = (display.height() - 1) - y;
      if (fill){
        display.fillCircle(x, y, r,random(0x0010,0xFFFF));
      } 
      else {
//        Here you can change White to colorfull
//        display.drawCircle(x, y, r,random(0x0010,0xFFFF));
        display.drawCircle(x, y, r,WHITE);
      }
        delay(1000);  
    }
  }
}

