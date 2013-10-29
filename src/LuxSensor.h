//
//  LuxSensor.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//
#pragma once

#include "ETRILighting.h"
#include "Sensor.h"
#include "ofxDAQButton.h"

class LuxSensor : public Sensor {
public:
    LuxSensor();
    ~LuxSensor();
    void setup();
    void draw(LightSensorType sensorType, LightVisualType visualType);
    ofxDAQButton button;
    float dragPosY;

    float lightIntensity;
    float prevLightLevel;
    bool bDragStarted;
    void updateLightIntensity(float val);
    
};