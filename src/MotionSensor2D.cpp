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

    
    compassImg.loadImage("motion2D/compass.png");
    compassImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    compassImg.setAnchorPoint(compassImg.getWidth()/2, compassImg.getHeight()/2);
    
    compassBGImg.loadImage("motion2D/motion2DBG.png");
    compassBGImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    //compassBGImg.setAnchorPoint(compassBGImg.getWidth()/2, compassBGImg.getHeight()/2);

}

void MotionSensor2D::addLine(ofxPlotLine* line){
    shortPlot.addLine(line);
    longPlot.addLine(line);
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
        shortPlot.draw(200 ,200);
        longPlot.draw(200, 780);
    }

}