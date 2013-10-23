//
//  ofxPlotSlider.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/22/13.
//
//

#pragma once

#include "ofMain.h"

class ofxPlotSlider {
public:
    ofxPlotSlider();
    ~ofxPlotSlider();
    
    void draw(float x, float y);
    void mouseMoved(ofMouseEventArgs& event);
    void mouseDragged(ofMouseEventArgs& event);
    void mousePressed(ofMouseEventArgs& event);
    void mouseReleased(ofMouseEventArgs& event);

    
    void setup(float width);
    void clearEvents();

    void setBar(ofColor color, float size);
    
    float getValue();
    
    bool isInside(float _x, float _y);
    void updateBarPos(float _x, float _y);

    ofColor barColor;
    float barCircleRadius;

    float transX;
    float transY;
    float sliderWidth;
    float barPosX;
    float barPosY;

    bool bHasFocus;
    bool bWasSetup;

};
