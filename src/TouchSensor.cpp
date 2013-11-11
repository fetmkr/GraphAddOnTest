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
    //ring.arc(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 225, 225, -11.25, 11.25,80);

    NumOfSlice = 16;
    ringSlice.fill();
    
    cwArrowTimer.setup(500, false);
    ccwArrowTimer.setup(500, false);
    
    bCWShow = false;
    bCCWShow = false;
    
    brightLevel = 0.0;
}

void TouchSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        drawInfo(200, 125);
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    

    ofPushMatrix();
    ofSetColor(255, 0, 0);
    ofFill();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    // slice drawing
    drawSlice(0, false);
    ofPopMatrix();

    ofSetColor(255, 255, 255);
    ofPushMatrix();
    touchRingImg.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofPopMatrix();
    
    if (bCWShow) {

        if(cwArrowTimer.isTimerFinished()){
            bCWShow = false;
        }
        else{
            ofPushMatrix();
            cwArrowImg.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofPopMatrix();
        }
    }
    
    if (bCCWShow) {
        
        if(ccwArrowTimer.isTimerFinished()){
            bCCWShow = false;
        }
        else{
            ofPushMatrix();
            ccwArrowImg.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofPopMatrix();
        }
    }


    
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

void TouchSensor::drawSlice(int num, bool bShow){
    
    // 16 slices ranges from 0 ~ 15
    if (num <0) {
        num = 0;
    }
    if (num > NumOfSlice - 1) {
        num = NumOfSlice - 1;
    }
    if (bShow) {
        ringSlice.arc(0, 0, 225, -90-11.25 + (360.0/NumOfSlice) * num, 360.0/NumOfSlice);
    }
   
}

void TouchSensor::drawCWArrow(bool bShow, float msTime){
    cwArrowTimer.reset();
    cwArrowTimer.setTimer(msTime);
    cwArrowTimer.startTimer();
    bCWShow = bShow;
}

void TouchSensor::drawCCWArrow(bool bShow, float msTime){
    ccwArrowTimer.reset();
    ccwArrowTimer.setTimer(msTime);
    ccwArrowTimer.startTimer();
    bCCWShow = bShow;
}

float TouchSensor::getBrightLevel(){
    return brightLevel;
}

