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

/********************************************************************
 _____              __ _                       _   _             
/  __ \            / _(_)                     | | (_)            
| /  \/ ___  _ __ | |_ _  __ _ _   _ _ __ __ _| |_ _  ___  _ __  
| |    / _ \| '_ \|  _| |/ _` | | | | '__/ _` | __| |/ _ \| '_ \ 
| \__/\ (_) | | | | | | | (_| | |_| | | | (_| | |_| | (_) | | | |
 \____/\___/|_| |_|_| |_|\__, |\__,_|_|  \__,_|\__|_|\___/|_| |_|
                          __/ |                                  
                         |___/                                   
********************************************************************/

/* Includes */
#include "PZEM004Tv30.h"

/* Instances */
/*
 *  Hardware Serial2 is only available on certain boards.  
 */
PZEM004Tv30 pzemSerial1(&Serial2, 0x01);
PZEM004Tv30 pzemSerial2(&Serial2, 0x02);
PZEM004Tv30 pzemSerial3(&Serial2, 0x03);

/*****************************
 _____           _      
/  __ \         | |     
| /  \/ ___   __| | ___ 
| |    / _ \ / _` |/ _ \
| \__/\ (_) | (_| |  __/
 \____/\___/ \__,_|\___|
*****************************/

/*****************************
 _____      _               
/  ___|    | |              
\ `--.  ___| |_ _   _ _ __  
 `--. \/ _ \ __| | | | '_ \ 
/\__/ /  __/ |_| |_| | |_) |
\____/ \___|\__|\__,_| .__/ 
                     | |    
                     |_|    
******************************/

void setup()
{
    Serial.begin(9600);
}

/*****************************
 _                       
| |                      
| |     ___   ___  _ __  
| |    / _ \ / _ \| '_ \ 
| |___| (_) | (_) | |_) |
\_____/\___/ \___/| .__/ 
                  | |    
                  |_|    
*****************************/

void loop()
{
    Serial.println();
    Serial.println(F("############ PZEM_1 ############"));
    float voltage = pzemSerial1.voltage();
    if (!isnan(voltage))
    {
        Serial.print(F("Voltage       : "));
        Serial.print(voltage);
        Serial.println(" Volts");
    }
    else
    {
        Serial.println(F("Error reading voltage"));
    }

    float current = pzemSerial1.current();
    if (!isnan(current))
    {
        Serial.print(F("Current       : "));
        Serial.print(current);
        Serial.println(F("   Amperes"));
    }
    else
    {
        Serial.println(F("Error reading current"));
    }

    float power = pzemSerial1.power();
    if (!isnan(power))
    {
        Serial.print(F("Power         : "));
        Serial.print(power);
        Serial.println(F("   Watts"));
    }
    else
    {
        Serial.println(F("Error reading power"));
    }

    float energy = pzemSerial1.energy();
    if (!isnan(energy))
    {
        Serial.print(F("Energy        : "));
        Serial.print(energy, 3);
        Serial.println(F("  kWh"));
    }
    else
    {
        Serial.println(F("Error reading energy"));
    }

    float frequency = pzemSerial1.frequency();
    if (!isnan(frequency))
    {
        Serial.print(F("Frequency     : "));
        Serial.print(frequency, 1);
        Serial.println(F("   Hz"));
    }
    else
    {
        Serial.println(F("Error reading frequency"));
    }

    float pf = pzemSerial1.pf();
    if (!isnan(pf))
    {
        Serial.print(F("Power Factor  : "));
        Serial.println(pf);
    }
    else
    {
        Serial.println(F("Error reading power factor"));
    }

    Serial.println();
    Serial.println();
    
    Serial.println(F("############ PZEM_2 ############"));

    voltage = pzemSerial2.voltage();
    if (!isnan(voltage))
    {
        Serial.print(F("Voltage       : "));
        Serial.print(voltage);
        Serial.println(" Volts");
    }
    else
    {
        Serial.println(F("Error reading voltage"));
    }

    current = pzemSerial2.current();
    if (!isnan(current))
    {
        Serial.print(F("Current       : "));
        Serial.print(current);
        Serial.println(F("   Amperes"));
    }
    else
    {
        Serial.println(F("Error reading current"));
    }

    power = pzemSerial2.power();
    if (!isnan(power))
    {
        Serial.print(F("Power         : "));
        Serial.print(power);
        Serial.println(F("   Watts"));
    }
    else
    {
        Serial.println(F("Error reading power"));
    }

    energy = pzemSerial2.energy();
    if (!isnan(energy))
    {
        Serial.print(F("Energy        : "));
        Serial.print(energy, 3);
        Serial.println(F("  kWh"));
    }
    else
    {
        Serial.println(F("Error reading energy"));
    }

    frequency = pzemSerial2.frequency();
    if (!isnan(frequency))
    {
        Serial.print(F("Frequency     : "));
        Serial.print(frequency, 1);
        Serial.println(F("   Hz"));
    }
    else
    {
        Serial.println(F("Error reading frequency"));
    }

    pf = pzemSerial2.pf();
    if (!isnan(pf))
    {
        Serial.print(F("Power Factor  : "));
        Serial.println(pf);
    }
    else
    {
        Serial.println(F("Error reading power factor"));
    }

    Serial.println();
    Serial.println();
    
    Serial.println(F("############ PZEM_3 ############"));

    voltage = pzemSerial3.voltage();
    if (!isnan(voltage))
    {
        Serial.print(F("Voltage       : "));
        Serial.print(voltage);
        Serial.println(" Volts");
    }
    else
    {
        Serial.println(F("Error reading voltage"));
    }

    current = pzemSerial3.current();
    if (!isnan(current))
    {
        Serial.print(F("Current       : "));
        Serial.print(current);
        Serial.println(F("   Amperes"));
    }
    else
    {
        Serial.println(F("Error reading current"));
    }

    power = pzemSerial3.power();
    if (!isnan(power))
    {
        Serial.print(F("Power         : "));
        Serial.print(power);
        Serial.println(F("   Watts"));
    }
    else
    {
        Serial.println(F("Error reading power"));
    }

    energy = pzemSerial3.energy();
    if (!isnan(energy))
    {
        Serial.print(F("Energy        : "));
        Serial.print(energy, 3);
        Serial.println(F("  kWh"));
    }
    else
    {
        Serial.println(F("Error reading energy"));
    }

    frequency = pzemSerial3.frequency();
    if (!isnan(frequency))
    {
        Serial.print(F("Frequency     : "));
        Serial.print(frequency, 1);
        Serial.println(F("   Hz"));
    }
    else
    {
        Serial.println(F("Error reading frequency"));
    }

    pf = pzemSerial3.pf();
    if (!isnan(pf))
    {
        Serial.print(F("Power Factor  : "));
        Serial.println(pf);
    }
    else
    {
        Serial.println(F("Error reading power factor"));
    }

    Serial.println();
    delay(2000);
}
