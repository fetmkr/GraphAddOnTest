//
//  ColorSensor.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#include "ColorSensor.h"

ColorSensor::ColorSensor(){
    
}

ColorSensor::~ColorSensor(){
    
}

void ColorSensor::setup(){
    Sensor::setup();
    setupColorPicker(520, 520);
}

void ColorSensor::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofRotateZ(45);
    colorPicker.draw(0, 0);
    ofPopMatrix();
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("COLOR DATA ANALYSIS");
        drawPlots();
    }
    
}

void ColorSensor::setupColorPicker(int width, int height){
    float w = width;
    float h = height;
    float cx = w/2;
    float cy = h/2;
    
    colorPicker.allocate(w,h,OF_IMAGE_COLOR);
    colorPicker.setAnchorPoint(w/2, h/2);
    
    for (float y=0; y<h; y++) {
        for (float x=0; x<w; x++) {
            
//            float angle = atan2(y-cy,x-cy)+PI; // HSB
            float angle = atan2(y-w/2,x-h/2)+PI; // Hue
//            float dist = ofDist(x,y,cx,cy);
//            float hue = angle/TWO_PI*255;
//            float sat = ofMap(dist,0,w/4,0,255,true);
//            float bri = ofMap(dist,w/4,w/2,255,0,true);
            
//            colorPicker.setColor(x,y,ofColor::fromHsb(hue,sat,bri)); // HSB
            colorPicker.setColor(x,y,ofColor::fromHsb(angle/TWO_PI*255,255,255)); // Hue
        }
    }
    colorPicker.update();
}

ofColor ColorSensor::pickColor(int x, int y){
    
    float red;
    float green;
    float blue;
    
    red = colorPicker.getColor(x, y).r;
	green = colorPicker.getColor(x, y).g;
	blue = colorPicker.getColor(x, y).b;
    
    return ofColor(red,green,blue);
}