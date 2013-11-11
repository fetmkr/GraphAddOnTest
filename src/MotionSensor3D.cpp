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
    setBGImg("motion3D/motion3DBG.png");

    

    compass3D.loadModel("motion3D/motion3d.dae", true);
    compass3D.setScale(0.5, 0.5, 0.5);
    
    // how is the assimp model loader works on scaling??
    crossModel.loadModel("motion3D/cross.dae", true);
    // 150 pixel cross size vs 366 pixel circle size
    crossModel.setScale(float(150.0/366.0)*0.5, float(150.0/366.0)*0.5, float(150.0/366.0)*0.5);
    
    viewport = ofRectangle((ofGetWindowWidth()-500.0)/2, (ofGetWindowHeight()-500.0)/2 -30, 500, 500);
    //cam.setupPerspective();
    // how to set z position properly?? 
    cam.setPosition(0, 0, 500);
    gyroX = 0.0;
    gyroY = 0.0;
    gyroZ = 0.0;
    
}

void MotionSensor3D::draw(LightSensorType sensorType, LightVisualType visualType){
    if (visualType == VISUAL_GRAPHIC) {
        drawInfo(200, 125);   
    }

    
    ofPushStyle();
    ofSetColor(255, 255, 255);
    drawBGImg(0, 0);
    cam.begin(viewport);
    ofEnableDepthTest();

    // to give better 3D-ness
    // tilt them a little 
    ofRotateY(ofRadToDeg(-0.1));
    ofRotateX(ofRadToDeg(.5));
    
    glShadeModel(GL_SMOOTH); //some model / light stuff
//    light.enable(); ofLight is not working for diffuse lighting of the model
    
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    
    ofEnableSeparateSpecularLight();
    
    ofPushMatrix();
    ofRotateX(-90);
    crossModel.drawFaces();
    ofPopMatrix();
    
    
    ofRotateY(gyroZ * -10.0); // around screen Y axis: pitch
    ofRotateX(gyroY * -10.0); // around screen X axis: roll
    ofRotateZ(gyroX * -10.0); // around screen Z axis: pitch

    ofPushMatrix();
    ofRotateX(-90);
    ofRotateZ(180);
    compass3D.drawFaces();
    ofPopMatrix();
    
    ofDisableSeparateSpecularLight();
    ofDisableDepthTest();
    
    // disable the lighting or it will affect the rests of the drawing
    glDisable(GL_LIGHT0);
    glDisable(GL_NORMALIZE);
    glDisable(GL_LIGHTING);
    cam.end();
    
    // draw camera viewport
//    ofNoFill();
//    ofSetColor(0);
//    ofRect(viewport);
    
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(0, 0, 0);
    ofRectangle gyroXRect = numberFont.getStringBoundingBox(niceFloatToString(gyroX, PRECISION_3DIGIT), 0, 0);
    ofRectangle gyroYRect = numberFont.getStringBoundingBox(niceFloatToString(gyroY, PRECISION_3DIGIT), 0, 0);
    ofRectangle gyroZRect = numberFont.getStringBoundingBox(niceFloatToString(gyroZ, PRECISION_3DIGIT), 0, 0);
    
    numberFont.drawString(niceFloatToString(gyroX, PRECISION_3DIGIT), 580 - gyroXRect.getWidth()/2, 790);
    numberFont.drawString(niceFloatToString(gyroY, PRECISION_3DIGIT), 960 - gyroYRect.getWidth()/2, 790);
    numberFont.drawString(niceFloatToString(gyroZ, PRECISION_3DIGIT), 1360 - gyroZRect.getWidth()/2, 790);


    ofPopStyle();
    
    if (visualType == VISUAL_SIENCE){
        drawAnalBG("MOTION DATA ANALYSIS 3D");
        drawPlots();

    }
    
}

void MotionSensor3D::setGyroVal(float x, float y, float z){
    gyroX = x; // yaw
    gyroY = y; // roll
    gyroZ = z; // pitch 
}