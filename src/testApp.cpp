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
    
    analFont.loadFont("SimKBRg.ttf", 35);
    numberFont.loadFont("HelveticaNeueUltraLight.ttf", 25);
    textFont.loadFont("HelveticaNeueUltraLight.ttf", 23.5);
    
    compassImg.loadImage("motion2D/compass.png");
    compassImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    compassImg.setAnchorPoint(compassImg.getWidth()/2, compassImg.getHeight()/2);
    
    compassBGImg.loadImage("motion2D/motion2DBG.png");
    compassBGImg.setImageType(OF_IMAGE_COLOR_ALPHA);
    //compassBGImg.setAnchorPoint(compassBGImg.getWidth()/2, compassBGImg.getHeight()/2);
    
    etriLogoBlk.load("etri_logo_black.svg");
    
    MotionSensorPlot.setup("accelerometer", 900, 540);
    MotionSensorPlot.setGrid(ofColor(100), ofColor(100), RECT_GRID_DISPLAY);
    MotionSensorPlot.setLineStyle(LINE_ONLY);
    MotionSensorPlot.setTimeScale(1.0);
    MotionSensorPlot.showTimeValue(true);
    MotionSensorPlot.showMenu(true);
    
    MotionSensorHistoryPlot.setup("accel history", 900, 160);
    MotionSensorHistoryPlot.setGrid(ofColor(100), ofColor(100), RECT_DISPLAY_ONLY);
    MotionSensorHistoryPlot.setLineStyle(LINE_ONLY);
    MotionSensorHistoryPlot.setTimeScale(30.0);
    MotionSensorHistoryPlot.showTimeValue(true);
    MotionSensorHistoryPlot.showSlider(true);
    

    AccelXLine.setup("X", ofColor(255,0,0));
    AccelYLine.setup("Y", ofColor(0,255,0));
    AccelZLine.setup("Z", ofColor(0,0,255));
    
    GyroXLine.setup("X", ofColor(255,255,0));
    GyroYLine.setup("Y", ofColor(0,255,255));
    GyroZLine.setup("Z", ofColor(255,0,255));
    
    MotionSensorPlot.addLine(&AccelXLine);
    MotionSensorPlot.addLine(&AccelYLine);
    MotionSensorPlot.addLine(&AccelZLine);
    
    MotionSensorPlot.addLine(&GyroXLine);
    MotionSensorPlot.addLine(&GyroYLine);
    MotionSensorPlot.addLine(&GyroZLine);
    
    MotionSensorHistoryPlot.addLine(&AccelXLine);
    MotionSensorHistoryPlot.addLine(&AccelYLine);
    MotionSensorHistoryPlot.addLine(&AccelZLine);
    
    MotionSensorHistoryPlot.addLine(&GyroXLine);
    MotionSensorHistoryPlot.addLine(&GyroYLine);
    MotionSensorHistoryPlot.addLine(&GyroZLine);
    
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
            break;
        case SENSOR_MOTION_2D:
            if (visualType == VISUAL_GRAPHIC) {
                
            }
            ofPushStyle();
            
            // paint white to prevent the images from tinting
            ofSetColor(255, 255, 255);
            
            compassBGImg.draw(0, 0);
            
            ofPushMatrix();
            ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofRotateZ(int(ofGetElapsedTimeMillis()/30)%360); // convert data value to rotation value
            compassImg.draw(0, 0);
            ofPopMatrix();
            
            ofSetCircleResolution(80);

            // draw center circle
            ofPushMatrix();
            ofTranslate(20, 20); // convert data value to coordinate
            ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofSetColor(5, 5, 229);
            ofCircle(0, 0, 75);
            ofSetColor(255, 255, 255);
            ofSetLineWidth(1);
            ofLine(-18, 0, 18, 0);
            ofRotateZ(90);
            ofLine(-18, 0, 18, 0);
            ofPopMatrix();
            

            // draw left circle
            ofPushMatrix();
            ofTranslate(570, 490);
            ofRotateZ(-30); // convert data value to rotataion
            ofSetColor(5, 5, 229);
            ofCircle(0, 0, 45);
            ofSetLineWidth(1);
            ofSetColor(244, 15, 70);
            ofLine(-45, 0, 45, 0);
            ofPopMatrix();
            
            // draw right circle
            ofPushMatrix();
            ofTranslate(1350, 490);
            ofRotateZ(30); // convert data value to rotataion
            ofSetColor(5, 5, 229);
            ofCircle(0, 0, 45);
            ofSetLineWidth(1);
            ofSetColor(244, 15, 70);
            ofLine(-45, 0, 45, 0);
            ofPopMatrix();
            
            // draw center cross
            ofPushMatrix();
            ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofSetLineWidth(1);
            ofSetColor(244, 15, 70);
            ofLine(-75, 0, 75, 0);
            ofRotateZ(90);
            ofLine(-75, 0, 75, 0);
            ofPopMatrix();
            
            ofPopStyle();
            
            
            if (visualType == VISUAL_SIENCE){
                drawAnalBG("MOTION DATA ANALYSIS");
                MotionSensorPlot.draw(200 ,200);
                MotionSensorHistoryPlot.draw(200, 780);
            }
            
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



void testApp::drawAnalBG(string name){
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
