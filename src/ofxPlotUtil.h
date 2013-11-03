//
//  ofxPlotUtil.h
//  GraphAddOnTest
//
//  Created by songhojun on 10/24/13.
//
//

#pragma once

#include "ofMain.h"

namespace ofxPlotUtil{
    string getTimeStamp(unsigned long long ms);
    string niceFloatToString(float val);
    string niceIntToString(int val);
}