//
//  Sensor.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/25/13.
//
//

#include "Sensor.h"

Sensor::Sensor(){
    
}

Sensor::~Sensor(){
    
}

void Sensor::setup(){
    analFont.loadFont("SimKBRg.ttf", 36);
    groupFont.loadFont("SimKBRg.ttf", 24);
    dataFont.loadFont("SimKBRg.ttf", 18);

    etriLogoBlk.loadImage("etri_logo_black.png");
    numberFont.loadFont("HelveticaNeueUltraLight.ttf", 25);
    textFont.loadFont("HelveticaNeueUltraLight.ttf", 23.5);
    
    shortPlot.setup("short plot", 900, 540);
    shortPlot.setGrid(ofColor(100), ofColor(100), RECT_GRID_DISPLAY);
    shortPlot.setLineStyle(LINE_ONLY);
    shortPlot.setTimeScale(1.0);
    shortPlot.showTimeValue(true);
    shortPlot.showSlider(false);
    shortPlot.show3DButton(true);
    shortPlot.showMenu(true);
    
    longPlot.setup("long plot", 900, 160);
    longPlot.setGrid(ofColor(100), ofColor(100), RECT_DISPLAY_ONLY);
    longPlot.setLineStyle(LINE_ONLY);
    longPlot.setTimeScale(30.0);
    longPlot.showTimeValue(true);
    longPlot.showSlider(true);
    longPlot.show3DButton(true);
    //longPlot.showMenu(true);
    
    
}
void Sensor::setBGImg(string path){
    BGImg.loadImage(path);
    BGImg.setImageType(OF_IMAGE_COLOR_ALPHA);
}

void Sensor::drawBGImg(float x, float y){
    BGImg.draw(x, y);
}

void Sensor::drawPlots(){
    shortPlot.draw(200 ,200);
    longPlot.draw(200, 780);
}

void Sensor::addLine(ofxPlotLine* line){
    shortPlot.addLine(line);
    longPlot.addLine(line);
}

void Sensor::addGroup(string groupName){
    shortPlot.addGroup(groupName);
    longPlot.addGroup(groupName);
}


void Sensor::addLineToGroup(ofxPlotLine* line, string groupName){
    shortPlot.addLineToGroup(line, groupName);
    longPlot.addLineToGroup(line, groupName);
}



void Sensor::drawAnalBG(string name){
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
    etriLogoBlk.draw(0,0);
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
    
//    ofSetColor(100);
//    ofLine(200 +900 + 20 + 128 + 20, 200, 200 +900 + 20 + 128 + 20 +460, 200);
//    ofRect(200 +900 + 20 + 128 + 20, 200, 4, 4);
//    ofRect(200 +900 + 20 + 128 + 20 +460, 200, 4, 4);

    ofSetRectMode(OF_RECTMODE_CORNER);
    
    drawGroupData(200 +900 + 20 + 128 + 20, 200);


}



void Sensor::drawGroupData(float x, float y, string groupName){
    vector<ofxPlotLine*> lines;
    lines = shortPlot.getLinesFromGroup(groupName);
    float min;
    float max;
    float avg;
    float lastVal;
    
    
    ofSetColor(100);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofLine(x, y, x + 460, y);
    ofRect(x, y, 4, 4);
    ofRect(x +460, y, 4, 4);
    ofSetRectMode(OF_RECTMODE_CORNER);

    
    for (int i = 0; i < lines.size(); i++) {
        min = lines[i]->getMin();
        max = lines[i]->getMax();
        avg = lines[i]->getAvg(128);
        lastVal = lines[i]->lastData;
        ofSetColor(255);
        groupFont.drawString(groupName, x, y + 40);
        
        
        ofSetColor(0);
        dataFont.drawString("MIN", x, y + 40 + 40 + 50 * i);
        dataFont.drawString(niceFloatToString(min, PRECISION_3DIGIT), x, y + 40 + 60 + 50 * i);
        dataFont.drawString("MAX", x + 70, y + 40 + 40 + 50 * i);
        dataFont.drawString(niceFloatToString(max, PRECISION_3DIGIT), x + 70, y + 40 + 60 + 50 * i);
        dataFont.drawString("AVG", x + 140, y + 40 + 40 + 50 * i);
        dataFont.drawString(niceFloatToString(avg, PRECISION_3DIGIT), x + 140, y + 40 + 60 + 50 * i);
        
        ofSetColor(255);
        analFont.drawString(lines[i]->name, x+275, y + 40 + 60 + 50 * i);
        analFont.drawString(niceFloatToString(lastVal, PRECISION_3DIGIT), x+275 + 50, y + 40 + 60 + 50 * i);

    }
    
}

void Sensor::drawGroupData(float x, float y){

    if(shortPlot.groups.size()>0){
        for (int i = 0; i< shortPlot.groups.size(); i++) {
            float gap = 0.0;
            if(i > 0){
                gap = (50 + shortPlot.getNumOfLinesInGroup(shortPlot.groups[i-1]) * 35.0 + 35) * i ;
            }
            drawGroupData(x, y + gap, shortPlot.groups[i]);
        }
    }
}
