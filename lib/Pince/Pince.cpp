#include <Pince.h>

//! Setup des pinces
Pince Pince::m_instance; 
Pince& pince = Pince::instance();


void Pince::setup()
{
    pwm.begin();
    pwm.setOscillatorFrequency(25000000);
    pwm.setPWMFreq(SERVO_FREQ);
}

//Etat ouvert
void Pince::opening(int side) // Side can be right (0) or left (1)
{       
    if(side == 0) // Right
    {
        pwm.setPWM(SERVO_RP, 0, 400); // Faire tourner le servo 
        delay(500);
    }
    else if(side == 1) // Left
    {
        pwm.setPWM(SERVO_LP, 0, 370); // Faire tourner le servo
        delay(500);
    }
}


//! Pour Gauche, baisser la valeur pour amplifier le mouvement

void Pince::close(int side)
{
    if(side == 0) //Right
    {
        pwm.setPWM(SERVO_RP, 0, 150);
        delay(500);
    }
    else if(side == 1) //Left
    {
         pwm.setPWM(SERVO_LP, 0, 98);
         delay(500);
    }
}

void Pince::up(int side)
{
    if(side == 0) //Right
    {
        pwm.setPWM(SERVO_RB, 0, 185);
        delay(500);
    }
    else if(side == 1) //Left
    {
         pwm.setPWM(SERVO_LB, 0, 150);
         delay(500);
    }
}

void Pince::down(int side)
{

    if(side == 0) // Right
    {
        pwm.setPWM(SERVO_RB, 0, 380);
        delay(500);
    }
    else if(side == 1) // Left
    {
        pwm.setPWM(SERVO_LB, 0, 330);
        delay(500);
    }
}

//! Fonction attrape plante

void Pince::grab(int side)
{    
    if (side == 0){ //Right

        opening(0);
        delay(500); 
        down(0);
        delay(500); 
        close(0);
        delay(500); 
        up(0);
        delay(500); 
        isGrabed[0] = true;
    }
    else if (side == 1){   //Left

        opening(1);
        delay(500);
        down(1);
        delay(500);
        close(1);
        delay(500); 
        up(1);
        delay(500); 
        isGrabed[1] = true;
    }
}

//! Fonction lache plante

void Pince::ungrab(int side)
{

    if (side == 0){ //RIGHT
        down(0);
        delay(500);       
        opening(0);
        delay(500); 
        up(0);
        delay(500); 
        close(0);
        delay(500);
        isGrabed[0] = false; 
    }

    else if (side == 1){ //LEFT
        down(1);
        delay(500); 
        opening(1);
        delay(500);  
        up(1);
        delay(500); 
        close(1);
        delay(500); 
        isGrabed[1] = false;
    }
}