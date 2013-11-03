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
    void setBGImg(string path);
    void drawBGImg(float x, float y);
    void drawAnalBG(string name);
    
    void addLine(ofxPlotLine* line);
    
    void addGroup(string groupName);
    void addLineToGroup(ofxPlotLine* line, string groupName);
       
    void drawPlots();
    void drawGroupData(float x, float y);
    void drawGroupData(float x, float y, string groupName);

    ofTrueTypeFont analFont;
    ofTrueTypeFont groupFont;
    ofTrueTypeFont dataFont;
    
    ofImage etriLogoBlk;

    ofImage BGImg;
    
    ofTrueTypeFont numberFont;
    ofTrueTypeFont textFont;
    
    ofxPlot shortPlot;
    ofxPlot longPlot;
    
    
};
