//
//  ETRILighting.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/25/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxPlotUtil.h"
#include "ofxPlot.h"
#include "ofxPlotLine.h"
#include "ofxVectorGraphics.h"
#include "ofxTimer.h"


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
