This project lets user control windows audio mixer through physical knobs. Desktop application is written in python.
Python code uses comtypes, pycaw, pyserial and customtkinter packages.
Hardware part of the projest is based on ESP32 microcontroller and features 4 linear poteniometers.

Desktop app features:
- User can choose COM port to which ESP32 is plugged in.
- Potentiometers 2-4 control volumes of Spotify desktop app, Discord and Google Chrome
- User can choose which app's volume is controlled by potentiometer1

ESP32 app features:
- Serial communication with python desktop app through UART and built in USB connector
- Knob position reading using 4 ADC channels
- Signal filtering by a software low-pass filter

ESP32 pinout:
Potentiometer 1 - GPIO4
Potentiometer 2 - GPIO34
Potentiometer 3 - GPIO15
Potentiometer 4 - GPIO2
