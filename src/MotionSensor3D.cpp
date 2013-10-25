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
    compass3D.loadModel("motion3D/motion3d.dae", true);
    compass3D.setScale(0.5, 0.5, 0.5);
}

void MotionSensor3D::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        
    }
    ofPushStyle();
    
    
    cam.begin();
    
    ofEnableDepthTest();
    
    glShadeModel(GL_SMOOTH); //some model / light stuff
    //    light.enable();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    
    ofEnableSeparateSpecularLight();
    
    ofRotateZ(-20);
    
    ofPushMatrix();
    ofRotateX(-90);
    ofRotateZ(180);
    compass3D.drawFaces();
    ofPopMatrix();
    
    
    cam.end();
    
    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){

    }
    
}