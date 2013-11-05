//
//  ofxPlotLine.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxPlotButton.h"

class ofxPlotLine {
public:
    ofxPlotLine();
    ~ofxPlotLine();
    
    void setup(string name, ofColor color);
    void clear();
    void draw(ofEventArgs& event);
    void drawButton(float x, float y);
    
    void addData(float data);
    void setDrawScale(float scale);
    float getDrawScale();
    
    float drawScaleFactor;
    
    float getElement(int index);
    
    void setVisible(bool bShow);
    bool isVisible();
    
    float getMax();
    void resetMax();
    
    float getMin();
    void resetMin();
    
    float getAvg(int NumOfSamples);
    
    
    float maxValForDrawing;
    float minValForDrawing;
    
    void setMaxForDrawing( float val);
    float getMaxForDrawing();
    
    void setMinForDrawing( float val);
    float getMinForDrawing();
    
    float maxVal;
    float minVal;

    string name;
    ofColor color;
    float lastData;
    bool bIsVisible;

    int BUFFER_SIZE;
    int nextIndex;
    vector<float> dataBuffer;
    
    ofxPlotButton button;
    
    string groupName;
    void setGroupName(string name);
    string getGroupName();

};
