//
//  Sensor.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/25/13.
//
//

#pragma once

#include "ETRILighting.h"

class Sensor {
    
    
public:
    Sensor();
    ~Sensor();


    void setup();
    
    void drawAnalBG(string name);
    ofTrueTypeFont analFont;
    ofxSVG etriLogoBlk;

    ofTrueTypeFont numberFont;
    ofTrueTypeFont textFont;
    
    ofxPlot shortPlot;
    ofxPlot longPlot;
};
