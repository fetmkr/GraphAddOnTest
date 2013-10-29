//
//  PressAltSensor.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#pragma once

#include "ETRILighting.h"
#include "Sensor.h"

class PressAltSensor : public Sensor {
    
public:
    PressAltSensor();
    ~PressAltSensor();
    
    void setup();
    void draw(LightSensorType sensorType, LightVisualType visualType);
    
    ofImage arrowImg;
};