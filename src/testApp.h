#pragma once

#include "ofMain.h"
#include "ETRILighting.h"
#include "MotionSensor2D.h"
#include "MotionSensor3D.h"

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

        LightSensorType sensorType;
        LightDemoType demoType;
        LightVisualType visualType;
    
        MotionSensor2D motionSensor2D;
        MotionSensor3D motionSensor3D;
};
