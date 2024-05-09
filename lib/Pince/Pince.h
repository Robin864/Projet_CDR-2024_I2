#pragma once
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <UniBoardV4Def.h>
#include <Wire.h>



#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// Define Servos Pins
const int SERVO_LB = 4; // Servo Left Base
const int SERVO_LP = 5; // Servo Left Pliers
const int SERVO_RB = 6; // Servo Right Base
const int SERVO_RP = 7; // Servo Right Pliers


class Pince
{
private:
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

    void opening(int side);
    void close(int side);
    void up(int side);
    void down(int side);

public:
    Pince(){};
    bool isGrabed[2] = {false, false}; //[0-Grab Right, 1-Grab Left]
    // bool isMoving[4] = {false, false, false, false}; //[0-LB, 1-LP, 2-RB, 3-RP]

    void setup();
    void grab(int side);
    void ungrab(int side);

//Singleton
public:
    static inline Pince& instance(){return m_instance;}
    Pince(const Pince&) = delete;
    Pince(Pince&&) = delete;
    Pince& operator=(const Pince&) = delete;
    Pince& operator=(Pince&&) = delete;
private:
    static Pince m_instance;
};


extern Pince& pince;