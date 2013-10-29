//
//  ofxDAQButton.h
//  LightingDataVisualizer
//
//  Created by songhojun on 10/29/13.
//
//

#pragma once

#include "ofMain.h"

enum ButtonShapeType{
    BUTTON_SHAPE_RECT = 0,
    BUTTON_SHAPE_CIRCLE = 1
};

class ofxDAQButton {
public:
    ofxDAQButton();
    ~ofxDAQButton();
    
    void setup(float width, float height, bool bToggle , bool bDefaultVal, ButtonShapeType shape);
    void resize(float width, float height);
    void clearEvents();
    void draw(float x, float y);
    void setPressedColor(ofColor c);
    void setReleasedColor(ofColor c);
    void showPressed();
    void showReleased();
    
    
    void showButton(bool bShow);
    bool bShowButton;
    
    bool isPressed();
    
    ofVec2f getMouseXY();
    float mouseX;
    float mouseY;
    
    void mouseMoved(ofMouseEventArgs& event);
    void mouseDragged(ofMouseEventArgs& event);
    void mousePressed(ofMouseEventArgs& event);
    void mouseReleased(ofMouseEventArgs& event);
    
    ButtonShapeType shapeType;
    
    
    float buttonWidth;
    float buttonHeight;
    
    float buttonRadius;
    
    float bToggleButton;
    
    float transX;
    float transY;
    
    ofColor pressedColor;
    ofColor releasedColor;
    
    bool bWasSetup;
    bool bHasFocus;
    bool bIsPressed;
    
    ofRectangle buttonRect;
    
    bool IsInside(float x, float y);
    
    //    void addSound(string filename);
};