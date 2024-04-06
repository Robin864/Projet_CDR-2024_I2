// Based on
// https://raw.githubusercontent.com/Unimakers/CDR-2024-FIRMWARE/main/CDR2024%20BASE/lib/Define/UniBoardDef.h

#pragma once

namespace PIN
{
    namespace Inputs
    {
        constexpr int
        TIR = 6,
        btn1 = 7,
        btn2 = 25;
    } // namespace Inputs

    namespace Steppers
    {
        constexpr int
            STEP1 = 18,
            STEP2 = 16,
            STEP3 = 21,
            STEP4 = 23,

            EN = 19,

            DIR1 = 17,
            DIR2 = 15,
            DIR3 = 20,
            DIR4 = 22;  
    } // namespace Steppers
    
    namespace Lidar
    {
        constexpr int
            LIDAR_TX = 11,
            LIDAR_RX = 10,
            LIDAR_PWM = 12;
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
            NAPPE1 = 26,
			NAPPE2 = 33,
			NAPPE3 = 34,
			NAPPE4 = 35,
			NAPPE5 = 32,
			NAPPE6 = 31,
			NAPPE7 = 38,
			NAPPE8 = 39;
    } // namespace Nappe
    
} // namespace PIN
