//
//  ofxPlotButton.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/24/13.
//
//

#pragma once

#include "ofMain.h"

class ofxPlotButton {
public:
    ofxPlotButton();
    ~ofxPlotButton();
    
    void setup(float width, float height, bool bToggle);
    void clearEvents();
    void draw(float x, float y);
    bool isPressed();
    
    void mouseMoved(ofMouseEventArgs& event);
    void mouseDragged(ofMouseEventArgs& event);
    void mousePressed(ofMouseEventArgs& event);
    void mouseReleased(ofMouseEventArgs& event);
    

    float buttonWidth;
    float buttonHeight;
    float bToggleButton;
    
    float transX;
    float transY;
    
    bool bWasSetup;
    bool bHasFocus;
    bool bIsPressed;
    
    ofRectangle buttonRect;

    
//    void addSound(string filename);
};