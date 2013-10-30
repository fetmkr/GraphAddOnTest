//
//  ColorSensor.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#pragma once

#include "ETRILighting.h"
#include "Sensor.h"
#include "ofxDAQButton.h"

class ColorSensor : public Sensor {
    
    
public:
    ColorSensor();
    ~ColorSensor();

    void setup();
    void reset();
    void draw(LightSensorType sensorType, LightVisualType visualType);

    ofImage colorPicker;
    void setupColorPicker(int width, int height);
    ofColor pickColor(int x, int y);
    ofColor getCompColor(ofColor c);
    
    ofColor selectedColor;
    
    ofxDAQButton button;
};