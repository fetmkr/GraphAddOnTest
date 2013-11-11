//
//  PressAltSensor.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#include "PressAltSensor.h"

PressAltSensor::PressAltSensor(){
    
}

PressAltSensor::~PressAltSensor(){
    
}

void PressAltSensor::setup(){
    Sensor::setup();
    setBGImg("pressAlt/pressAltBG.png");
    arrowImg.loadImage("pressAlt/arrow.png");
    arrowImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    arrowImg.setAnchorPoint(arrowImg.getWidth()/2, arrowImg.getHeight()/2);
}

void PressAltSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        drawInfo(200, 125);
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    drawBGImg(0, 0);
    
    ofPushMatrix();
    ofTranslate(660, 490);
    ofRotateZ(0);
    arrowImg.draw(0, 0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(1260, 490);
    ofRotateZ(0);
    arrowImg.draw(0, 0);
    ofPopMatrix();
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("PRESSURE ALTITUDE DATA");
        drawPlots();
    }
}