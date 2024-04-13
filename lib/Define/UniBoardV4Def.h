/*
    Based on https://raw.githubusercontent.com/Unimakers/CDR-2024-FIRMWARE/main/CDR2024%20BASE/lib/Define/UniBoardDef.h
    Updated 13/04/2024
*/

#pragma once

namespace PIN
{
    namespace Inputs
    {
        constexpr int
        TIR = 6,
        btn1 = 7,
        btn2 = 48;
    } // namespace Inputs

    namespace Steppers
    {
        constexpr int
            STEP1 = 10,
            STEP2 = 46,
            STEP3 = 13,
            STEP4 = 21,

            EN = 11,

            DIR1 = 9,
            DIR2 = 3,
            DIR3 = 12,
            DIR4 = 14;  
    } // namespace Steppers
    
    namespace Lidar
    {
        constexpr int
            LIDAR_TX = 18,
            LIDAR_RX = 17,
            LIDAR_PWM = 8;
    } // namespace Lidar

    namespace I2C
    {
        constexpr int
            SDA = 4,
            SCL = 5;
    } // namespace I2C
    
    namespace Nappe
    {
        constexpr int
            NAPPE1 = 45,
			NAPPE2 = 40,
			NAPPE3 = 41,
			NAPPE4 = 42,
			NAPPE5 = 39,
			NAPPE6 = 38,
			NAPPE7 = 1,
			NAPPE8 = 2;
    } // namespace Nappe
    
} // namespace PIN
