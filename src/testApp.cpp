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
    etriLogoBlk.load("etri_logo_black.svg");
    
    AccelGraph.setup("accelerometer", 900, 540);
    AccelGraph.setGrid(ofColor(100), ofColor(100), RECT_GRID_DISPLAY);
    AccelGraph.setLineStyle(LINE_ONLY);
    AccelGraph.setTimeScale(1.0);
    AccelGraph.showTimeValue(true);
    AccelGraph.showMenu(true);
    //AccelGraph.showSlider(true);
    
    AccelHistoryPlot.setup("accel history", 900, 160);
    AccelHistoryPlot.setGrid(ofColor(100), ofColor(100), RECT_DISPLAY_ONLY);
    AccelHistoryPlot.setLineStyle(LINE_ONLY);
    AccelHistoryPlot.setTimeScale(30.0);
    AccelHistoryPlot.showTimeValue(true);
    AccelHistoryPlot.showSlider(true);
    
    
//    AccelXLine->setup("X", ofColor(255,0,0));
//    AccelYLine->setup("Y", ofColor(0,255,0));
//    AccelZLine->setup("Z", ofColor(0,0,255));
    AccelXLine.setup("X", ofColor(255,0,0));
    AccelYLine.setup("Y", ofColor(0,255,0));
    AccelZLine.setup("Z", ofColor(0,0,255));
    
    AccelGraph.addLine(&AccelXLine);
    AccelGraph.addLine(&AccelYLine);
    AccelGraph.addLine(&AccelZLine);
    
    AccelHistoryPlot.addLine(&AccelXLine);
    AccelHistoryPlot.addLine(&AccelYLine);
    AccelHistoryPlot.addLine(&AccelZLine);
    bData = false;
    
//    AccelZLine.setVisible(false);
    
    }

//--------------------------------------------------------------
void testApp::update(){
    
    // fake data
    float xtemp, ytemp,ztemp;
    xtemp = 0.0;
    ytemp = 0.0;
    ztemp = 0.0;
    
    
//    if (bData) {
        xtemp = xtemp + ofSignedNoise(30*ofGetElapsedTimef()*1.0f)*20.0f;
        ytemp = ytemp + ofSignedNoise(50*ofGetElapsedTimef()*1.0f)*40.0f;
        ztemp = ztemp + ofSignedNoise(10*ofGetElapsedTimef()*1.0f)*30.0f;
        
//    }
    
    // fake data into shared data buffer
//    AccelXLine->addData(xtemp);
//    AccelYLine->addData(ytemp);
//    AccelZLine->addData(ztemp);
    AccelXLine.addData(xtemp);
    AccelYLine.addData(ytemp);
    AccelZLine.addData(ztemp);
        
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    
    
    // draw analysis window
    ofSetColor(0, 0, 0,100);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRect(160, 90, 1600, 900);
    ofSetColor(255);
    analFont.drawString("MOTION DATA ANALYSIS", 400, 170);
    ofSetColor(0);
    analFont.drawString("GRAPH", 200 +900 + 20 + 5, 170);
    analFont.drawString("ON TIME", 200 +900 + 20 + 128 + 20 + 5, 170);
    ofSetColor(255);
    analFont.drawString(AccelGraph.getTimeStamp(ofGetElapsedTimeMillis()), 200 +900 + 20 + 128 + 20 + 280, 170);
    
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

    
    AccelGraph.draw(200 ,200);
    AccelHistoryPlot.draw(200, 780);
    
    
    
    
    
    
//    ofDrawBitmapString(ofToString(AccelXLine.getMin()), 50,100);
//    ofDrawBitmapString(ofToString(AccelXLine.getMax()), 50,150);
//    ofDrawBitmapString(ofToString(AccelXLine.getAvg(1000)), 50,200);


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch(key){
        case ' ':
            AccelGraph.show3D(true);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch(key){
        case ' ':
            AccelGraph.show3D(false);
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
