//
//  NavigationMenu.cpp
//  LightingDataVisualizer
//
//  Created by songhojun on 10/30/13.
//
//

#include "NavigationMenu.h"

NavigationMenu::NavigationMenu(){
    
}

NavigationMenu::~NavigationMenu(){
    
}

void NavigationMenu::setup(float w, float h, ofColor c){
    menuWidth = w;
    menuHeight = h;
    
    menuRect = ofRectangle(0,0,2*menuWidth,menuHeight);
    menuColor = c;
    
    menuButton.setup(2*menuWidth, menuHeight, false, false, BUTTON_SHAPE_RECT);
    menuButton.showButton(false);
    
    touchButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    motionButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    pressAltButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    tempHumidButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    colorLuxButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    
    streeDemoButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    indoorDemoButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    
    //default
    sensorType = SENSOR_TOUCH;
    
}

void NavigationMenu::draw(float x, float y){
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    menuButton.draw(x-menuRect.getWidth()/2, y);
    
    if (menuButton.isMoveInside()) {
        
        ofSetColor(ofColor(menuColor));
        ofRectRounded(x-menuRect.getWidth()/2, y, menuRect.getWidth(), menuRect.getHeight(), 5);
        
        
        touchButton.draw(0, y);
        motionButton.draw(0, y+menuWidth+20);
        pressAltButton.draw(0, y+(menuWidth+20) * 2);
        tempHumidButton.draw(0, y + (menuWidth+20) * 3);
        colorLuxButton.draw(0, y + (menuWidth+20) * 4);
        
        streeDemoButton.draw(0, y + (menuWidth+20) * 5);
        indoorDemoButton.draw(0, y + (menuWidth+20) * 6);
    }
    
    if (touchButton.isPressed()) {
        sensorType = SENSOR_TOUCH;
    }
    else if (motionButton.isPressed()){
        sensorType = SENSOR_MOTION_2D;
    }
    else if (pressAltButton.isPressed()){
        sensorType = SENSOR_PRESSURE_ALTITUDE;
    }
    else if (tempHumidButton.isPressed()){
        sensorType = SENSOR_TEMP_HUMIDITY;
    }
    else if (colorLuxButton.isPressed()){
        sensorType = SENSOR_COLOR;
    }

    
    ofPopMatrix();
    ofPopStyle();
}


LightSensorType NavigationMenu::getSensorType(){
    return sensorType;
}