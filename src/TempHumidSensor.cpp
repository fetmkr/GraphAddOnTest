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
    ambTempVal = 0.0;
    objTempVal = 0.0;
    humidVal = 0.0;

}

void TempHumidSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        drawInfo(200, 125);
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    drawBGImg(0, 0);
    
    // change the val from data
    drawBar(680, 640, 100, ofMap(ambTempVal, -45.0, 125.0, 20, 360), ofColor(174,174,174));
    drawBar(910, 640, 100, ofMap(objTempVal, -45.0, 125.0, 20, 360), ofColor(244,15,70));
    drawBar(1130, 640, 100, ofMap(humidVal, 0.0, 100.0, 20, 360), ofColor(0,0,255));

    ofSetColor(255, 255, 255);

    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, 450);
    gageImg.draw(0, 0);
    ofPopMatrix();
    ofSetColor(0, 0, 0);
    ofRectangle ambTRect = numberFont.getStringBoundingBox(niceFloatToString(ambTempVal, PRECISION_3DIGIT), 0, 0);
    ofRectangle objTRect = numberFont.getStringBoundingBox(niceFloatToString(objTempVal, PRECISION_3DIGIT), 0, 0);
    ofRectangle humidRect = numberFont.getStringBoundingBox(niceFloatToString(humidVal, PRECISION_3DIGIT), 0, 0);
    
    numberFont.drawString(niceFloatToString(ambTempVal, PRECISION_3DIGIT), 740 - ambTRect.getWidth()/2, 790);
    numberFont.drawString(niceFloatToString(objTempVal, PRECISION_3DIGIT), 960 - objTRect.getWidth()/2, 790);
    numberFont.drawString(niceFloatToString(humidVal, PRECISION_3DIGIT), 1180 - humidRect.getWidth()/2, 790);

    
    
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

void TempHumidSensor::setTempHumidVal(float ambT, float objT, float hum){
    ambTempVal = ambT;
    objTempVal = objT;
    humidVal = hum;
}
