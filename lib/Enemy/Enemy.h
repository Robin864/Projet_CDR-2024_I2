#include <Arduino.h>
#include <ld06.h>

#define HERE " [" + String(__FILE__) + " at line " + String(__LINE__) + "]"
#define THROW(x) Serial.println( "Throw in " + String(__FILE__) + " at line " + String(__LINE__) + " : " + x);

const float rangeAngle = 20.41;
const int minDetection = 150; // Minimum distance pour detection robot (mm)
const int maxDetection = 500; // Maximum distance pour detection robot (mm)
const int precision = 200; // 0 -> 255;

class Enemy
{
public:
    Enemy();
    bool isDetected(float angle); // Angle in degrees
    void setDetectionArea(float angle);

private:
    LD06 captor;
};
