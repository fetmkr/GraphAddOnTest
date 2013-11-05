//
//  ofxPlot.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/13/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxPlotUtil.h"
#include "ofxPlotLine.h"
#include "ofxPlotSlider.h"
#include "ofxPlotButton.h"
//#include "ofxTrueTypeFontUC.h"

using namespace ofxPlotUtil;


enum GridOptionType {
    RECT_DISPLAY_ONLY,
    RECT_GRID_DISPLAY
};

enum LineStyleType {
    LINE_ONLY,
    POINT_ONLY,
    LINE_WITH_POINT
};

class ofxPlot{
public:
    ofxPlot();
    ~ofxPlot();
    
    void setup(string name, float width, float height);
    void setGrid(ofColor rectColor, ofColor gridColor, GridOptionType option);
    void setLineStyle(LineStyleType style);
    
    void showTimeValue(bool bShow);
    //string getTimeStamp(unsigned long long ms);
        
    void showSlider(bool bShow);
    void showMenu(bool bShow);
    void show3DButton(bool bShow);
    bool bShowMenu;
    bool bShow3DButton;
    
    void setMenuButton(float size, float xOffset);
    float buttonSize;
    float buttonXOffsetPos;
    
    void show3D(bool b3D);
    bool is3D(void);
    
    void setZOffset(int offset);
    float getDrawPosZ(int NumOfDraw, int index);

    void setTimeScale(float sec);
    void setDataRate(float Hz);
    
    void draw(float x, float y);
//    void addLine(ofPtr<ofxPlotLine> line);
    
    
    void addLine(ofxPlotLine* line);

    void addGroup(string groupName);
    vector<string> groups;
    
    void addLineToGroup(ofxPlotLine* line, string groupName);
    vector<ofxPlotLine*> getLinesFromGroup(string groupName);
    int getNumOfLinesInGroup(string groupName);
    
    
    
    int getNumOfLines();
    
    int getNumOfVisibleLines();
    
    string graphName;
    float graphWidth;
    float graphHeight;
    float xPos;
    float yPos;
    
    int zOffset;
    int timeOffset;
    

    bool bShowTimeVal;
    bool bShowSlider;
    
    bool b3DMode;
    
    ofColor rectColor;
    ofColor gridColor;
    GridOptionType gridOption;
    LineStyleType lineStyle;
    
    
    float timeScale;
    float dataRate;
    
    float dx, prevDx;
    unsigned long long t, initTime;
    float speed;
    

//    vector< ofPtr<ofxPlotLine> > graphLinesPtr;
        ofTrueTypeFont timeFont;
    ofTrueTypeFont menuFont;
    ofxPlotButton button3DOn;

private:
    vector<ofxPlotLine*> graphLinesPtr;
    ofPolyline drawLine;
    ofxPlotSlider slider;
    ofCamera cam3D;
    void drawMilliTimeValue(float offsetTime);
    void drawTimeStamp(float offsetTime);
    

    
    
};
