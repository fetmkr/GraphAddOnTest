//
//  ofxPlot.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#include "ofxPlot.h"

ofxPlot::ofxPlot(){
    
}

ofxPlot::~ofxPlot(){
    
}

void ofxPlot::setup(string name, float width, float height){
    graphName = name;
    graphWidth = width;
    graphHeight = height;
    // default time scale = 1 sec
    timeScale = 1.0;
    
    // default data rate = 60 Hz
    dataRate = 60;
    
    // default zOffset value = 50
    zOffset = 50;
    
    
    cam3D.enableOrtho();
    
    timeFont.loadFont("NewMedia Fett.ttf",8, true, true, true);

    
    
    slider.setup(graphWidth);
}

void ofxPlot::setGrid(ofColor rectColor, ofColor gridColor, GridOptionType option){
    this->rectColor = rectColor;
    this->gridColor = gridColor;
    gridOption = option;
}

void ofxPlot::setLineStyle(LineStyleType style){
    lineStyle = style;
}

void ofxPlot::setZOffset(int offset){
    zOffset = offset;
}

float ofxPlot::getDrawPosZ(int NumOfDraw, int index){
    float drawPos;
    
    if (NumOfDraw % 2) {
        // odd number
        drawPos = zOffset * div(NumOfDraw, 2).quot - zOffset * index;
        
    }
    else{
        // even number
        drawPos = zOffset * div(NumOfDraw, 2).quot - zOffset * index - zOffset/2;
    }
    
    return drawPos;
}

void ofxPlot::setTimeScale(float sec)
{
    timeScale = sec;
}

void ofxPlot::setDataRate(float Hz){
    dataRate = Hz;
}

void ofxPlot::draw(float x, float y){
        
    xPos = x;
    yPos = y;
    float timeStep;
    int NumOfDisplayData;
    
    NumOfDisplayData = int(timeScale * dataRate);
    timeStep = graphWidth / NumOfDisplayData;
    
    int drawIndex = 0;
        
    
    
    
    
    ofPushStyle();
    


    // draw rect
    ofNoFill();
    ofSetColor(this->rectColor);
    ofRect(xPos, yPos, graphWidth, graphHeight);

    ofRectangle camView;
    camView = ofRectangle(xPos, yPos, graphWidth, graphHeight);
    //ofEnableDepthTest();

    
    cam3D.begin(camView);

	// Setup Ortho projection
	ofSetMatrixMode(OF_MATRIX_PROJECTION);
    ofMatrix4x4 ortho;
    ortho.makeOrthoMatrix(-graphWidth/2, graphWidth/2, -graphHeight/2, graphHeight/2, - getNumOfVisibleLines() * zOffset -1000, getNumOfVisibleLines() * zOffset +1000);
    ofLoadMatrix(ortho);
    ofSetMatrixMode(OF_MATRIX_MODELVIEW);

    // 3D Mode
    if(b3DMode){
        ofRotateX(ofRadToDeg(.5));
        ofRotateY(ofRadToDeg(.5));
        // scale up a little in 3D mode 
        ofScale(1.3, 1.3);
    }
    
    // font testing
    // ttf font needs to be flipped
    // bitmap font needs to be of bitmap mode model
//    ofPushMatrix();
//    ofScale(1, -1);
//    ofSetColor(255, 0, 0);
//    timeFont.drawStringAsShapes("안녕하세요", 0, 0);
//    //ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
//    //ofDrawBitmapString("Hello World", 50, -10, 50);
//    ofPopMatrix();
    
    

    if(gridOption == RECT_GRID_DISPLAY){
        ofPushMatrix();

        // draw Grid
        ofSetColor(this->gridColor);
        ofLine(-graphWidth/2, 0, graphWidth/2, 0);
        //ofLine(0, -graphHeight/2, 0, graphHeight/2);
        ofSetColor(this->gridColor * 0.5);
        ofLine(-graphWidth/2, graphHeight/4, graphWidth/2, graphHeight/4);
        ofLine(-graphWidth/2, -graphHeight/4, graphWidth/2, -graphHeight/4);

        ofPopMatrix();
    }

    ofPushMatrix();
    // Move to the left
    ofTranslate(-graphWidth/2 , 0);

    
    for(int i = 0 ; i < graphLinesPtr.size() ; i++)
    {
        if (graphLinesPtr[i]->isVisible()) {
            
            ofSetColor(graphLinesPtr[i]->color);
            if(lineStyle != POINT_ONLY){
                
                // draw line
                // we need to add 1 more point to finish the line nicely
                for (int j = 0; j< NumOfDisplayData + 1; j++) {
                    
                    // how can we draw the most recent data - > the last element is the recent one
                    // so draw from the last to the last - numofdisplaydata element 
                    drawLine.addVertex(ofPoint(timeStep * NumOfDisplayData - timeStep * j
                                               , i + graphLinesPtr[i]->getElement(j + graphLinesPtr[i]->dataBuffer.size() - 1 - NumOfDisplayData)
                                               , getDrawPosZ(getNumOfVisibleLines(), drawIndex)));
                    
                }
          
                drawLine.draw();
                drawLine.clear();
            }
            
            if(lineStyle != LINE_ONLY){
                
                // draw points
                glPointSize(1.5);
                glBegin(GL_POINTS);
                for (int j = 0; j<= NumOfDisplayData; j++) {
                    
                    glVertex3f(timeStep * NumOfDisplayData - timeStep * j
                               , i + graphLinesPtr[i]->getElement(j + graphLinesPtr[i]->dataBuffer.size() - 1 - NumOfDisplayData)
                               , getDrawPosZ(getNumOfVisibleLines(), drawIndex));
                    
                }
                
                glEnd();
            }
            
            drawIndex++;
   
        }
    }
    
    drawIndex = 0;
    
    ofPopMatrix();
    
    cam3D.end();
    //ofDisableDepthTest();
    
    
    if(bShowTimeVal){
        // show time code
        //ofDrawBitmapString(getElapsedTime(0), 20,20);
        drawTimeValue(0);
        
    }
    
    if (bShowSlider) {
        // slider should only be responsive when it's drawn
        slider.draw(xPos, yPos+graphHeight);
    }
    ofPopStyle();
    
    
    

    
    
}

