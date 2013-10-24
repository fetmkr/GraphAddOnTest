//
//  ofxPlotUtil.cpp
//  GraphAddOnTest
//
//  Created by songhojun on 10/24/13.
//
//

#include "ofxPlotUtil.h"

namespace ofxPlotUtil {
    string getTimeStamp(unsigned long long ms){
        string timeStamp;
        string minStamp;
        string secStamp;
        string milliStamp;
        int min;
        int sec;
        int milli;
        
        min = int(ms / 60000);
        sec = int(ms / 1000) % 60;
        milli = int(ms / 10 ) % 100;
        
        if (min < 10){
            minStamp ="0"+ofToString(min);
        }
        else{
            minStamp=ofToString(min);
        }
        
        if (sec < 10){
            secStamp = "0"+ofToString(sec);
        }
        else{
            secStamp = ofToString(sec);
        }
        
        if(milli < 10){
            milliStamp = "0"+ofToString(milli);
        }
        else{
            milliStamp=ofToString(milli);
        }
        
        timeStamp = minStamp + ":" + secStamp + "." + milliStamp;
        
        return timeStamp;
    }
}