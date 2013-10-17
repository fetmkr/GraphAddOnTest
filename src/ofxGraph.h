//
//  ofxGraph.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxGraphLine.h"

enum GridOptionType {
    RECT_DISPLAY_ONLY,
    RECT_GRID_DISPLAY
};

enum LineStyleType {
    LINE_ONLY,
    POINT_ONLY,
    LINE_WITH_POINT
};

class ofxGraph{
public:
    ofxGraph();
    ~ofxGraph();
    
    void setup(string name, float width, float height);
    void setGrid(ofColor rectColor, ofColor gridColor, GridOptionType option);
    void setLineStyle(LineStyleType style);
    
    void setXLegend(string name);
    void setYLegend(string name);
    
    void showXLegend(bool bShow);
    void showYLegend(bool bShow);
    
    void showXValue(int num);
    void showYValue(int num);
        
    void showScrollBar(bool bShow);
    
    void setZOffset(int offset);
    float getDrawPosZ(int NumOfDraw, int index);

    void setTimeScale(float sec);
    void setDataRate(float Hz);
    
    void draw(float x, float y);
    void addLine(ofPtr<ofxGraphLine> line);

    int getNumOfLines();
    
    int getNumOfVisibleLines();
    
    string graphName;
    float graphWidth;
    float graphHeight;
    float xPos;
    float yPos;
    
    int zOffset;
    

    
    ofColor rectColor;
    ofColor gridColor;
    GridOptionType gridOption;
    LineStyleType lineStyle;
    
    
    float timeScale;
    float dataRate;
    
    float dx, prevDx;
    unsigned long long t, initTime;
    float speed;
    

    vector< ofPtr<ofxGraphLine> > graphLinesPtr;
    ofPolyline drawLine;

    ofEasyCam cam3D;
    


};
