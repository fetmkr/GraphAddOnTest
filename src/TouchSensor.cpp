//
//  TouchSensor.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#include "TouchSensor.h"

TouchSensor::TouchSensor(){
    
}

TouchSensor::~TouchSensor(){
    
}

void TouchSensor::setup(){
    Sensor::setup();
    touchRingImg.loadImage("touchSensor/touchRing.png");
    touchRingImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    touchRingImg.setAnchorPoint(touchRingImg.getWidth()/2, touchRingImg.getHeight()/2);
    
    cwArrowImg.loadImage("touchSensor/cwArrow.png");
    cwArrowImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    cwArrowImg.setAnchorPoint(cwArrowImg.getWidth()/2, cwArrowImg.getHeight()/2);
    
    ccwArrowImg.loadImage("touchSensor/ccwArrow.png");
    ccwArrowImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    ccwArrowImg.setAnchorPoint(ccwArrowImg.getWidth()/2, ccwArrowImg.getHeight()/2);
}

void TouchSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);

    ofPushMatrix();
    touchRingImg.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofPopMatrix();
    
    ofPushMatrix();
    cwArrowImg.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofPopMatrix();
    
    ofPushMatrix();
    ccwArrowImg.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofPopMatrix();
    
    ofPushMatrix();
    ofSetColor(5, 5, 229);
    ofSetCircleResolution(80);
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 50);
    ofPopMatrix();
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("TOUCH DATA ANALYSIS");
        drawPlots();
    }
    
}