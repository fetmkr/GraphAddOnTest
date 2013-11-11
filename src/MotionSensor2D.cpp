//
//  MotionSensor2D.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/25/13.
//
//

#include "MotionSensor2D.h"

MotionSensor2D::MotionSensor2D(){
    
}

MotionSensor2D::~MotionSensor2D(){
    
}

void MotionSensor2D::setup(){
    Sensor::setup();
    setBGImg("motion2D/motion2DBG.png");
    
    compassImg.loadImage("motion2D/compass.png");
    compassImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    compassImg.setAnchorPoint(compassImg.getWidth()/2, compassImg.getHeight()/2);
    accelX = 0.0;
    accelY = 0.0;
    accelZ = 0.0;
    compassVal = 0.0;
}


void MotionSensor2D::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        drawInfo(200, 125);
    }
    ofPushStyle();
    
    // paint white to prevent the images from tinting
    ofSetColor(255, 255, 255);
    
    drawBGImg(0, 0);
    
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, 490);
//    ofRotateZ(int(ofGetElapsedTimeMillis()/30)%360); // convert data value to rotation value
    ofRotateZ(compassVal); // convert data value to rotation value
    compassImg.draw(0, 0);
    ofPopMatrix();
    
    ofSetCircleResolution(80);
    
    // draw center circle
    ofPushMatrix();
    // map value to screen
    ofTranslate(accelY * 2.0, accelX * 2.0); // convert data value to coordinate
    ofTranslate(ofGetWindowWidth()/2, 490);
    ofSetColor(5, 5, 229);
    ofCircle(0, 0, 75);
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    ofLine(-18, 0, 18, 0);
    ofRotateZ(90);
    ofLine(-18, 0, 18, 0);
    ofPopMatrix();
    
    
    // draw left circle
    ofPushMatrix();
    ofTranslate(570, 490);
    ofRotateZ(ofMap(accelY*(-1.0), -20.0, 20.0, -90, 90)); // convert data value to rotataion
    ofSetColor(5, 5, 229);
    ofCircle(0, 0, 45);
    ofSetLineWidth(1);
    ofSetColor(244, 15, 70);
    ofLine(-45, 0, 45, 0);
    ofPopMatrix();
    
    // draw right circle
    ofPushMatrix();
    ofTranslate(1350, 490);
    ofRotateZ(ofMap(accelX*(-1.0), -20.0, 20.0, -90, 90)); // convert data value to rotataion
    ofSetColor(5, 5, 229);
    ofCircle(0, 0, 45);
    ofSetLineWidth(1);
    ofSetColor(244, 15, 70);
    ofLine(-45, 0, 45, 0);
    ofPopMatrix();
    
    // draw center cross
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, 490);
    ofSetLineWidth(1);
    ofSetColor(244, 15, 70);
    ofLine(-75, 0, 75, 0);
    ofRotateZ(90);
    ofLine(-75, 0, 75, 0);
    ofPopMatrix();
    
    ofSetColor(0, 0, 0);
    ofRectangle accelYRect = numberFont.getStringBoundingBox(niceFloatToString(accelY, PRECISION_1DIGIT), 0, 0);
    ofRectangle accelXRect = numberFont.getStringBoundingBox(niceFloatToString(accelX, PRECISION_1DIGIT), 0, 0);
    ofRectangle compassRect = numberFont.getStringBoundingBox(niceFloatToString(accelY, PRECISION_1DIGIT), 0, 0);

    numberFont.drawString(niceFloatToString(accelY, PRECISION_1DIGIT), 570 - accelYRect.getWidth()/2, 790);
    numberFont.drawString(niceFloatToString(accelX, PRECISION_1DIGIT), 1350 - accelXRect.getWidth()/2, 790);
    numberFont.drawString(niceFloatToString(compassVal, PRECISION_1DIGIT), 960 - compassRect.getWidth()/2, 790);
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("MOTION DATA ANALYSIS 2D");

        drawPlots();
    }

}

void MotionSensor2D::setAccelVal(float x, float y, float z){
    accelX = x;
    accelY = y;
    accelZ = z;
}

void MotionSensor2D::setCompassVal(float val){
    compassVal = val;
}
