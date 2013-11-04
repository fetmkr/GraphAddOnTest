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
    enum PrecisionType {
        PRECISION_1DIGIT = 10,
        PRECISION_2DIGIT = 100,
        PRECISION_3DIGIT = 1000,
        
    };
    
    string getTimeStamp(unsigned long long ms);
    string niceFloatToString(float val, PrecisionType precisionType);
    string niceIntToString(int val);
}