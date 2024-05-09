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
    // Position to first plants
    move.moveToAndRun(135 * DEG_TO_RAD, 700);
    
    // if (!pince.isGrabed[0])
    pince.grab(0);

    // Position to second plants
    move.moveToAndRun(0, 0);
    
    // if (!pince.isGrabed[1])
    pince.grab(1);

    // Drop the plants in the Jardinière
    goNearPlantsBasket();
    pushPots();
    
    pince.ungrab(1); // First ungrab the left side


    pince.ungrab(0); // And ungrab the right side

    // Position to third plants
    move.moveToAndRun(0, 0);
    pince.grab(1);


    // Position to third plants
    move.moveToAndRun(0, 0);
    pince.grab(0);

    // Drop the plants in the Jardinière
    goNearPlantsBasket();
    pushPots();
    pince.ungrab(0);


    pince.ungrab(1);

    // Start panels process
    goToPanelsWall();

    movePanels();

    goHome();
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
        move.moveToXYAndRun(680, 715-200); // Go to plants
        move.moveToXYAndRun(20, 0); // Push the plants
        //pince.grab(0);

        move.turnOver(); // Must be corrected
        while(move.run());

        move.moveToXYAndRun(336, 15); // Go to the wall
        // pince.ungrab(0);
        move.moveToXYAndRun(10, 0);
        move.moveToXYAndRun(0, -715); // Go to home2
    }
}
