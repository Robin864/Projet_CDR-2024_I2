#include "Movement.h"

#define HOME_OFFSET 250

Movement Movement::m_instance; 
Movement& move = Movement::instance();

Movement::Movement()
{
    fl = AccelStepper(AccelStepper::DRIVER, PIN::Steppers::STEP3, PIN::Steppers::DIR3); // AVG - 1
    fl.setPinsInverted(false);
    fr = AccelStepper(AccelStepper::DRIVER, PIN::Steppers::STEP1, PIN::Steppers::DIR1); // AVD - 2
    fr.setPinsInverted(true);
    rl = AccelStepper(AccelStepper::DRIVER, PIN::Steppers::STEP4, PIN::Steppers::DIR4); // ARG - 3
    rl.setPinsInverted(true);
    rr = AccelStepper(AccelStepper::DRIVER, PIN::Steppers::STEP2, PIN::Steppers::DIR2); // ARD - 4
    rr.setPinsInverted(false);
}

void Movement::setup() // Setup steppers caracteristics
{
    // Set default acceleration
    fl.setAcceleration(ACCEL);
    fr.setAcceleration(ACCEL);
    rl.setAcceleration(ACCEL);
    rr.setAcceleration(ACCEL);

    // Set default speed
    fl.setMaxSpeed(SPEED);
    fr.setMaxSpeed(SPEED);
    rl.setMaxSpeed(SPEED);
    rr.setMaxSpeed(SPEED);    
}

void Movement::init(char team) // Set the initial bot's position
{
    moveToAndRun(0, 2000); // Stick the bot to the wall
    moveToAndRun(0, HOME_OFFSET); // Put back the bot in 250, 250
    moveToAndRun(270, 2000);
    moveToAndRun(270, HOME_OFFSET);

    calibrated = true;
}

void Movement::moveTo(float angle, float distance) // Angle in rad, distance in mm
{

    float distanceX = cos(angle) * distance * wtx;
    float distanceY = sin(angle) * distance * wty;

    distance = sqrt(distanceX * distanceX + distanceY * distanceY);
    angle = atan2(distanceY, distanceX);

    // Steps per steppers
    float stepsFL = sin(angle + PI/4) * distance * uStep;
    float stepsFR = cos(angle + PI/4) * distance * uStep;
    float stepsRL = -sin(angle - PI/4) * distance * uStep;
    float stepsRR = cos(angle - PI/4) * distance * uStep;

    // Absolute values
    float absStepsFL = abs(stepsFL);
    float absStepsFR = abs(stepsFR);
    float absStepsRL = abs(stepsRL);
    float absStepsRR = abs(stepsRR);

    // Determine biggest distance
    float maxSteps = max(max(absStepsFL, absStepsFR), max(absStepsRL, absStepsRR));

    // Scalers
    float scalerFL = absStepsFL / maxSteps;
    float scalerFR = absStepsFR / maxSteps;
    float scalerRL = absStepsRL / maxSteps;
    float scalerRR = absStepsRR / maxSteps;

    // Determine each speed
    float speedFL = SPEED * scalerFL * uStep;
    float speedFR = SPEED * scalerFR * uStep;
    float speedRL = SPEED * scalerRL * uStep;
    float speedRR = SPEED * scalerRR * uStep;

    // Determine each acceleration
    float accelFL = ACCEL * scalerFL * uStep;
    float accelFR = ACCEL * scalerFR * uStep;
    float accelRL = ACCEL * scalerRL * uStep;
    float accelRR = ACCEL * scalerRR * uStep;

    // Set speeds
    fl.setMaxSpeed(speedFL);
    fr.setMaxSpeed(speedFR);
    rl.setMaxSpeed(speedRL);
    rr.setMaxSpeed(speedRR);

    // Set accelerations
    fl.setAcceleration(accelFL);
    fr.setAcceleration(accelFR);
    rl.setAcceleration(accelRL);
    rr.setAcceleration(accelRR);

    // Reset stepper position
    fl.setCurrentPosition(0);
    fr.setCurrentPosition(0);
    rl.setCurrentPosition(0);
    rr.setCurrentPosition(0);

    // Move the robot
    fl.move(stepsFL);
    fr.move(stepsFR);
    rl.move(stepsRL);
    rr.move(stepsRR);
}

void Movement::moveToXY(float x, float y){
    float angle = atan2(y, x);
    float distance = sqrt(x * x + y * y);
    moveTo(angle, distance);
}

void Movement::moveToXYAndRun(float x, float y){
    float angle = atan2(y, x);
    float distance = sqrt(x * x + y * y);
    moveToAndRun(angle, distance);
}

bool Movement::run()
{
    bool r_fl = fl.run();
    bool r_fr = fr.run();
    bool r_rl = rl.run();
    bool r_rr = rr.run();

    return r_fl || r_fr || r_rl || r_rr;
}

void Movement::moveToAndRun(float angle, float distance)
{
    
    moveTo(angle, distance);

    bool isRunning = true;
    bool isPaused = false;
    while(isRunning){
        if(enemy.isDetected(angle * RAD_TO_DEG)){
            stop();
            isPaused = true;
        }else{
            if(isPaused){
                fl.setMaxSpeed(SPEED);
                fr.setMaxSpeed(SPEED);
                rl.setMaxSpeed(SPEED);
                rr.setMaxSpeed(SPEED);
                isPaused = false;
            }
            isRunning = run();
        }
    }

    /*
    do {
        if(!enemy.isDetected(angle))
            run();
        else if(enemy.isDetected(angle))
            stop();
    } while (!isArrived());
    */

   /*
   moveTo(angle, distance);
   while(1){
    if(!enemy.isDetected(angle) || true)
        if(!run()) break;
    else
        stop();//pause
   }
   /**/

}

void Movement::stop()
{
    fl.setMaxSpeed(0);
    fr.setMaxSpeed(0);
    rl.setMaxSpeed(0);
    rr.setMaxSpeed(0);

    delay(1000);
}

void Movement::turnOver(float angle)
{
    // distance in mm the opposite wheels must run through
    halfCicle = PI * (angle * 1.01); // 180 deg =~ 182.5

    // Speed
    fl.setMaxSpeed(SPEED);
    fr.setMaxSpeed(SPEED);
    rl.setMaxSpeed(SPEED);
    rr.setMaxSpeed(SPEED);

    // Acceleration
    fl.setAcceleration(ACCEL);
    fr.setAcceleration(ACCEL);
    rl.setAcceleration(ACCEL);
    rr.setAcceleration(ACCEL);
    
    // Reset stepper position
    fl.setCurrentPosition(0);
    fr.setCurrentPosition(0);
    rl.setCurrentPosition(0);
    rr.setCurrentPosition(0);
    
    // Move the robot
    fl.move(-halfCicle * uStep);
    fr.move(halfCicle * uStep);
    rl.move(-halfCicle * uStep);
    rr.move(halfCicle * uStep);

    while(run()) {}
}

bool Movement::isArrived()
{
    if (fl.targetPosition() != fl.currentPosition() || 
        fr.targetPosition() != fr.currentPosition() || 
        rl.targetPosition() != rl.currentPosition() || 
        rr.targetPosition() != rr.currentPosition())
        return false;
    else
        return true;
}