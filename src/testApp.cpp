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
    
    AccelXLine.setup("X", ofColor(255,0,0));
    AccelYLine.setup("Y", ofColor(0,255,0));
    AccelZLine.setup("Z", ofColor(0,0,255));
    GyroXLine.setup("X", ofColor(255,255,0));
    GyroYLine.setup("Y", ofColor(0,255,255));
    GyroZLine.setup("Z", ofColor(255,0,255));

    // setup before add the lines
    // otherwise the button will not be shown
    motionSensor2D.setup();
    motionSensor3D.setup();
    pressAltSensor.setup();
    touchSensor.setup();
    
    motionSensor2D.addLine(&AccelXLine);
    motionSensor2D.addLine(&AccelYLine);
    motionSensor2D.addLine(&AccelZLine);
    motionSensor2D.addLine(&GyroXLine);
    motionSensor2D.addLine(&GyroYLine);
    motionSensor2D.addLine(&GyroZLine);
    
    motionSensor3D.addLine(&AccelXLine);
    motionSensor3D.addLine(&AccelYLine);
    motionSensor3D.addLine(&AccelZLine);
    motionSensor3D.addLine(&GyroXLine);
    motionSensor3D.addLine(&GyroYLine);
    motionSensor3D.addLine(&GyroZLine);

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

    AccelXLine.addData(xtemp);
    AccelYLine.addData(ytemp);
    AccelZLine.addData(ztemp);
    GyroXLine.addData(xtemp);
    GyroYLine.addData(ytemp);
    GyroZLine.addData(ztemp);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);

    switch (sensorType) {
        case SENSOR_TOUCH:
            touchSensor.draw(sensorType, visualType);
            break;
        case SENSOR_MOTION_2D:
            motionSensor2D.draw(sensorType,visualType);
            break;
        case SENSOR_MOTION_3D:
            motionSensor3D.draw(sensorType, visualType);
            break;
        case SENSOR_PRESSURE_ALTITUDE:
            pressAltSensor.draw(sensorType, visualType);
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
        case 'q':
            sensorType = SENSOR_MOTION_2D;
            break;
        case 'w':
            sensorType = SENSOR_MOTION_3D;
            break;
        case 'e':
            sensorType = SENSOR_PRESSURE_ALTITUDE;
            break;
        case 'r':
            sensorType = SENSOR_TOUCH;
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

