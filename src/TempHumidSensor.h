//
//  TempHumidSensor.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#pragma once

#include "ETRILighting.h"
#include "Sensor.h"

class TempHumidSensor : public Sensor {
public:
    TempHumidSensor();
    ~TempHumidSensor();
    void setup();
    void draw(LightSensorType sensorType, LightVisualType visualType);
    
    void drawBar(float x, float y, float w, float val, ofColor c);
    
    ofImage gageImg;
    
    float ambTempVal;
    float objTempVal;
    float humidVal;
    
    void setTempHumidVal(float ambT, float objT, float hum);
    
};