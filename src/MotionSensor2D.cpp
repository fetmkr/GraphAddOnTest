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
    numberFont.loadFont("HelveticaNeueUltraLight.ttf", 25);
    textFont.loadFont("HelveticaNeueUltraLight.ttf", 23.5);
    
    compassImg.loadImage("motion2D/compass.png");
    compassImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    compassImg.setAnchorPoint(compassImg.getWidth()/2, compassImg.getHeight()/2);
    
    compassBGImg.loadImage("motion2D/motion2DBG.png");
    compassBGImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    //compassBGImg.setAnchorPoint(compassBGImg.getWidth()/2, compassBGImg.getHeight()/2);
    
    MotionSensorPlot.setup("accelerometer", 900, 540);
    MotionSensorPlot.setGrid(ofColor(100), ofColor(100), RECT_GRID_DISPLAY);
    MotionSensorPlot.setLineStyle(LINE_ONLY);
    MotionSensorPlot.setTimeScale(1.0);
    MotionSensorPlot.showTimeValue(true);
    MotionSensorPlot.showMenu(true);
    
    MotionSensorHistoryPlot.setup("accel history", 900, 160);
    MotionSensorHistoryPlot.setGrid(ofColor(100), ofColor(100), RECT_DISPLAY_ONLY);
    MotionSensorHistoryPlot.setLineStyle(LINE_ONLY);
    MotionSensorHistoryPlot.setTimeScale(30.0);
    MotionSensorHistoryPlot.showTimeValue(true);
    MotionSensorHistoryPlot.showSlider(true);
    MotionSensorHistoryPlot.showMenu(true);

    
    AccelXLine.setup("X", ofColor(255,0,0));
    AccelYLine.setup("Y", ofColor(0,255,0));
    AccelZLine.setup("Z", ofColor(0,0,255));
    
    GyroXLine.setup("X", ofColor(255,255,0));
    GyroYLine.setup("Y", ofColor(0,255,255));
    GyroZLine.setup("Z", ofColor(255,0,255));
    
    MotionSensorPlot.addLine(&AccelXLine);
    MotionSensorPlot.addLine(&AccelYLine);
    MotionSensorPlot.addLine(&AccelZLine);
    
    MotionSensorPlot.addLine(&GyroXLine);
    MotionSensorPlot.addLine(&GyroYLine);
    MotionSensorPlot.addLine(&GyroZLine);
    
    MotionSensorHistoryPlot.addLine(&AccelXLine);
    MotionSensorHistoryPlot.addLine(&AccelYLine);
    MotionSensorHistoryPlot.addLine(&AccelZLine);
    
    MotionSensorHistoryPlot.addLine(&GyroXLine);
    MotionSensorHistoryPlot.addLine(&GyroYLine);
    MotionSensorHistoryPlot.addLine(&GyroZLine);

}

void MotionSensor2D::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        
    }
    ofPushStyle();
    
    // paint white to prevent the images from tinting
    ofSetColor(255, 255, 255);
    
    compassBGImg.draw(0, 0);
    
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofRotateZ(int(ofGetElapsedTimeMillis()/30)%360); // convert data value to rotation value
    compassImg.draw(0, 0);
    ofPopMatrix();
    
    ofSetCircleResolution(80);
    
    // draw center circle
    ofPushMatrix();
    ofTranslate(20, 20); // convert data value to coordinate
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
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
    ofRotateZ(-30); // convert data value to rotataion
    ofSetColor(5, 5, 229);
    ofCircle(0, 0, 45);
    ofSetLineWidth(1);
    ofSetColor(244, 15, 70);
    ofLine(-45, 0, 45, 0);
    ofPopMatrix();
    
    // draw right circle
    ofPushMatrix();
    ofTranslate(1350, 490);
    ofRotateZ(30); // convert data value to rotataion
    ofSetColor(5, 5, 229);
    ofCircle(0, 0, 45);
    ofSetLineWidth(1);
    ofSetColor(244, 15, 70);
    ofLine(-45, 0, 45, 0);
    ofPopMatrix();
    
    // draw center cross
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofSetLineWidth(1);
    ofSetColor(244, 15, 70);
    ofLine(-75, 0, 75, 0);
    ofRotateZ(90);
    ofLine(-75, 0, 75, 0);
    ofPopMatrix();
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("MOTION DATA ANALYSIS");
        MotionSensorPlot.draw(200 ,200);
        MotionSensorHistoryPlot.draw(200, 780);
    }

}