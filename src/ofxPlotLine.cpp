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
}

void ofxPlotLine::clear(){

}



// add data to circular buffer

void ofxPlotLine::addData(float data){
    
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





