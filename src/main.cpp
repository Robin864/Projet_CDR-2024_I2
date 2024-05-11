#include <Arduino.h>
#include <AccelStepper.h>
#include <ld06.h>
#include <SPI.h>

#include "UniBoardV4Def.h" // Board Caracteristics
#include "Movement.h" // Bot's movements
#include "Position.h" // Position management
#include "Strategy.h" // Strategy
#include "Pince.h"

#define INIT_PIN PIN::Inputs::btn2
#define TEAM_PIN PIN::Inputs::btn1
#define TIR_PIN PIN::Inputs::TIR

//Strategy strat; // Initialize stategy
Enemy lidar;
Strategy strat; // Initialize stategy

bool initState;
bool initialized = false; // atHome

void setup()
{
    Serial.begin(115200);

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

    if(strat.team == 'b')
        Serial.println("Blue team");
    else if(strat.team == 'y')
        Serial.println("Yellow team");

    // if (digitalRead(INIT_PIN) != initState && !initialized)
    // {
    //     // strat.initialization();
    //     // initialized = true;

    //     // while (digitalRead(TIR_PIN)) // Wait the Tirette
    //     //     delay(1);
    //     Serial.println("Button pushed");
    // }

    Serial.println("Wait tirette");
    while (!digitalRead(TIR_PIN)) // Wait Tirette release
        delay(1);

    Serial.println("Tirette pulled");
    // strat.homologation();

    strat.game();

    // delay(10000);

    /*
    if (lidar.isDetected(45))
    {
        Serial.println("Detected");
    }/**/

    // strat.calibration();

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