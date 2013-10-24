#pragma once

#include "ofMain.h"
#include "ofxPlot.h"
#include "ofxPlotLine.h"
#include "ofxPlotUtil.h"
#include "ofxSvg.h"

using namespace ofxPlotUtil;

enum LightSensorType{
    SENSOR_TOUCH = 0,
    SENSOR_MOTION_2D,
    SENSOR_MOTION_3D,
    SENSOR_PRESSURE_ALTITUDE,
    SENSOR_TEMP_HUMIDITY,
    SENSOR_COLOR,
    SENSOR_LUX
};

enum LightDemoType{
    DEMO_STREET = 0,
    DEMO_INDOOR = 1
};

enum LightVisualType {
    VISUAL_GRAPHIC = 0,
    VISUAL_SIENCE = 1
};

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void drawAnalBG(string name);
    
    
    
        LightSensorType sensorType;
        LightDemoType demoType;
        LightVisualType visualType;
    
    
        ofImage compassImg;
        ofImage compassBGImg;
    
    
        ofxPlot MotionSensorPlot;
        ofxPlot MotionSensorHistoryPlot;
    
        ofxPlotLine AccelXLine;
        ofxPlotLine AccelYLine;
        ofxPlotLine AccelZLine;
    
        ofxPlotLine GyroXLine;
        ofxPlotLine GyroYLine;
        ofxPlotLine GyroZLine;
    
    
    
    
    
    
    
        ofTrueTypeFont analFont;
        ofTrueTypeFont numberFont;
        ofTrueTypeFont textFont;
    
        ofxSVG etriLogoBlk;
    
        bool bData;

    
};