// to add instance to vector, what is proper way?


//void ofxPlot::addLine(ofPtr<ofxPlotLine> line){
//    graphLinesPtr.push_back(line);
//}

void ofxPlot::addLine(ofxPlotLine* line){
    graphLinesPtr.push_back(line);
}


int ofxPlot::getNumOfLines(){
    return graphLinesPtr.size();
}


int ofxPlot::getNumOfVisibleLines(){
    int cnt = 0;
    for (int i = 0; i < graphLinesPtr.size(); i++) {
        if (graphLinesPtr[i]->isVisible())
            cnt++;
    }
    
    return cnt;
}


void ofxPlot::show3D(bool b3D){
    b3DMode = b3D;
}

bool ofxPlot::is3D(void){
    return b3DMode;
}

void ofxPlot::showTimeValue(bool bShow){
    bShowTimeVal = bShow;
}

string ofxPlot::getTimeStamp(){
    string timeStamp;
    string minStamp;
    string secStamp;
    string milliStamp;
    int min;
    int sec;
    int milli;
    
    min = int(ofGetElapsedTimeMillis() / 60000);
    sec = int(ofGetElapsedTimeMillis() / 1000) %60;
    milli = int(ofGetElapsedTimeMillis()/10 ) % 100;
    
    if (min < 10){
        minStamp ="0"+ofToString(min);
    }
    else{
        minStamp=ofToString(min);
    }
    
    if (sec < 10){
        secStamp = "0"+ofToString(sec);
    }
    else{
        secStamp = ofToString(sec);
    }
    
    if(milli < 10){
        milliStamp = "0"+ofToString(milli);
    }
    else{
        milliStamp=ofToString(milli);
    }
    
    timeStamp = minStamp + ":" + secStamp + ":" + milliStamp;
    
    return timeStamp;
}

void ofxPlot::drawTimeValue(float offsetTime){
    
    string time[4];
    
    for(int i = 0; i < 4; i++) {
        time[i] = ofToString(int(offsetTime + (timeScale * 1000 / 3) * i)) + " ms";
        ofRectangle boundingBox = timeFont.getStringBoundingBox(time[i], 0, 0);
        float x;
        float y;
        x = xPos + graphWidth*i/3 - boundingBox.getCenter().x;
        y= yPos + graphHeight + boundingBox.height*2;
        ofSetColor(255);
        timeFont.drawString(ofToString(time[i]), x, y);
        ofFill();
        ofSetColor(255, 0, 0);
        ofCircle(xPos + graphWidth*i/3, yPos + graphHeight, 2);
    }
}

void ofxPlot::showSlider(bool bShow){
    bShowSlider = bShow;
}

