//
//  MotionSensor2D.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/25/13.
//
//

#pragma once
#include "ETRILighting.h"
#include "Sensor.h"


class MotionSensor2D : public Sensor{
    
public:
    MotionSensor2D();
    ~MotionSensor2D();

    void setup();
    void draw(LightSensorType sensorType, LightVisualType visualType);
    
    float accelX;
    float accelY;
    float accelZ;
    float compassVal;
    void setAccelVal(float x, float y, float z);
    void setCompassVal(float val);

    ofImage compassImg;
    
};
