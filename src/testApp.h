#pragma once

#include "ofMain.h"
#include "ETRILighting.h"
#include "ofxDAQButton.h"
#include "MotionSensor2D.h"
#include "MotionSensor3D.h"
#include "PressAltSensor.h"
#include "TouchSensor.h"
#include "ColorSensor.h"
#include "LuxSensor.h"
#include "TempHumidSensor.h"
#include "NavigationMenu.h"
#include "ofxNetwork.h"

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
    
    
        void setupPlots();
    
        void changeScene(LightSensorType &scene);
        void changeMode(LightVisualType &mode);


        LightSensorType sensorType;
        LightDemoType demoType;
        LightVisualType visualType;
    
        ofxPlotLine touchProxiLine;
        ofxPlotLine touchPressLine;
        ofxPlotLine touchWheelLine;
        ofxPlotLine touchGestureLine;
        ofxPlotLine touchSleepLine;
    
        ofxPlotLine AccelXLine;
        ofxPlotLine AccelYLine;
        ofxPlotLine AccelZLine;
        ofxPlotLine GyroXLine;
        ofxPlotLine GyroYLine;
        ofxPlotLine GyroZLine;
        ofxPlotLine compassLine;
    
        ofxPlotLine pressureLine;
        ofxPlotLine altLine;
        
        ofxPlotLine ambTempLine;
        ofxPlotLine objTempLine;
        ofxPlotLine humidityLine;
        
        ofxPlotLine colorLine;
        ofxPlotLine luxLine;
    
        MotionSensor2D motionSensor2D;
        MotionSensor3D motionSensor3D;
        PressAltSensor pressAltSensor;
        TouchSensor touchSensor;
        ColorSensor colorSensor;
        LuxSensor luxSensor;
        TempHumidSensor tempHumidSensor;
    
        NavigationMenu naviMenu;
        ofxTCPServer TCP;
        vector <string> storeText;
    
        float luxData;
private:
    ~testApp();
};
