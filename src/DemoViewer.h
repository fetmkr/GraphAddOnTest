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

float brightLevel;
float luxVal;
float cupTemp;

float streetRotY;
float streetRotZ;


void setDemoVal(float bright, float lux, float cupT, float RotY, float RotZ);

};