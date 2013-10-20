//
//  ofxGraph.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#include "ofxGraph.h"

ofxGraph::ofxGraph(){
    
}

ofxGraph::~ofxGraph(){
    
}

void ofxGraph::setup(string name, float width, float height){
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
    cam3D.setDistance(200);
    //cam3D.tilt(-10);
}

void ofxGraph::setGrid(ofColor rectColor, ofColor gridColor, GridOptionType option){
    this->rectColor = rectColor;
    this->gridColor = gridColor;
    gridOption = option;
}

void ofxGraph::setLineStyle(LineStyleType style){
    lineStyle = style;
}

void ofxGraph::setZOffset(int offset){
    zOffset = offset;
}

float ofxGraph::getDrawPosZ(int NumOfDraw, int index){
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

void ofxGraph::setTimeScale(float sec)
{
    timeScale = sec;
}

void ofxGraph::setDataRate(float Hz){
    dataRate = Hz;
}

void ofxGraph::draw(float x, float y){
    
//    ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(),0),ofGetWidth()-80,20);
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
    ofEnableDepthTest();

    cam3D.begin(camView);    
    
    if(gridOption == RECT_GRID_DISPLAY){
        ofPushMatrix();
        // draw Grid
        ofSetColor(this->gridColor);
//        ofFill();
//        ofBeginShape();
//        ofVertex(0, 270, -50);
//        ofVertex(graphWidth, 270, -50);
//        ofVertex(graphWidth, 270, 50);
//        ofVertex(0,270, 50);
//        ofEndShape();
        ofLine(0, graphHeight/2, graphWidth, graphHeight/2);
        ofLine(graphWidth/2, graphHeight, graphWidth/2, 0);
        ofPopMatrix();
    }

           
    ofPushMatrix();
    ofTranslate(0, graphHeight/2);

    
    
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
                //        ofPushStyle();
                glPointSize(1.5);
                glBegin(GL_POINTS);
                for (int j = 0; j<= NumOfDisplayData; j++) {
                    
                    glVertex3f(timeStep * NumOfDisplayData - timeStep * j
                               , i + graphLinesPtr[i]->getElement(j + graphLinesPtr[i]->dataBuffer.size() - 1 - NumOfDisplayData)
                               , getDrawPosZ(getNumOfVisibleLines(), drawIndex));
                    
                }
                
                glEnd();
                //        ofPopStyle();
            }
            
            drawIndex++;
   
        }
    }
    
    drawIndex = 0;
    
    ofPopMatrix();
    cam3D.end();
    ofDisableDepthTest();
    
    ofPopStyle();
    
    
}

// to add instance to vector, what is proper way?


//void ofxGraph::addLine(ofPtr<ofxGraphLine> line){
//    graphLinesPtr.push_back(line);
//}

void ofxGraph::addLine(ofxGraphLine* line){
    graphLinesPtr.push_back(line);
}


int ofxGraph::getNumOfLines(){
    return graphLinesPtr.size();
}


int ofxGraph::getNumOfVisibleLines(){
    int cnt = 0;
    for (int i = 0; i < graphLinesPtr.size(); i++) {
        if (graphLinesPtr[i]->isVisible())
            cnt++;
    }
    
    return cnt;
}