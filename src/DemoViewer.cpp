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
    indoorBG.setImageType(OF_IMAGE_COLOR_ALPHA);
    
    cupImg.loadImage("indoor/cup.png");
    cupImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    
    outdoorBG.loadImage("outdoor/outdoor.png");
    outdoorBG.setImageType(OF_IMAGE_COLOR_ALPHA);
    
    streeLightImg.loadImage("outdoor/streetlight.png");
    streeLightImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    streeLightImg.setAnchorPoint(35, 588);
    
    etriLogo.loadImage("etri_logo_color.png");



}

void DemoViewer::draw(LightDemoType demoType){
    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    
    if (demoType != DEMO_NODEMO) {
        ofSetColor(0, 0, 0,200);
        ofRect(posX, posY, 1600, 900);
        ofSetColor(255, 255, 255);
        etriLogo.draw(200, 125);
    }
    
    if (demoType == DEMO_INDOOR) {
        
        indoorBG.draw(posX, posY);
        
        cupImg.draw(460+posX, 640+posY);
    }
    else if (demoType == DEMO_OUTDOOR){
        ofPushMatrix();
        ofTranslate(286 + posX, 728 + posY);
        ofRotateZ(0);
        streeLightImg.draw(0, 0);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(1134 + posX, 728 + posY);
        ofRotateZ(0);
        streeLightImg.draw(0, 0);
        ofPopMatrix();
        
        outdoorBG.draw(posX, posY);
    }
    
    ofPopStyle();
}