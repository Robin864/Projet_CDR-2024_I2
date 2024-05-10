#include "Enemy.h"
#include "UniBoardV4Def.h"

Enemy::Enemy() : captor(Serial1)
{
    Serial1.begin(230400, SERIAL_8N1, PIN::Lidar::LIDAR_TX);
    captor.init();
    captor.enableFiltering();
    captor.setDistanceRange(150, 500);
}

void Enemy::setDetectionArea(float angle){

    /*
        Angle : dans repère robot
        135 : décalage lidar vers repère robot
        rangeAngle : angle de détection
    */

    float minAngle = angle - 135 - rangeAngle;
    float maxAngle = angle - 135 + rangeAngle;

    captor.setAngleRange(minAngle, maxAngle); // Default detection area
    THROW(minAngle)
    THROW(maxAngle)
}

bool Enemy::isDetected(float angle)
{
    setDetectionArea(angle);
    if (captor.readScan())
    {
        uint16_t points = captor.getNbPointsInScan();

        THROW(points)

        if (points == 0)
        {
            //delay(1000);
            return false;
        }
        else
            return true;
    }
    return false;
}