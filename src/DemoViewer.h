//
//  DemoViewer.h
//  LightingDataVisualizer
//
//  Created by songhojun on 11/11/13.
//
//

#pragma once

#include "ETRILighting.h"

class DemoViewer {
    
    
public:
    DemoViewer();
    ~DemoViewer();
    
    void setup(float x, float y);
    void draw(LightDemoType demoType);

ofImage indoorBG;
ofImage outdoorBG;
float posX;
float posY;

};