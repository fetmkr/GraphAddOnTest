//
//  ofxGraphLine.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#include "ofxGraphLine.h"

ofxGraphLine::ofxGraphLine(){
    
}

ofxGraphLine::~ofxGraphLine(){
    clear();
}

void ofxGraphLine::setup(string name, ofColor color){
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

void ofxGraphLine::clear(){

}



// add data to circular buffer

void ofxGraphLine::addData(float data){
    
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

float ofxGraphLine::getElement(int index){
    if(dataBuffer.size() > 0){
        return dataBuffer[(nextIndex + index) % BUFFER_SIZE];
    }
    else{
        return 0.0;
    }
}

void ofxGraphLine::setVisible(bool bShow){
    bIsVisible = bShow;
}

bool ofxGraphLine::isVisible(){
    return bIsVisible;
}





