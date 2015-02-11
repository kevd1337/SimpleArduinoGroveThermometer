/*
 Simple_Backlit_Thermometer_Sketch.ino
 
 Author: Kevin Dela Rosa
 2015-02-11
 
 Arduino sketch for a digital thermometer. Temperature is displayed in F & C on an LCD which has a backlight that can be toggled on and off via a button.
 
 Components:
 * 1 x Arduino Uno R3 : http://arduino.cc/en/Main/arduinoBoardUno
 * 1 x Seeed Studio Grove Base Shield V2 : http://www.seeedstudio.com/depot/base-shield-v13-p-1378.html
 * 1 x Seeed Studio Grove Button : http://www.seeedstudio.com/depot/Grove-Button-p-766.html
 * 1 x Seeed Studio Grove LCD RGB Backlight : http://www.seeedstudio.com/depot/Grove-LCD-RGB-Backlight-p-1643.html
 * 1 x Seeed Studio Grove Temperature Sensor : http://www.seeedstudio.com/depot/Grove-Temperature-Sensor-p-774.html
 * 3 x Seeed Studio Grove 4-pin cables : http://www.seeedstudio.com/depot/Grove-Universal-4-Pin-20cm-Unbuckled-Cable-5-PCs-Pack-p-749.html
 * 1 x 9V Battery (optional) 
 * 1 x 9V to Barrel Jack Adapter (optional)
 
 NOTE: all of the Seeed Studio Grove componenets are available in the Grove Starter Kit v3 - http://www.seeedstudio.com/wiki/Grove_-_Starter_Kit_v3
 
 Prerequisites:
 * Arduino IDE with Grove LCD RGB Backlight library installed ( https://github.com/Seeed-Studio/Sketchbook_Starter_Kit_V2.0/tree/master/libraries/Grove_LCD_RGB_Backlight )
 
 Setup:
 1) Plug Grove Base Shield into Arduino
 2) Connect Temperature Sensor module to the analog port 0 (A0) of grove shield using 4-pin grove cable
 3) Connect Button module to the digital port 3 (D3)  of grove shield using 4-pin grove cable
 4) Connect LCD RGB Backlight module to an I2C port of grove shield using 4-pin grove cable
 5) Compile and upload sketch to Arduino
 6) (optional) connect 9v batter via 9V to Barrel Jack Adapter 
*/

#include <Wire.h>
#include "rgb_lcd.h"

// LCD
rgb_lcd lcd;

// RGB color for LCD when backlit button activated (yellow)
const int LCD_DISPLAY_COLOR_R = 255;
const int LCD_DISPLAY_COLOR_G = 165;
const int LCD_DISPLAY_COLOR_B = 0;

// Pin of Button (D3)
const int PIN_BUTTON = 3;    

// Pin of Temperature sensor
const int PIN_TEMPERATURE_SENSOR = A0;     

// B value of the thermistor, used in temperature calcuation
const int B = 3975;

// Sleep time in loop
const int SLEEP_TIME_MS = 400;

// flag for denoting whether "backlight" on LCD is activated
boolean backlit;

/*
 * Setup LCD and Button
 */
void setup() {
    // set up the LCD's number of columns and rows
    lcd.begin(16, 2);
    
    // First line of LCD display
    lcd.print("Temperature:");
    
    // Display "backlight" is off by default
    lcd.setRGB(0, 0, 0);
    backlit = false;
    
    // Setup button
    pinMode(PIN_BUTTON, INPUT);
}

/*
 * Toggles "backlight" state of LCD
 */
void toggleBacklightState() {
  if(backlit) {
    // Turn lights off
    lcd.setRGB(0,0,0);
  } else {
    // Turn lights on
    lcd.setRGB(LCD_DISPLAY_COLOR_R, LCD_DISPLAY_COLOR_G, LCD_DISPLAY_COLOR_B);    
  }
  
  backlit = !backlit;
}

/* 
 * Entry point of program
 */
void loop() {
    // Check if button was pressed, if so toggle backlight on LCD
    if(digitalRead(PIN_BUTTON)) {  
       toggleBacklightState();
    }
    
    // Read analog value of temperatur sensor, calculate resistance, and temperature in C and F
    int val = analogRead(PIN_TEMPERATURE_SENSOR);
    float resistance=(float)(1023-val)*10000/val;
    float celsius=1/(log(resistance/10000)/B+1/298.15)-273.15;
    float fahrenheit=celsius*9.0/5.0+32;

    // Update display with latest temperature reading
    lcd.setCursor(0, 1);
    lcd.print(celsius);
    lcd.print((char)223); // degree character
    lcd.print("C ");
    lcd.print(fahrenheit);
    lcd.print((char)223);
    lcd.print("F ");
    
    // Sleep
    delay(SLEEP_TIME_MS);
}

