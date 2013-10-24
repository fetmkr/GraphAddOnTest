//
//  ofxPlotButton.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/24/13.
//
//

#include "ofxPlotButton.h"


ofxPlotButton::ofxPlotButton(){
    bWasSetup = false;
}

ofxPlotButton::~ofxPlotButton(){
    clearEvents();
}

void ofxPlotButton::setup(float width, float height, bool bToggle, bool bDefaultVal){
    buttonWidth = width;
    buttonHeight = height;
    buttonRect = ofRectangle(0, 0, buttonWidth, buttonHeight);

    bToggleButton = bToggle;
    bIsPressed = bDefaultVal;
    bHasFocus = false;
    
    if(!bWasSetup){
        ofRegisterMouseEvents(this);
//        ofAddListener(ofEvents().mouseMoved, this, &ofxPlotButton::mouseMoved);
//        ofAddListener(ofEvents().mousePressed, this, &ofxPlotButton::mousePressed);
//        ofAddListener(ofEvents().mouseReleased, this, &ofxPlotButton::mouseReleased);
//        ofAddListener(ofEvents().mouseDragged, this, &ofxPlotButton::mouseDragged);
		bWasSetup = true;
	}
}





void ofxPlotButton::clearEvents(){
    if(bWasSetup){
        ofUnregisterMouseEvents(this);
//        ofRemoveListener(ofEvents().mouseMoved, this, &ofxPlotButton::mouseMoved);
//        ofRemoveListener(ofEvents().mousePressed, this, &ofxPlotButton::mousePressed);
//        ofRemoveListener(ofEvents().mouseReleased, this, &ofxPlotButton::mouseReleased);
//        ofRemoveListener(ofEvents().mouseDragged, this, &ofxPlotButton::mouseDragged);
	}
	bWasSetup = false;
}

void ofxPlotButton::draw(float x, float y){
    transX = x;
    transY = y;
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(transX, transY);
    //ofSetRectMode(OF_RECTMODE_CENTER);

    if(bIsPressed){
        ofFill();
        ofSetColor(100);
        ofRect(buttonRect); 
    }
    
    ofNoFill();
    ofSetColor(0);
    ofRect(buttonRect);
    //ofSetRectMode(OF_RECTMODE_CORNER);

    ofPopMatrix();
    ofPopStyle();
    
}

void ofxPlotButton::resize(float width, float height){
    buttonWidth = width;
    buttonHeight = height;
    buttonRect.setWidth(width);
    buttonRect.setHeight(height);
}

bool ofxPlotButton::isPressed(){
    return bIsPressed;
}

void ofxPlotButton::mouseMoved(ofMouseEventArgs& event){
    bHasFocus = false;
}

void ofxPlotButton::mouseDragged(ofMouseEventArgs& event){
    
}

void ofxPlotButton::mousePressed(ofMouseEventArgs& event){
    bHasFocus = false;
    if(buttonRect.inside(event.x-transX, event.y-transY))
    {
        bHasFocus = true;
        if (bToggleButton) {
            bIsPressed = !bIsPressed;
        }
        else{
            bIsPressed = true;
        }
    }
}

void ofxPlotButton::mouseReleased(ofMouseEventArgs& event){
    if (bHasFocus) {
        //if (buttonRect.inside(event.x-transX, event.y-transY)) {
        if (bToggleButton) {
        }
        else{
            bIsPressed = false;
        }

        //}
    }
    bHasFocus = false;
}



