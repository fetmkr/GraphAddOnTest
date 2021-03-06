//
//  ofxPlotLine.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#include "ofxPlotLine.h"

ofxPlotLine::ofxPlotLine(){
    
}

ofxPlotLine::~ofxPlotLine(){
    clear();
}

void ofxPlotLine::setup(string name, ofColor color){
    this->name = name;
    this->color = color;
    BUFFER_SIZE = 2048*8;
    // reserve the vector for better performance
    dataBuffer.reserve(BUFFER_SIZE);
    // initialize vector elements 
    dataBuffer.resize(BUFFER_SIZE);
    nextIndex = 0;
    bIsVisible = true;
    
    minVal = 0.0;
    maxVal = 0.0;
    minValForDrawing = 0.0;
    maxValForDrawing = 0.0;
    drawScaleFactor = 1.0;
    
    button.setup(50, 50, true, true);
    groupName = "";
}

void ofxPlotLine::clear(){

}



// add data to circular buffer

void ofxPlotLine::addData(float data){
    
    // implementing circular buffer with stl vector
    if(nextIndex >= dataBuffer.size()){
        dataBuffer.push_back(data);
    }
    else{
        dataBuffer[nextIndex] = data;
    }
    ++nextIndex;
    
    if (nextIndex >= BUFFER_SIZE) {
        nextIndex = 0;
    }
    
    lastData = data;
    
    // update Min
    if (data <= minVal) {
        minVal = data;
    }
    
    // update Max
    if (data >= maxVal){
        maxVal = data;
    }    
}


// get data using index from circular buffer

float ofxPlotLine::getElement(int index){
    if(dataBuffer.size() > 0){
        return dataBuffer[(nextIndex + index) % BUFFER_SIZE];
    }
    else{
        return 0.0;
    }
}

void ofxPlotLine::setVisible(bool bShow){
    bIsVisible = bShow;
}

bool ofxPlotLine::isVisible(){
    return bIsVisible;
}

float ofxPlotLine::getMax(){
    return maxVal;
}


float ofxPlotLine::getMin(){
    return minVal;
}

void ofxPlotLine::resetMax(){
    maxVal = 0.0;
}

void ofxPlotLine::resetMin(){
    minVal = 0.0;
}

float ofxPlotLine::getAvg(int NumOfSamples){
    // calculate only the recent average for NumOfSamples
    
    double sum = 0;
    float avg = 0;
    
    for (int i = 0; i < NumOfSamples; i++) {
        sum += getElement(i + dataBuffer.size() - NumOfSamples);
    }
    
    avg = float(sum / NumOfSamples);
    
    return avg;
}

void ofxPlotLine::setDrawScale(float scale){
    drawScaleFactor = scale;
}

float ofxPlotLine::getDrawScale(){
    return drawScaleFactor;
}

void ofxPlotLine::drawButton(float x, float y){
    button.draw(x, y);
    setVisible(button.isPressed());
}


void ofxPlotLine::setGroupName(string name){
    groupName = name;
}

string ofxPlotLine::getGroupName(){
    return groupName;
}


void ofxPlotLine::setMaxForDrawing( float val){
    maxValForDrawing = val;
}

float ofxPlotLine::getMaxForDrawing(){
    return maxValForDrawing;
}

void ofxPlotLine::setMinForDrawing( float val){
    minValForDrawing = val;
}

float ofxPlotLine::getMinForDrawing(){
    return minValForDrawing;
}
