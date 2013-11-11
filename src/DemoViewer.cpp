//
//  DemoViewer.cpp
//  LightingDataVisualizer
//
//  Created by songhojun on 11/11/13.
//
//

#include "DemoViewer.h"

DemoViewer::DemoViewer(){
    
}

DemoViewer::~DemoViewer(){
    
}

void DemoViewer::setup(float x, float y){
    
    posX = x;
    posY = y;
    indoorBG.loadImage("indoor/indoor.png");
    outdoorBG.loadImage("outdoor/outdoor.png");
    
}

void DemoViewer::draw(LightDemoType demoType){
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    
    if (demoType == DEMO_INDOOR) {
        indoorBG.draw(posX, posY);
    }
    else if (demoType == DEMO_OUTDOOR){
        outdoorBG.draw(posX, posY);
    }
    
    ofPopStyle();
}