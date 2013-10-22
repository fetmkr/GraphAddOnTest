//
//  ofxPlotSlider.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/22/13.
//
//

#include "ofxPlotSlider.h"

ofxPlotSlider::ofxPlotSlider(){
    bWasSetup = false;
}

ofxPlotSlider::~ofxPlotSlider(){
    clearEvents();
}

void ofxPlotSlider::clearEvents(){
    if(bWasSetup){
		ofRemoveListener(ofEvents().draw, this, &ofxPlotSlider::draw);
		ofRemoveListener(ofEvents().mouseMoved, this, &ofxPlotSlider::mouseMoved);
		ofRemoveListener(ofEvents().mousePressed, this, &ofxPlotSlider::mousePressed);
		ofRemoveListener(ofEvents().mouseReleased, this, &ofxPlotSlider::mouseReleased);
		ofRemoveListener(ofEvents().mouseDragged, this, &ofxPlotSlider::mouseDragged);
	}
	bWasSetup = false;
}

void ofxPlotSlider::setup(float x, float y, float width){
    sliderPosX = x;
    sliderPosY = y;
    sliderWidth = width;
    bHasFocus = false;
    // default bar circle setting 
    setBar(ofColor(255,0,0), 10.0);
    barPosX = sliderPosX;
    barPosY = 0.0;
    
    if(!bWasSetup){
		ofAddListener(ofEvents().draw, this, &ofxPlotSlider::draw);
		ofAddListener(ofEvents().mouseMoved, this, &ofxPlotSlider::mouseMoved);
		ofAddListener(ofEvents().mousePressed, this, &ofxPlotSlider::mousePressed);
		ofAddListener(ofEvents().mouseReleased, this, &ofxPlotSlider::mouseReleased);
		ofAddListener(ofEvents().mouseDragged, this, &ofxPlotSlider::mouseDragged);
		bWasSetup = true;
	}
}

void ofxPlotSlider::setBar(ofColor color, float size){
    barColor = color;
    barCircleRadius = size;
}

void ofxPlotSlider::draw(ofEventArgs& event){
    
    ofPushStyle();
    ofPushMatrix();
    ofFill();
    ofSetColor(barColor);
    if(!bHasFocus) ofCircle(barPosX, sliderPosY, barCircleRadius);
    else ofCircle(barPosX, sliderPosY, barCircleRadius * 1.3);
    ofPopMatrix();
    ofPopStyle();
}

void ofxPlotSlider::mouseMoved(ofMouseEventArgs& event){
    bHasFocus = false;
}

void ofxPlotSlider::mouseDragged(ofMouseEventArgs& event){
    if (bHasFocus) {
        updateBarPos(event.x,event.y);

    }
}

void ofxPlotSlider::mousePressed(ofMouseEventArgs& event){
    bHasFocus = false;
    if(isInside(event.x, event.y))
    {
        bHasFocus = true;
        updateBarPos(event.x,event.y);

    }
    
}

void ofxPlotSlider::mouseReleased(ofMouseEventArgs& event){
    if (bHasFocus) {
        if (isInside(event.x, event.y)) {
           updateBarPos(event.x,event.y);
        }
    }
    bHasFocus = false;
}

bool ofxPlotSlider::isInside(float _x, float _y){
    return (ofVec2f(_x, _y).distance(ofVec2f(barPosX, sliderPosY)) < barCircleRadius);
}

void ofxPlotSlider::updateBarPos(float _x, float _y){
    
    if(_x > sliderPosX && _x < sliderPosX+sliderWidth)
    {
        barPosX = _x;
    }
    else if (_x < sliderPosX){
        barPosX = sliderPosX;
    }
    else if ( _x > sliderPosX + sliderWidth){
        barPosX = sliderPosX + sliderWidth;
    }
    

}

