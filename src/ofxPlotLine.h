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
    
    float getElement(int index);
    
    void setVisible(bool bShow);
    bool isVisible();

    string name;
    ofColor color;
    float lastData;
    bool bIsVisible;

    int BUFFER_SIZE;
    int nextIndex;
    vector<float> dataBuffer;
    
};
