//
//  Sensor.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/25/13.
//
//

#include "Sensor.h"

Sensor::Sensor(){
    
}

Sensor::~Sensor(){
    
}

void Sensor::setup(){
    analFont.loadFont("SimKBRg.ttf", 35);
    etriLogoBlk.load("etri_logo_black.svg");
}

void Sensor::drawAnalBG(string name){
    // draw analysis window
    ofSetColor(0, 0, 0,200);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRect(160, 90, 1600, 900);
    ofSetColor(255);
    analFont.drawString(name, 400, 170);
    ofSetColor(0);
    analFont.drawString("GRAPH", 200 +900 + 20 + 5, 170);
    analFont.drawString("ON TIME", 200 +900 + 20 + 128 + 20 + 5, 170);
    ofSetColor(255);
    analFont.drawString(getTimeStamp(ofGetElapsedTimeMillis()), 200 +900 + 20 + 128 + 20 + 280, 170);
    
    ofPushMatrix();
    ofTranslate(200, 125);
    ofScale(0.8, 0.8);
    etriLogoBlk.draw();
    ofPopMatrix();
    
    ofNoFill();
    ofSetColor(0);
    ofRect(160, 90, 1600, 900);
    
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //ofSetColor(244, 15, 70);
    ofSetColor(0,0,0,150);
    ofRect(160, 90, 7, 7);
    ofRect(160+1600, 90, 7, 7);
    ofRect(160, 90+900, 7, 7);
    ofRect(160+1600, 90+900, 7, 7);
    
    ofSetColor(0, 0, 0);
    ofLine(200, 110, 200+900, 110);
    ofRect(200, 110, 6, 6);
    ofRect(200+900, 110, 6, 6);
    
    ofSetColor(0, 0, 0);
    ofLine(200 +900 + 20, 110, 200 +900 + 20 + 128, 110);
    ofRect(200 +900 + 20, 110, 6, 6);
    ofRect(200 +900 + 20 + 128, 110, 6, 6);
    
    ofSetColor(100);
    ofLine(200 +900 + 20, 200, 200 +900 + 20 + 128, 200);
    ofRect(200 +900 + 20, 200, 4, 4);
    ofRect(200 +900 + 20 + 128, 200, 4, 4);
    
    ofLine(200 +900 + 20, 780, 200 +900 + 20 + 128, 780);
    ofRect(200 +900 + 20, 780, 4, 4);
    ofRect(200 +900 + 20 + 128, 780, 4, 4);
    
    
    ofSetColor(0, 0, 0);
    ofLine(200 +900 + 20 + 128 + 20, 110, 200 +900 + 20 + 128 + 20 +460, 110);
    ofRect(200 +900 + 20 + 128 + 20, 110, 6, 6);
    ofRect(200 +900 + 20 + 128 + 20 +460, 110, 6, 6);
    
    ofSetColor(100);
    ofLine(200 +900 + 20 + 128 + 20, 200, 200 +900 + 20 + 128 + 20 +460, 200);
    ofRect(200 +900 + 20 + 128 + 20, 200, 4, 4);
    ofRect(200 +900 + 20 + 128 + 20 +460, 200, 4, 4);
    
    ofSetRectMode(OF_RECTMODE_CORNER);

}
