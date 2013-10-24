#include "testApp.h"

// better way to use ofPtr ???
// maybe we don't need ofPtr for the lines
// we can just use normal pointer like advanced3d example used pointer for cameras?

//ofPtr<ofxPlotLine> AccelXLine(new ofxPlotLine);
//ofPtr<ofxPlotLine> AccelYLine(new ofxPlotLine);
//ofPtr<ofxPlotLine> AccelZLine(new ofxPlotLine);

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    motionSensor.setup();  
    sensorType = SENSOR_MOTION_2D;
    
    }

//--------------------------------------------------------------
void testApp::update(){
    
    // fake data
    float xtemp, ytemp,ztemp;
    xtemp = 0.0;
    ytemp = 0.0;
    ztemp = 0.0;
    
    xtemp = xtemp + ofSignedNoise(30*ofGetElapsedTimef()*1.0f)*20.0f;
    ytemp = ytemp + ofSignedNoise(50*ofGetElapsedTimef()*1.0f)*40.0f;
    ztemp = ztemp + ofSignedNoise(10*ofGetElapsedTimef()*1.0f)*30.0f;

    motionSensor.AccelXLine.addData(xtemp);
    motionSensor.AccelYLine.addData(ytemp);
    motionSensor.AccelZLine.addData(ztemp);
    motionSensor.GyroXLine.addData(xtemp);
    motionSensor.GyroYLine.addData(ytemp);
    motionSensor.GyroZLine.addData(ztemp);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);

    
    switch (sensorType) {
        case SENSOR_TOUCH:
            break;
        case SENSOR_MOTION_2D:
            motionSensor.draw(sensorType,visualType);
            break;
        case SENSOR_MOTION_3D:
            break;
        case SENSOR_PRESSURE_ALTITUDE:
            break;
        case SENSOR_TEMP_HUMIDITY:
            break;
        case SENSOR_COLOR:
            break;
        case SENSOR_LUX:
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch(key){
        case ' ':
            visualType = VISUAL_SIENCE;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch(key){
        case ' ':
            visualType = VISUAL_GRAPHIC;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

