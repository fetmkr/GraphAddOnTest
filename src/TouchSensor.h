//
//  TouchSensor.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#pragma once

#include "ETRILighting.h"
#include "Sensor.h"

class TouchSensor : public Sensor {
    
public:
    TouchSensor();
    ~TouchSensor();

    void setup();
    void draw(LightSensorType sensorType, LightVisualType visualType);

    void drawSlice(int num, bool bShow);
    void drawCWArrow(bool bShow, float msTime);
    void drawCCWArrow(bool bShow, float msTime);

    ofImage touchRingImg;
    ofImage cwArrowImg;
    ofImage ccwArrowImg;

    int NumOfSlice;
    ofxVectorGraphics ringSlice;

    ofxTimer cwArrowTimer;
    ofxTimer ccwArrowTimer;

    bool bCWShow;
    bool bCCWShow;
    
    float brightLevel;
    float getBrightLevel();
};