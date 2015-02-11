# SimpleArduinoGroveThermometer

Arduino sketch for a digital thermometer. Temperature is displayed in celsius and fahrenheit on an LCD which has a backlight that can be toggled on and off via a button.

![Screenshot](https://raw.githubusercontent.com/kevd1337/SimpleArduinoGroveThermometer/master/img/in-action.jpg)

# Components

- 1 x [Arduino Uno R3](http://arduino.cc/en/Main/arduinoBoardUno)
- 1 x [Seeed Studio Grove Base Shield V2](http://www.seeedstudio.com/depot/base-shield-v13-p-1378.html)
- 1 x [Seeed Studio Grove Button](http://www.seeedstudio.com/depot/Grove-Button-p-766.html)
- 1 x [Seeed Studio Grove LCD RGB Backlight](http://www.seeedstudio.com/depot/Grove-LCD-RGB-Backlight-p-1643.html)
- 1 x [Seeed Studio Grove Temperature Sensor](http://www.seeedstudio.com/depot/Grove-Temperature-Sensor-p-774.html)
- 3 x [Seeed Studio Grove 4-pin cables](http://www.seeedstudio.com/depot/Grove-Universal-4-Pin-20cm-Unbuckled-Cable-5-PCs-Pack-p-749.html)
- 1 x 9V Battery (optional) 
- 1 x 9V to Barrel Jack Adapter (optional)
 
NOTE: all of the Seeed Studio Grove componenets are available in the [Grove Starter Kit v3](http://www.seeedstudio.com/wiki/Grove_-_Starter_Kit_v3)

# Layout

![Screenshot](https://raw.githubusercontent.com/kevd1337/SimpleArduinoGroveThermometer/master/img/layout.jpg)

# Prerequisites
- [Arduino IDE](http://arduino.cc/) with [Grove LCD RGB Backlight library](https://github.com/Seeed-Studio/Sketchbook_Starter_Kit_V2.0/tree/master/libraries/Grove_LCD_RGB_Backlight) installed
 
# Setup
- Plug Grove Base Shield into Arduino
- Connect Temperature Sensor module to the analog port 0 (A0) of grove shield using 4-pin grove cable
- Connect Button module to the digital port 3 (D3)  of grove shield using 4-pin grove cable
- Connect LCD RGB Backlight module to an I2C port of grove shield using 4-pin grove cable
- Compile and upload sketch to Arduino
- (optional) connect 9v battery via 9V to Barrel Jack Adapter 
