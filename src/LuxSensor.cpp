//
//  LuxSensor.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#include "LuxSensor.h"

LuxSensor::LuxSensor(){
    
}

LuxSensor::~LuxSensor(){
    
}

void LuxSensor::setup(){
    Sensor::setup();
    button.setup(500, 500, true, false,BUTTON_SHAPE_CIRCLE);
    button.showButton(false);
    lightIntensity = 0.0;
    prevLightLevel = 0.0;
    bDragStarted = false;

}

void LuxSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofSetColor(100, 100, 100); // change the color based on data
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    ofSetColor(lightIntensity);
    ofSetCircleResolution(80);
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 250);
    
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    button.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    if (button.isDragged()) {
        if (bDragStarted) {
            lightIntensity = prevLightLevel;
            bDragStarted = false;
        }
        else{
            updateLightIntensity(button.getDragAmout().y);
        }
//        if (button.getDragType() == BUTTON_DRAG_UP){
//            updateLightIntensity(true);
//        }
//        else if (button.getDragType() == BUTTON_DRAG_DOWN) {
//            updateLightIntensity(false);
//        }
        //cout << button.getDragAmout().y << endl;
    }
    else
    {
//        prevLightLevel = lightIntensity;
//        bDragStarted = true;
    }
    ofPopMatrix();
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("LUX DATA ANALYSIS");
        drawPlots();
    }
}

void LuxSensor::updateLightIntensity(float val){
    lightIntensity = ofMap(val/2.0, -ofGetWindowHeight(), ofGetWindowHeight(), 0.0, 255.0, true);
    //lightIntensity = ofClamp(lightIntensity, 0, 255);
}