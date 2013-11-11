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
    ofImage cupImg;

    ofImage outdoorBG;
    ofImage streeLightImg;
    ofImage etriLogo;


    float posX;
    float posY;

};