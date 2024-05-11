#include <Arduino.h>

const double FREQ_DIVIDER = 1000000; // Periods multiplier
const double TIMER_FREQ = 80; // In Mhz
const double TIMERID = 0;

class Timer
{
private:
    hw_timer_t * t = NULL; // Declare new timer
    
public:
    void setup(int gameTime); // Setup timer with specified game time in seconds
    void start(); // Start the timer
    bool gameOver(); // Check if the timer is ended (so the game)
};