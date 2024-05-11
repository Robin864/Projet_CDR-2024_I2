#include "Timer.h"

bool gg = false; // good game

void IRAM_ATTR endGame() // Interrupt function
{
    delay(1000000);
}

void Timer::setup(int gameTime)
{
    t = timerBegin(TIMERID, TIMER_FREQ, true); // Specify an ID and the timer frequency different from 1,2,3, see UniBoard's schematic
    timerAttachInterrupt(t, &endGame, true); // Attach a fonction to the interruption
    timerAlarmWrite(t, FREQ_DIVIDER*gameTime, true); // Set settings for the timer
}

void Timer::start()
{
    timerAlarmEnable(t); // Enable timer
}

bool Timer::gameOver() // Handle end game
{
    if (gg)
    {
        return true;
    }
    return false;
}