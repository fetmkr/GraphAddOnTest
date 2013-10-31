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
    
    dataButton.setup(menuWidth, menuWidth, true, false, BUTTON_SHAPE_RECT);
    ofAddListener(dataButton.pressEvent, this, &NavigationMenu::pressEventHandler);
    
    
    touchButton.showButton(true, false);
    motionButton.showButton(true, false);
    pressAltButton.showButton(true, false);
    tempHumidButton.showButton(true, false);
    colorLuxButton.showButton(true, false);
    
    indoorDemoButton.showButton(true, false);
//    indoorDemoButton.setPressedColor(ofColor(0,255,0));
    streeDemoButton.showButton(true, false);
//    streeDemoButton.setPressedColor(ofColor(255,0,0));

    dataButton.showButton(true, false);
    
    
    touchIcon.loadImage("menu/touchIcon.png");
    motionIcon.loadImage("menu/motionIcon.png");
    pressAltIcon.loadImage("menu/pressAltIcon.png");
    tempHumidIcon.loadImage("menu/tempHumidIcon.png");
    colorLuxIcon.loadImage("menu/colorLuxIcon.png");
    
    streetDemoIcon.loadImage("menu/streetDemoIcon.png");
    indoorDemoIcon.loadImage("menu/indoorDemoIcon.png");
    
    dataIcon.loadImage("menu/dataIcon.png");
    
    
    
    toggleButton.setup(50, 50, true, true, BUTTON_SHAPE_CIRCLE);
    toggleButton.showButton(false, false);
    ofAddListener(toggleButton.pressEvent, this, &NavigationMenu::pressEventHandler);
    
    bToggle = true;

    //default
    sensorType = SENSOR_TOUCH;
    
    
}

void NavigationMenu::reset(){
    toggleButton.setPressed(true);
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
        
        indoorDemoButton.draw(0, menuHeight + y - menuWidth *3);
        streeDemoButton.draw(0, menuHeight + y - menuWidth*2);
        
        dataButton.draw(0, menuHeight + y - menuWidth);
        
        ofSetColor(255, 255, 255);
        touchIcon.draw(0, y);
        motionIcon.draw(0, y+menuWidth);
        pressAltIcon.draw(0, y+(menuWidth) * 2);
        tempHumidIcon.draw(0, y + (menuWidth) * 3);
        colorLuxIcon.draw(0, y + (menuWidth) * 4);
        
        
        indoorDemoIcon.draw(0, menuHeight + y - menuWidth*3);
        streetDemoIcon.draw(0, menuHeight + y - menuWidth*2);
        
        
        dataIcon.draw(0, menuHeight + y - menuWidth);
    }
    
    if (touchButton.isPressed()) {
        sensorType = SENSOR_TOUCH;
        ofNotifyEvent(sensorTypeChanged, sensorType);
    }
    else if (motionButton.isPressed()){
        toggleButton.setPressed(true);
        sensorType = SENSOR_MOTION_2D;
        ofNotifyEvent(sensorTypeChanged, sensorType);
    }
    else if (pressAltButton.isPressed()){
        sensorType = SENSOR_PRESSURE_ALTITUDE;
        ofNotifyEvent(sensorTypeChanged, sensorType);
    }
    else if (tempHumidButton.isPressed()){
        sensorType = SENSOR_TEMP_HUMIDITY;
        ofNotifyEvent(sensorTypeChanged, sensorType);
    }
    else if (colorLuxButton.isPressed()){
        toggleButton.setPressed(true);
        sensorType = SENSOR_COLOR;
        ofNotifyEvent(sensorTypeChanged, sensorType);
    }

    

    
        
    ofPopMatrix();
    ofPopStyle();
}

void NavigationMenu::drawLRButton(float x, float y){
    

    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofSetColor(0, 0, 255);
    ofSetCircleResolution(80);

    ofNoFill();
    ofCircle(x-15, y, 10);
    ofCircle(x+15, y, 10);
    
    ofFill();
    ofPushMatrix();
    toggleButton.draw(x, y);
    if (toggleButton.isPressed()) {
        ofCircle(x-15, y, 10);
    }
    else{
        ofCircle(x+15, y, 10);
    }

    
    ofPopMatrix();
    ofPopStyle();
}

LightSensorType NavigationMenu::getSensorType(){
    return sensorType;
}

void NavigationMenu::pressEventHandler(bool &bPress){
    if(toggleButton.isPressed()){
        bToggle = true;
        if (sensorType == SENSOR_MOTION_3D){
            sensorType = SENSOR_MOTION_2D;
        }
        else if(sensorType == SENSOR_LUX){
            sensorType = SENSOR_COLOR;
        }
        ofNotifyEvent(sensorTypeChanged, sensorType);
    }
    else{
        bToggle = false;
        if (sensorType == SENSOR_MOTION_2D){
            sensorType = SENSOR_MOTION_3D;
        }
        else if(sensorType == SENSOR_COLOR){
            sensorType = SENSOR_LUX;
        }
        ofNotifyEvent(sensorTypeChanged, sensorType);
    }
    
    
    if(dataButton.isPressed()){
        visualType = VISUAL_SIENCE;
        ofNotifyEvent(visualTypeChanged, visualType);
    }
    else{
        visualType = VISUAL_GRAPHIC;
        ofNotifyEvent(visualTypeChanged, visualType);
    }
    
}
