//
//  ofxPlotLine.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#pragma once

#include "ofMain.h"

class ofxPlotLine {
public:
    ofxPlotLine();
    ~ofxPlotLine();
    
    void setup(string name, ofColor color);
    void clear();
    void draw(ofEventArgs& event);
    
    void addData(float data);
    void setScale(float scale);
    float getScale();
    
    float scaleFactor;
    
    float getElement(int index);
    
    void setVisible(bool bShow);
    bool isVisible();
    
    float getMax();
    void resetMax();
    
    float getMin();
    void resetMin();
    
    float getAvg(int NumOfSamples);
    
    float maxVal;
    float minVal;

    string name;
    ofColor color;
    float lastData;
    bool bIsVisible;

    int BUFFER_SIZE;
    int nextIndex;
    vector<float> dataBuffer;
    
};
