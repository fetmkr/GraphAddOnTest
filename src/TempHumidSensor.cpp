//
//  TempHumidSensor.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#include "TempHumidSensor.h"

TempHumidSensor::TempHumidSensor(){
    
}

TempHumidSensor::~TempHumidSensor(){
    
}

void TempHumidSensor::setup(){
    Sensor::setup();
    setBGImg("tempHumid/tempHumidBG.png");
    gageImg.loadImage("tempHumid/gagebar.png");
    gageImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    gageImg.setAnchorPoint(gageImg.getWidth()/2, gageImg.getHeight()/2);

}

void TempHumidSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        drawInfo(200, 125);
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    drawBGImg(0, 0);
    
    // change the val from data
    drawBar(680, 640, 100, 200, ofColor(174,174,174));
    drawBar(910, 640, 100, 200, ofColor(244,15,70));
    drawBar(1130, 640, 100, 200, ofColor(0,0,255));

    ofSetColor(255, 255, 255);

    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, 450);
    gageImg.draw(0, 0);
    ofPopMatrix();
    

    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("TEMP. & HUMIDITY DATA");
        drawPlots();
    }

}

void TempHumidSensor::drawBar(float x, float y, float w, float val, ofColor c){
    
    ofSetColor(c);
    ofFill();
    ofRect(x, y, w, val * (-1));
    
}
