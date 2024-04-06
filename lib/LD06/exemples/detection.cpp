#include <Arduino.h>
#include "ld06.h"

LD06 ld06(Serial1);

/*
// ld06 constructor with pwm pin
#define LD06PWMPIN 1             // Lidar PWM pin, by default it is not needed.
LD06 ld06(Serial1, LD06PWMPIN);  // ld06 constructor with hardware serial and pwm pin.
*/

void setup() {
    pinMode(21, INPUT);
    Serial.begin(115200);
    Serial1.begin(230400,SERIAL_8N1,10);
    ld06.init();

    // PWM is disabled by default but can be used to adjust configuration

}

void loop() {
    if (ld06.readScan()) {             // Read lidar packets and return true when a new full 360° scan is available
        ld06.printScanTeleplot(Serial);  // Print full scan using teleplot format (check :https://teleplot.fr/)
        
        // Other displays examples and getters
        ld06.printScanCSV(Serial);  // Print scan in csv format

        if (ld06.isNewScan()) {     // Even if fullScan is disabled you can know when last data chunk have a loop closure
            Serial.println("New 360 deg scan");
        }

        Serial.println(ld06.getSpeed());        // Show the lidar speed in degrees ° / second
        Serial.println(ld06.getAngleStep());    // Show the angle step resolution in degree
        uint16_t n = ld06.getNbPointsInScan();  // Give the number of points in the scan, can be usefull with filtering to tell if there are abstacles around the lidar
        Serial.println(String() + ld06.getNbPointsInScan() + " lidar points in the defined range");
        
        for (uint16_t i = 0; i < n; i++) {
            Serial.println(String() + ld06.getPoints(i)->angle + "," + ld06.getPoints(i)->distance + ";");  // example to show how to extract data. ->x, ->y and ->intensity are also available.
        }
    }
}