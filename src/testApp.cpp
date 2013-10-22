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
    
    AccelGraph.setup("accelerometer", 960, 540);
    AccelGraph.setGrid(ofColor(100), ofColor(100), RECT_GRID_DISPLAY);
    AccelGraph.setLineStyle(LINE_ONLY);
    AccelGraph.setTimeScale(4.0);
    
//    AccelXLine->setup("X", ofColor(255,0,0));
//    AccelYLine->setup("Y", ofColor(0,255,0));
//    AccelZLine->setup("Z", ofColor(0,0,255));
    AccelXLine.setup("X", ofColor(255,0,0));
    AccelYLine.setup("Y", ofColor(0,255,0));
    AccelZLine.setup("Z", ofColor(0,0,255));
    
    AccelGraph.addLine(&AccelXLine);
    AccelGraph.addLine(&AccelYLine);
    AccelGraph.addLine(&AccelZLine);

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
    ofBackground(0);
    AccelGraph.draw(20,100);
    ofDrawBitmapString(ofToString(AccelXLine.getMin()), 50,100);
    ofDrawBitmapString(ofToString(AccelXLine.getMax()), 50,150);
    ofDrawBitmapString(ofToString(AccelXLine.getAvg(1000)), 50,200);


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
