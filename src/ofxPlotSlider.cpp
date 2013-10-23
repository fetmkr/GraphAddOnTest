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
		ofRemoveListener(ofEvents().mouseMoved, this, &ofxPlotSlider::mouseMoved);
		ofRemoveListener(ofEvents().mousePressed, this, &ofxPlotSlider::mousePressed);
		ofRemoveListener(ofEvents().mouseReleased, this, &ofxPlotSlider::mouseReleased);
		ofRemoveListener(ofEvents().mouseDragged, this, &ofxPlotSlider::mouseDragged);
	}
	bWasSetup = false;
}

void ofxPlotSlider::setup(float width){

    sliderWidth = width;
    bHasFocus = false;
    // default bar circle setting 
    setBar(ofColor(255,0,0), 10.0);

    
    if(!bWasSetup){
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

void ofxPlotSlider::draw(float x, float y){
    
    ofPushStyle();
    ofPushMatrix();
    transX = x;
    transY = y;
    ofTranslate(transX, transY);
    ofFill();
    ofSetColor(barColor);
    if(!bHasFocus) ofCircle(barPosX, 0, barCircleRadius);
    else ofCircle(barPosX, 0, barCircleRadius * 1.3);
    ofPopMatrix();
    ofPopStyle();
}

void ofxPlotSlider::mouseMoved(ofMouseEventArgs& event){
    bHasFocus = false;
}

void ofxPlotSlider::mouseDragged(ofMouseEventArgs& event){
    if (bHasFocus) {
        updateBarPos(event.x-transX,event.y-transY);

    }
}

void ofxPlotSlider::mousePressed(ofMouseEventArgs& event){
    bHasFocus = false;
    if(isInside(event.x-transX, event.y-transY))
    {
        bHasFocus = true;
        updateBarPos(event.x-transX,event.y-transY);

    }
    
}

void ofxPlotSlider::mouseReleased(ofMouseEventArgs& event){
    if (bHasFocus) {
        if (isInside(event.x-transX, event.y-transY)) {
           updateBarPos(event.x-transX,event.y-transY);
        }
    }
    bHasFocus = false;
}

bool ofxPlotSlider::isInside(float _x, float _y){
    return (ofVec2f(_x, _y).distance(ofVec2f(barPosX, 0)) < barCircleRadius);
}

void ofxPlotSlider::updateBarPos(float _x, float _y){
    
    if(_x > 0 && _x < sliderWidth)
    {
        barPosX = _x;
    }
    else if (_x < 0){
        barPosX = 0;
    }
    else if ( _x > sliderWidth){
        barPosX = sliderWidth;
    }
    

}

