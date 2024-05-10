#include "Strategy.h"
#include "Movement.h"
#include "Pince.h"

#define TEAM_PIN PIN::Inputs::btn1
#define INIT_PIN PIN::Inputs::btn2

//Pince pince; // Right : 0, Left : 1

Strategy::Strategy()
{
    pinMode(TEAM_PIN, INPUT_PULLUP);
    pinMode(INIT_PIN, INPUT_PULLUP);
}

void Strategy::teamSelection()
{
    if(digitalRead(TEAM_PIN) == HIGH) // Button true
        team = 'y';
    else if(digitalRead(TEAM_PIN) == LOW) // Button false
        team = 'b';
}

void Strategy::initialization()
{
    move.init(team);

    // Handle team error
}

void Strategy::game()
{
    move.moveToXYAndRun(250, 250); //
    move.turnOver(-90); // Place the pince RIGHT in front of the plants
    move.moveToXYAndRun(350, -315); // Go to plant
    move.moveToXYAndRun(0, -210); // Push the plants to align it
    pince.grab(1); // Grab all the plants of the group using left pince

    move.moveToXYAndRun(600, 350); // Move to the second plants group
    move.turnOver(180); // Place the pince in front of the plants
    move.moveToXYAndRun(0, 300); // Push the plant to align it  
    pince.grab(0);

    move.moveToXYAndRun(800, 0);
    move.turnOver(-90);
    move.moveToXYAndRun(0, -400);
    pince.ungrab(1); // Ungrab plants in the basket

    move.moveToXYAndRun(0, 150);
    move.turnOver(-90);
    move.moveToXYAndRun(2000, 1200);
    pince.ungrab(0);



}

void Strategy::calibration()
{
    if(team == 'y'){
        move.moveTo(0 * DEG_TO_RAD, 500);
        while(!move.isArrived())
        {
            move.run();
        }
    }
    else if(team == 'b'){
        move.moveTo(-45 * DEG_TO_RAD, 500);
        while(!move.isArrived())
        {
            move.run();
        }
    }
}

void Strategy::movePlants()
{
    move.moveToAndRun(0, 0);
    move.moveToAndRun(0, -0); // Exact same distances but opposites each
}

void Strategy::goNearPlantsBasket()
{
    move.moveToAndRun(0, 0);
}

void Strategy::pushPots()
{
    // Little movement to push pots
    move.moveToAndRun(0, 0);
    move.moveToAndRun(0, 0); // Push it and come back
}

void Strategy::goToPanelsWall()
{
    move.moveToAndRun(0, 0);
}

void Strategy::movePanels()
{
    move.moveToAndRun(0, 0);
}

void Strategy::goHome()
{
    move.moveToAndRun(270, 1900);
}

void Strategy::homologation()
{
    if(team == 'y'){
        
    }
    else if(team == 'b'){
        move.moveToXYAndRun(250, 250); // Go to plants
        move.turnOver(-90);
        move.moveToXYAndRun(1300, 0); // Push the plants
        // pince.grab(0);

        // move.turnOver(90); // Must be corrected
        // // while(move.run());

        // move.moveToXYAndRun(336, 15); // Go to the wall
        // // pince.ungrab(0);
        // move.moveToXYAndRun(10, 0);
        // move.moveToXYAndRun(0, -715); // Go to home2
    }
}

void Strategy::grabPlants()
{
    pince.grab(0);
}