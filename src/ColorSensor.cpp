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
    colorPicker.loadImage("colorSensor/HueGradient.png");
    colorPicker.setImageType(OF_IMAGE_COLOR_ALPHA);
    colorPicker.setAnchorPoint(colorPicker.getWidth()/2, colorPicker.getHeight()/2);
    //setupColorPicker(600, 600);
    button.setup(500, 500, true, false,BUTTON_SHAPE_CIRCLE);
    button.showButton(false ,false);
}
void ColorSensor::reset(){
    button.setPressed(false);
}

void ColorSensor::draw(LightSensorType sensorType, LightVisualType visualType){

    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    ofSetColor(255, 0, 0); // change the color based on data
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    colorPicker.draw(0, 0);
    ofPopMatrix();
    
    ofPushMatrix();
    button.draw(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    if (button.isPressed()) {
        //cout << "pressed" << endl;
//        button.setPressedColor(pickColor(button.getMouseXY().x - (ofGetWindowWidth()-colorPicker.getWidth())/2, button.getMouseXY().y -(ofGetWindowHeight()- colorPicker.getHeight())/2));
//        button.setReleasedColor(pickColor(button.getMouseXY().x - (ofGetWindowWidth()-colorPicker.getWidth())/2, button.getMouseXY().y -(ofGetWindowHeight()- colorPicker.getHeight())/2));
        button.setPressedColor(selectedColor);
        button.setReleasedColor(selectedColor);
        
        button.showButton(true, true);

        
    }
    else
    {
        button.showButton(false,false);
        if(button.bIsMoveInside){
            selectedColor = pickColor(button.getMouseXY().x - (ofGetWindowWidth()-colorPicker.getWidth())/2, button.getMouseXY().y -(ofGetWindowHeight()- colorPicker.getHeight())/2);
        }
        ofSetColor(0, 0, 0);
        ofNoFill();
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofRectRounded(button.getMouseXY().x, button.getMouseXY().y, 25, 25, 3);
        //ofRect(button.getMouseXY().x, button.getMouseXY().y, 30, 30);
        ofSetRectMode(OF_RECTMODE_CORNER);
        //cout << "not pressed" << endl;
    }
    ofPopMatrix();
   
    ofPopStyle();
    
    if (visualType == VISUAL_GRAPHIC) {
        drawInfo(200, 125);
    }
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("COLOR DATA ANALYSIS");
        drawPlots();
    }
    
    
}

// draw with the code
//void ColorSensor::setupColorPicker(int width, int height){
//    float w = width;
//    float h = height;
//    float cx = w/2;
//    float cy = h/2;
//    
//    colorPicker.allocate(w,h,OF_IMAGE_COLOR);
//    colorPicker.setAnchorPoint(w/2, h/2);
//    
//    for (float y=0; y<h; y++) {
//        for (float x=0; x<w; x++) {
//            
//              // HSB          
////            float angle = atan2(y-cy,x-cy)+PI; 
////            float dist = ofDist(x,y,cx,cy); 
////            float hue = angle/TWO_PI*255;
////            float sat = ofMap(dist,0,w/4,0,255,true);
////            float bri = ofMap(dist,w/4,w/2,255,0,true);
////            colorPicker.setColor(x,y,ofColor::fromHsb(hue,sat,bri));
//
//            // Hue
//            // http://en.wikipedia.org/wiki/Atan2#Definition_and_computation
//
//            float angle = atan2(y-cy,x-cx)+PI;
//            colorPicker.setColor(x,y,ofColor::fromHsb(angle/TWO_PI*255,255,255));
//
//        }
//    }
//    colorPicker.update();
//}

ofColor ColorSensor::pickColor(int x, int y){
    
    float red;
    float green;
    float blue;
    
    red = colorPicker.getColor(x, y).r;
	green = colorPicker.getColor(x, y).g;
	blue = colorPicker.getColor(x, y).b;
    
    return ofColor(red,green,blue);
}

ofColor ColorSensor::getCompColor(ofColor c){
    ofColor compColor;
    
    compColor.r = 255 - c.r;
    compColor.g = 255 - c.g;
    compColor.b = 255 - c.b;
    
    return compColor;
}