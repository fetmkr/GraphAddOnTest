//
//  NavigationMenu.h
//  LightingDataVisualizer
//
//  Created by songhojun on 10/30/13.
//
//

#pragma once

#include "ETRILighting.h"
#include "ofxDAQButton.h"

class NavigationMenu {
    
public:
    NavigationMenu();
    ~NavigationMenu();
    
    void setup(float w, float h, ofColor c);
    void draw(float x, float y);
    
    ofRectangle menuRect;
    ofColor menuColor;
    ofxDAQButton menuButton;
    
    ofxDAQButton touchButton;
    ofxDAQButton motionButton;
    ofxDAQButton pressAltButton;
    ofxDAQButton tempHumidButton;
    ofxDAQButton colorLuxButton;
    
    ofxDAQButton streeDemoButton;
    ofxDAQButton indoorDemoButton;
    
    
    ofImage touchIcon;
    ofImage motionIcon;
    ofImage pressAltIcon;
    ofImage tempHumidIcon;
    ofImage colorLuxIcon;
    
    ofImage streetDemoIcon;
    ofImage indoorDemoIcon;
    
    LightSensorType sensorType;
    LightDemoType demoType;
    
    LightSensorType getSensorType();
    
    float menuWidth;
    float menuHeight;
};
