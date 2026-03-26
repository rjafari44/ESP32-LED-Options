# ESP32 LED Options

#### This project was derived from the IEEE Student Branch at UCI. This code consists of three modes: LED Blink, Basic Dimmer, and RGB Dimmer. Each mode has a different design needed to run. I have created my own schematics within LTspice with custom symbols, so feel free to follow them for an exact setup or change them according to your need. The LTspice files are provided in the project.

---

### Mode LED Blink:
A simple LED blinking mode which has the light flicker on and off once every second.

#### Circuit Schematic:

![Diagram](assets/Mode_Blink.jpg)

---

### Mode Basic Dimmer
This mode uses a potentiometer to control the brightness of the LED from 0% to 100%.

#### Circuit Schematic:

![Diagram](assets/Mode_Basic_Dimmer.jpg)

---

### Mode RGB Dimmer
This mode is built upon the Basic Dimmer but uses multiple potentiometers with multiple LEDs. I used a RGB Led which has multiple colors in it, but that could be simulated by using a Red, Green and Blue LED next to each other under a lens to simulate multiple colors.

#### Circuit Schematic:

![Diagram](assets/Mode_RGB_Dimmer.jpg)

---

## How to run
I ran this code on a WeAct Studio ESP32-C3 board which gave me issues with the serial monitor not working. I fixed the serial monitor issue by ensuring that USB CDC is enabled.

If using the Arduino IDE, make sure the WeAct Studio ESP32-C3 board is the correct selected one.

If running the script in CLI, it will prompt you for your board's serial port that it is connected to, so you need to find it and mention it. The serial port is usually /dev/ttyACM0 or /dev/ttyUSB0 but it could also be different. If the shell script is not executable, simply chmod it.

If you prefer a manual/edited compilation and upload, either edit my shell script or simply copy them one at a time with custom flags.

### 1. Find Connected Serial Port
#### On Linux
```bash
ls /dev/tty*
```   

#### With Arduino CLI (recommended method)
```bash
arduino-cli board list
```

### 2. Run the program in CLI
```bash
./run.sh
```