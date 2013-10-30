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
    menuButton.showButton(false,false);
    
    touchButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    motionButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    pressAltButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    tempHumidButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    colorLuxButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    
    
    
    streeDemoButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    indoorDemoButton.setup(menuWidth, menuWidth, false, false, BUTTON_SHAPE_RECT);
    
    
    touchButton.showButton(true, false);
    motionButton.showButton(true, false);
    pressAltButton.showButton(true, false);
    tempHumidButton.showButton(true, false);
    colorLuxButton.showButton(true, false);
    streeDemoButton.showButton(true, false);
    indoorDemoButton.showButton(true, false);
    
    
    touchIcon.loadImage("menu/touchIcon.png");
    motionIcon.loadImage("menu/motionIcon.png");
    pressAltIcon.loadImage("menu/pressAltIcon.png");
    tempHumidIcon.loadImage("menu/tempHumidIcon.png");
    colorLuxIcon.loadImage("menu/colorLuxIcon.png");
    
    streetDemoIcon.loadImage("menu/streetDemoIcon.png");
    indoorDemoIcon.loadImage("menu/indoorDemoIcon.png");
    
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
//        ofRectRounded(x-menuRect.getWidth()/2, y, menuRect.getWidth(), menuRect.getHeight(), 5);
        ofRect(x-menuRect.getWidth()/2, y, menuRect.getWidth(), menuRect.getHeight());

        
        touchButton.draw(0, y);
        motionButton.draw(0, y+menuWidth);
        pressAltButton.draw(0, y+(menuWidth) * 2);
        tempHumidButton.draw(0, y + (menuWidth) * 3);
        colorLuxButton.draw(0, y + (menuWidth) * 4);
        
        ofSetColor(255, 255, 255);
        touchIcon.draw(0, y);
        motionIcon.draw(0, y+menuWidth);
        pressAltIcon.draw(0, y+(menuWidth) * 2);
        tempHumidIcon.draw(0, y + (menuWidth) * 3);
        colorLuxIcon.draw(0, y + (menuWidth) * 4);
        
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