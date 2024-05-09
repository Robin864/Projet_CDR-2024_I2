#include <Arduino.h>
#include <AccelStepper.h>
#include <ld06.h>
#include <SPI.h>

#include "UniBoardV4Def.h" // Board Caracteristics
#include "Movement.h" // Bot's movements
#include "Position.h" // Position management
#include "Strategy.h" // Strategy
#include "Timer.h"
#include "Pince.h"

#define INIT_PIN PIN::Inputs::btn2
#define TEAM_PIN PIN::Inputs::btn1
#define TIR_PIN PIN::Inputs::TIR

//Strategy strat; // Initialize stategy
Timer timer;
Enemy lidar;
Strategy strat; // Initialize stategy

bool initState;
bool initialized = false; // atHome

void setup()
{
    Serial.begin(115200);
    timer.setup(100); // Game Time

    pinMode(TEAM_PIN, INPUT_PULLUP);
    pinMode(INIT_PIN, INPUT_PULLUP);
    pinMode(TIR_PIN, INPUT_PULLUP);

    // Enable steppers
    pinMode(PIN::Steppers::EN, OUTPUT); // enable/disable
    digitalWrite(PIN::Steppers::EN, LOW);

    // initState = digitalRead(INIT_PIN);

    strat.teamSelection();
    move.setup();
    pince.setup();
}

void loop()
{
    // strat.teamSelection(); // 1 = yellow, 0 = blue
    // if(strat.team == 'b')
    //     Serial.println("Blue team");
    // else if(strat.team == 'y')
    //     Serial.println("Yellow team");

    // if (digitalRead(INIT_PIN) != initState && !initialized)
    // {
    //     // strat.initialization();
    //     // initialized = true;

    //     // while (digitalRead(TIR_PIN)) // Wait the Tirette
    //     //     delay(1);
    //     Serial.println("Button pushed");
    // }

    // if (digitalRead(TIR_PIN)) // Si terette non présente
    // {
    //     Serial.println("TIRETTE");
    //     move.moveTo(270 * DEG_TO_RAD, 2000);
    //     move.moveToAndRun(270 * DEG_TO_RAD, 2000);
    // }

    // delay(10000);

    /*
    if (lidar.isDetected(45))
    {
        Serial.println("Detected");
    }/**/

    // strat.calibration();

    strat.homologation();

    // if (!digitalRead(TIR_PIN) && initialized)
    // {
    //     while (!digitalRead(TIR_PIN)) // Wait Tirette release
    //         delay(1);

    //     timer.start();
        
    //     while (!timer.gameOver())
    //     {
    //         // strat.game();
    //     }

    //     for(;;); // Stop loop
    // }

    while(1);
}