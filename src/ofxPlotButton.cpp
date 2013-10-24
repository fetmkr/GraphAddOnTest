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

void ofxPlotButton::setup(float width, float height, bool bToggle){
    buttonWidth = width;
    buttonHeight = height;
    bToggleButton = bToggle;
    bHasFocus = false;
    buttonRect = ofRectangle(0, 0, buttonWidth, buttonHeight);

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

bool ofxPlotButton::isPressed(){
    return bIsPressed;
}

void ofxPlotButton::mouseMoved(ofMouseEventArgs& event){
    bHasFocus = false;
}

void ofxPlotButton::mouseDragged(ofMouseEventArgs& event){
    
}

void ofxPlotButton::mousePressed(ofMouseEventArgs& event){
    cout << "teta" << endl;
    bHasFocus = false;
    if(buttonRect.inside(event.x-transX, event.y-transY))
    {
        bHasFocus = true;
        bIsPressed = true;
    }
}

void ofxPlotButton::mouseReleased(ofMouseEventArgs& event){
    if (bHasFocus) {
        if (buttonRect.inside(event.x-transX, event.y-transY)) {
            bIsPressed = false;
        }
    }
    bHasFocus = false;
}


