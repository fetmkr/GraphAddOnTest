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
    void reset();
    void draw(float x, float y);
    
    void drawLRButton(float x, float y);
    
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
    
    ofxDAQButton dataButton;
    
    ofxDAQButton toggleButton;
    bool bToggle;
    
    ofImage touchIcon;
    ofImage motionIcon;
    ofImage pressAltIcon;
    ofImage tempHumidIcon;
    ofImage colorLuxIcon;
    
    ofImage streetDemoIcon;
    ofImage indoorDemoIcon;
    
    ofImage dataIcon;
    
    LightSensorType sensorType;
    LightVisualType visualType;
    LightDemoType demoType;
    
    LightSensorType getSensorType();
    
    float menuWidth;
    float menuHeight;
    
    ofEvent<LightSensorType> sensorTypeChanged;
    ofEvent<LightVisualType> visualTypeChanged;
    ofEvent<LightDemoType> demoTypeChanged;
    void toggleButtonEventHandler(bool &bPress);
    void dataButtonEventHandler(bool &bPress);
    void indoorButtonEventHandler(bool &bPress);
    void outdoorButtonEventHandler(bool &bPress);


};
