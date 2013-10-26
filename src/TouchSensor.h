//
//  TouchSensor.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/26/13.
//
//

#include "ETRILighting.h"
#include "Sensor.h"

class TouchSensor : public Sensor {
    
public:
    TouchSensor();
    ~TouchSensor();

    void setup();
    void draw(LightSensorType sensorType, LightVisualType visualType);

    void drawSlice(int num, bool bShow);

    ofImage touchRingImg;
    ofImage cwArrowImg;
    ofImage ccwArrowImg;

    int NumOfSlice;
    ofxVectorGraphics ringSlice;
};