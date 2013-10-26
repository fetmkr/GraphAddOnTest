//
//  MotionSensor3D.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#include "MotionSensor3D.h"

MotionSensor3D::MotionSensor3D(){
    
}

MotionSensor3D::~MotionSensor3D(){
    
}

void MotionSensor3D::setup(){
    Sensor::setup();
    motion3DBGImg.loadImage("motion3D/motion3DBG.png");
    motion3DBGImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    

    compass3D.loadModel("motion3D/motion3d.dae", true);
    compass3D.setScale(0.5, 0.5, 0.5);
    
    // how is the assimp model loader works on scaling??
    crossModel.loadModel("motion3D/cross.dae", true);
    // 150 pixel cross size vs 366 pixel circle size
    crossModel.setScale(float(150.0/366.0)*0.5, float(150.0/366.0)*0.5, float(150.0/366.0)*0.5);
    
    viewport = ofRectangle((ofGetWindowWidth()-500.0)/2, (ofGetWindowHeight()-500.0)/2 -30, 500, 500);
    //cam.setupPerspective();
    // how to set z position ?? 
    cam.setPosition(0, 0, 500);
}

void MotionSensor3D::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        
    }
    ofSetColor(255, 255, 255);
    motion3DBGImg.draw(0, 0);

    
    ofPushStyle();

    cam.begin(viewport);
    ofEnableDepthTest();

    // to give better 3D-ness
    // tilt them a little 
    ofRotateY(ofRadToDeg(-0.1));
    ofRotateX(ofRadToDeg(.5));
    
    glShadeModel(GL_SMOOTH); //some model / light stuff
    //    light.enable();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    
    ofEnableSeparateSpecularLight();
    
    ofPushMatrix();
    ofRotateX(-90);
    crossModel.drawFaces();
    ofPopMatrix();
    
    
    //ofRotateZ(-20);
    ofRotateY(-20);
    ofPushMatrix();
    ofRotateX(-90);
    ofRotateZ(180);
    compass3D.drawFaces();
    ofPopMatrix();
    
    
    ofDisableDepthTest();
    cam.end();
    
    // draw camera viewport
    ofNoFill();
    ofSetColor(0);
    ofRect(viewport);
    
    ofPopStyle();
        
    if (visualType == VISUAL_SIENCE){

    }
    
}