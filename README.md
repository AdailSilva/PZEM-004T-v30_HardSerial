/* 
 *   
 *  Project:          IoT Energy Meter with C/C++, Java/Spring, TypeScript/Angular and Dart/Flutter;
 *  About:            End-to-end implementation of a LoRaWAN network for monitoring electrical quantities;
 *  Version:          1.0;
 *  Backend Mote:     ATmega328P/ESP32/ESP8266/ESP8285/STM32;
 *  Radios:           RFM95w and LoRaWAN EndDevice Radioenge Module: RD49C;
 *  Sensors:          Peacefair PZEM-004T 3.0 Version TTL-RTU kWh Meter;
 *  Backend API:      Java with Framework: Spring Boot;
 *  LoRaWAN Stack:    MCCI Arduino LoRaWAN Library (LMiC: LoRaWAN-MAC-in-C) version 3.0.99;
 *  Activation mode:  Activation by Personalization (ABP) or Over-the-Air Activation (OTAA);
 *  Author:           Adail dos Santos Silva
 *  E-mail:           adail101@hotmail.com
 *  WhatsApp:         +55 89 9 9433-7661
 *  
 *  In the _serialBuffers.h tab, some changes were made to the implementation by the creator of this project,
 *  but the copyright will continue to be for: Jakub Mandula Copyright (c) 2019;
 *  All the remaining implementation is authored by the creator of the LoRaWAN Electricity Meter project.
 *  
 *  WARNINGS:
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 *  this software and associated documentation files (the “Software”), to deal in
 *  the Software without restriction, including without limitation the rights to
 *  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 *  the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 *  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 *  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 *  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *  
 */
 
# PZEM-004T v3.0
Arduino communication library for Peacefair PZEM-004T-10A and PZEM-004T-100A v3.0 Energy monitor.

***

This module is an upgraded version of the PZEM-004T with frequency and power factor measurement features, available at the usual places. It communicates using a TTL interface over a Modbus-RTU like communication protocol but is incompatible with the older [@olehs](https://github.com/olehs) library found here: [https://github.com/olehs/PZEM004T](https://github.com/olehs/PZEM004T). I would like to thank [@olehs](https://github.com/olehs) for the great library which inspired me to write this one.

#### Common issue:
Make sure the device is connected to the AC power! The 5V only power the optocouplers, not the actual chip. Also please be safe, AC is dangerous. It can cause more serious issues, such as *death*. You are responsible for your own stupidity. **So don't be stupid.**

### Manufacturer (optimistic) specifications

| Function      | Measuring range    | Resolution      | Accuracy | TODO: Realistic specifications |
|---------------|--------------------|-----------------|----------|--------------------------------|
| Voltage       | 80~260V            | 0.1V            | 0.5%     |                                |
| Current       | 0\~10A or 0\~100A*   | 0.01A or 0.02A* | 0.5%     |                                |
| Active power  | 0\~2.3kW or 0\~23kW* | 0.1W            | 0.5%     |                                |
| Active energy | 0~9999.99kWh       | 1Wh             | 0.5%     |                                |
| Frequency     | 45~65Hz            | 0.1Hz           | 0.5%     |                                |
| Power factor  | 0.00~1.00          | 0.01            | 1%       |                                |

\* Using the external current transformer instead of the built in shunt

#### Other features
  * 247 unique programmable slave addresses
    * Enables multiple slaves to use the same Serial interface
  * Over power alarm
  * Energy counter reset
  * CRC16 checksum
  * Better, but not perfect mains isolation

### Example
```c++
#include <PZEM004Tv30.h>

PZEM004Tv30 pzem(&Serial3);

void setup() {
  Serial.begin(115200);

  Serial.print("Reset Energy");
  pzem.resetEnergy();


  Serial.print("Set address to 0x42");
  pzem.setAddress(0x42);
}

void loop() {
  float volt = pzem.voltage();
  Serial.print("Voltage: ");
  Serial.print(volt);
  Serial.println("V");

  float cur = pzem.current();
  Serial.print("Current: ");
  Serial.print(cur);
  Serial.println("A");

  float powe = pzem.power();
  Serial.print("Power: ");
  Serial.print(powe);
  Serial.println("W");

  float ener = pzem.energy();
  Serial.print("Energy: ");
  Serial.print(ener,3);
  Serial.println("kWh");

  float freq = pzem.frequency();
  Serial.print("Frequency: ");
  Serial.print(freq);
  Serial.println("Hz");

  float pf = pzem.pf();
  Serial.print("PF: ");
  Serial.println(pf);

  delay(1000);
}
```
# Installation instructions
You should be able to install the library from the Library Manager in the Arduino IDE. You can also download the ZIP of this repository and install it manually. A guide on how to do that is over here: [https://www.arduino.cc/en/guide/libraries](https://www.arduino.cc/en/guide/libraries) 

***
Thank you to [@olehs](https://github.com/olehs) for inspiring this library.
