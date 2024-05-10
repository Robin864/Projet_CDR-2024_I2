#pragma once

#include <AccelStepper.h>
#include <stdlib.h>
#include <math.h>

#include "UniBoardV4Def.h"
#include "Position.h"
#include "Enemy.h"

const double ACCEL = 200*2.5; // Temp
const double SPEED = 400*2.5; // Temp
const int uStep = 8; // Microstepping
const float wtx = 1.4705; // Wheel turn compensation coefficient
const float wty = 1.4705 + 0.26; // Wheel turn compensation coefficient
//const float wty = 1.75  + 0.175*3.0; // Wheel turn compensation coefficient

class Movement
{
private:
    Enemy enemy;
    AccelStepper fl, fr, rl, rr; // frontleft, frontright, rearleft, rearright
    bool calibrated;
    float halfCicle;

public:
    Movement();
    void setup();
    void init(char team);
    void moveTo(float angle, float distance);
    void moveToXY(float x, float y);
    bool run();
    void moveToAndRun(float angle, float distance);
    void stop();
    void turnOver(float angle);
    bool isArrived();
    void moveToXYAndRun(float x, float y);

//Singleton
public:
    static inline Movement& instance(){return m_instance;}
    Movement(const Movement&) = delete;
    Movement(Movement&&) = delete;
    Movement& operator=(const Movement&) = delete;
    Movement& operator=(Movement&&) = delete;
private:
    static Movement m_instance;

};

extern Movement& move;
