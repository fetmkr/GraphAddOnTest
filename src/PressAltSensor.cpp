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
    pressureVal = 0.0;
    altVal = 0.0;
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
    ofRotateZ(pressureVal);
    arrowImg.draw(0, 0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(1260, 490);
    ofRotateZ(altVal);
    arrowImg.draw(0, 0);
    ofPopMatrix();
    
    ofSetColor(0, 0, 0);
    ofRectangle pressRect = numberFont.getStringBoundingBox(niceFloatToString(pressureVal, PRECISION_1DIGIT), 0, 0);
    ofRectangle altRect = numberFont.getStringBoundingBox(niceFloatToString(altVal, PRECISION_1DIGIT), 0, 0);
    
    numberFont.drawString(niceFloatToString(pressureVal, PRECISION_1DIGIT), 660 - pressRect.getWidth()/2, 790);
    numberFont.drawString(niceFloatToString(altVal, PRECISION_1DIGIT), 1260 - altRect.getWidth()/2, 790);
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("PRESSURE ALTITUDE DATA");
        drawPlots();
    }
}

void PressAltSensor::setPressAltVal(float press, float alt){
    pressureVal = press;
    altVal = alt;
}