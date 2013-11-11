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


    brightLevel = 0.0;
    luxVal = 255.0;
    cupTemp = 0.0;
    streetRotY = 0.0;
    streetRotZ = 0.0;
}

void DemoViewer::draw(LightDemoType demoType){
    
    float light;
    light = ofClamp(brightLevel + luxVal, 0.0, 255.0);
    ofPushStyle();
    ofSetColor(255, 255, 255);
    
    if (demoType != DEMO_NODEMO) {
        ofSetColor(0, 0, 0,200);
        ofRect(posX, posY, 1600, 900);
        ofSetColor(255, 255, 255);
        etriLogo.draw(200, 125);
    }
    
    if (demoType == DEMO_INDOOR) {
        
        ofSetColor(light, light, light);
        indoorBG.draw(posX, posY);
        ofSetColor(ofColor::fromHsb(ofMap(cupTemp*2.0, 0.0, 100.0, 60, 0),255 ,255));
        cupImg.draw(460+posX, 640+posY);
        ofSetColor(255, 255, 255);
    }
    else if (demoType == DEMO_OUTDOOR){
        ofSetColor(light, light, light);
        ofPushMatrix();
        ofTranslate(286 + posX, 728 + posY);
        ofRotateX(streetRotY);
        ofRotateZ(streetRotZ * -1.0);
        streeLightImg.draw(0, 0);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(1134 + posX, 728 + posY);
        ofRotateX(streetRotY);
        ofRotateZ(streetRotZ * -1.0);
        streeLightImg.draw(0, 0);
        ofPopMatrix();
        outdoorBG.draw(posX, posY);
        ofSetColor(255, 255, 255);
    }
    
    ofPopStyle();
}

void DemoViewer::setDemoVal(float bright, float lux, float cupT, float RotY, float RotZ){
    brightLevel = bright;
    luxVal = lux;
    cupTemp = cupT;
    streetRotY = RotY;
    streetRotZ = RotZ;
}