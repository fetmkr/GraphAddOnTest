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

}

void LuxSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofSetColor(255, 255, 255); // change the color based on data
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    ofSetColor(lightIntensity);
    ofSetCircleResolution(80);
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 250);
    
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    button.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    if (button.bIsDragged) {
        if (button.getDragType() == BUTTON_DRAG_UP){
            updateLightIntensity(true);
        }
        else{
            updateLightIntensity(false);
        }
    }
    else
    {
        
    }
    ofPopMatrix();
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("LUX DATA ANALYSIS");
        drawPlots();
    }
}

void LuxSensor::updateLightIntensity(bool bUpDn){
    if(bUpDn){
      lightIntensity+=1.0;
    }
    else {
       lightIntensity-=1.0;
    }
    
    if (lightIntensity >255.0) {
        lightIntensity = 255.0;
    }
    if (lightIntensity <0){
        lightIntensity = 0.0;
    }
}