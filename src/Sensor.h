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
    
    map<string, int> lineGroup;
    void addGroup(string name);
    void addLineToGroup(string name, ofxPlotLine* line);
    void drawDataGroup(float x, float y, int index);
    
    void drawPlots();

    ofTrueTypeFont analFont;
    ofTrueTypeFont groupFont;
    
    ofImage etriLogoBlk;

    ofImage BGImg;
    
    ofTrueTypeFont numberFont;
    ofTrueTypeFont textFont;
    
    ofxPlot shortPlot;
    ofxPlot longPlot;
    
    int NumOfGroups;
    
    vector<ofxPlotLine*> linesPtr;
};
