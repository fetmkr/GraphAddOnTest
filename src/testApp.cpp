#include "testApp.h"

// better way to use ofPtr ???
// maybe we don't need ofPtr for the lines
// we can just use normal pointer like advanced3d example used pointer for cameras?

//ofPtr<ofxPlotLine> AccelXLine(new ofxPlotLine);
//ofPtr<ofxPlotLine> AccelYLine(new ofxPlotLine);
//ofPtr<ofxPlotLine> AccelZLine(new ofxPlotLine);

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
#ifdef _WIN32
    // Turn on vertical screen sync under Windows.
    // (I.e. it uses the WGL_EXT_swap_control extension)
    typedef BOOL (WINAPI *PFNWGLSWAPINTERVALEXTPROC)(int interval);
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    if(wglSwapIntervalEXT)
        wglSwapIntervalEXT(1);
#endif
    
    
    // TCP Server Setup
    // setup the server to listen on 11999
	TCP.setup(11999);
    
    // Optionally set the delimiter to something else.
    // The delimter in the client and the server have to be the same, default being [/TCP]
	TCP.setMessageDelimiter("\n");
    
   
    setupPlots();
    

    
    naviMenu.setup(80, 900, ofColor(0,0,0,200));
    ofAddListener(naviMenu.sensorTypeChanged, this, &testApp::changeScene);
    ofAddListener(naviMenu.visualTypeChanged, this, &testApp::changeMode);
    
    sensorType = SENSOR_TOUCH;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //for each client lets send them a message letting them know what port they are connected on
	for(int i = 0; i < TCP.getLastID(); i++){
		if( !TCP.isClientConnected(i) )continue;
        
		TCP.send(i, "hello client - you are connected on port - "+ofToString(TCP.getClientPort(i)) );
	}
    
    

    // fake data
    float xtemp, ytemp,ztemp;
    xtemp = 0.0;
    ytemp = 0.0;
    ztemp = 0.0;
    //luxData = 0.0;
    
    xtemp = xtemp + ofSignedNoise(30*ofGetElapsedTimef()*1.0f)*20.0f;
    ytemp = ytemp + ofSignedNoise(50*ofGetElapsedTimef()*1.0f)*40.0f;
    ztemp = ztemp + ofSignedNoise(10*ofGetElapsedTimef()*1.0f)*30.0f;

    AccelXLine.addData(xtemp);
    AccelYLine.addData(ytemp);
    AccelZLine.addData(ztemp);
    GyroXLine.addData(xtemp);
    GyroYLine.addData(ytemp);
    GyroZLine.addData(ztemp);
    
    luxLine.addData(luxData);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);

//    switch (naviMenu.getSensorType()) {
    switch (sensorType) {
        case SENSOR_TOUCH:
            touchSensor.draw(sensorType, visualType);
            break;
        case SENSOR_MOTION_2D:
            motionSensor2D.draw(sensorType,visualType);
            naviMenu.drawLRButton(960, 908);
            break;
        case SENSOR_MOTION_3D:
            motionSensor3D.draw(sensorType, visualType);
            naviMenu.drawLRButton(960, 908);
            break;
        case SENSOR_PRESSURE_ALTITUDE:
            pressAltSensor.draw(sensorType, visualType);
            break;
        case SENSOR_TEMP_HUMIDITY:
            tempHumidSensor.draw(sensorType, visualType);
            break;
        case SENSOR_COLOR:
            colorSensor.draw(sensorType, visualType);
            naviMenu.drawLRButton(960, 908);
            break;
        case SENSOR_LUX:
            luxSensor.draw(sensorType, visualType);
            naviMenu.drawLRButton(960, 908);

            break;
        default:
            break;
    }
    
    naviMenu.draw(0, 90);
    
    
    ofPushStyle();
    for(unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++){
        
		if( !TCP.isClientConnected(i) )continue;
        
		//give each client its own color
		//ofSetColor(255 - i*30, 255 - i * 20, 100 + i*40);
        ofSetColor(0);
        
		//calculate where to draw the text
		int xPos = 15;
		int yPos = 80 + (12 * i * 4);
        
		//get the ip and port of the client
		string port = ofToString( TCP.getClientPort(i) );
		string ip   = TCP.getClientIP(i);
		string info = "client "+ofToString(i)+" -connected from "+ip+" on port: "+port;
        
        
		//if we don't have a string allocated yet
		//lets create one
		if(i >= storeText.size() ){
			storeText.push_back( string() );
		}
        
		//we only want to update the text we have recieved there is data
		string str = TCP.receive(i);
        
		if(str.length() > 0){
			storeText[i] = str;
		}
        
        string nodelimStr;
        
        // take out the delimiter
        nodelimStr = storeText[i].substr(0,storeText[i].length()-1);
        
        vector<string> splitItems = ofSplitString(nodelimStr, "@");
        
        if(splitItems.size()>4){
            string idStr;
            string dataStr;
            
            for (int i = 0 ; i < splitItems.size()-1; i++) {
                
                idStr = splitItems[i].substr(0,4);
                
                dataStr = splitItems[i].substr(5);
                
                if (idStr == "$LUX") {
                    luxData = ofToFloat(dataStr);

                }
                
            }
        }
		//draw the info text and the received text bellow it
		ofDrawBitmapString(info, xPos, yPos);
		ofDrawBitmapString(storeText[i], 25, yPos + 20);
        
	}
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch(key){
        case 'f':
            ofToggleFullscreen();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch(key){
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::setupPlots(){
    
    touchProxiLine.setup("pressure", ofColor(255,0,255));
    touchPressLine.setup("pressure", ofColor(255,0,255));
    touchWheelLine.setup("pressure", ofColor(255,0,255));
    touchGestureLine.setup("pressure", ofColor(255,0,255));
    touchSleepLine.setup("pressure", ofColor(255,0,255));
    
    AccelXLine.setup("ACCEL X", ofColor(255,0,0));
    AccelYLine.setup("ACCLE Y", ofColor(0,255,0));
    AccelZLine.setup("ACCEL Z", ofColor(0,0,255));
    compassLine.setup("COMPASS", ofColor(255,255,0));
    
    GyroXLine.setup("GYRO X", ofColor(255,255,0));
    GyroYLine.setup("GYRO Y", ofColor(0,255,255));
    GyroZLine.setup("GYRO Z", ofColor(255,0,255));
    
    pressureLine.setup("PRESSURE", ofColor(255,0,255));
    altLine.setup("TEMP", ofColor(255,0,255));
    
    ambTempLine.setup("AMB TEMP", ofColor(255,0,255));
    objTempLine.setup("OBJ TMEP", ofColor(255,0,255));
    humidityLine.setup("HUMIDITY", ofColor(255,0,255));
    
    colorLine.setup("COLOR", ofColor(255,0,255));
    luxLine.setup("LUX", ofColor(255,0,255));
    
    // setup before add the lines
    // otherwise the button will not be shown
    touchSensor.setup();
    motionSensor2D.setup();
    motionSensor3D.setup();
    pressAltSensor.setup();
    tempHumidSensor.setup();
    colorSensor.setup();
    luxSensor.setup();

    
    touchSensor.addLine(&touchProxiLine);
    touchSensor.addLine(&touchPressLine);
    touchSensor.addLine(&touchWheelLine);
    touchSensor.addLine(&touchGestureLine);
    touchSensor.addLine(&touchSleepLine);

    
    motionSensor2D.addLine(&AccelXLine);
    motionSensor2D.addLine(&AccelYLine);
    motionSensor2D.addLine(&AccelZLine);
    motionSensor2D.addLine(&compassLine);
    
    
    motionSensor2D.addGroup("COMPASS");
    motionSensor2D.addLineToGroup("COMPASS", &compassLine);
    
    motionSensor2D.addGroup("ACCELEROMETER");
    motionSensor2D.addLineToGroup("ACCELEROMETER", &AccelXLine);
    motionSensor2D.addLineToGroup("ACCELEROMETER", &AccelYLine);
    motionSensor2D.addLineToGroup("ACCELEROMETER", &AccelZLine);
    

    
    motionSensor3D.addLine(&GyroXLine);
    motionSensor3D.addLine(&GyroYLine);
    motionSensor3D.addLine(&GyroZLine);
    
    pressAltSensor.addLine(&pressureLine);
    pressAltSensor.addLine(&altLine);
    
    tempHumidSensor.addLine(&ambTempLine);
    tempHumidSensor.addLine(&objTempLine);
    tempHumidSensor.addLine(&humidityLine);
    
    colorSensor.addLine(&colorLine);
    luxSensor.addLine(&luxLine);

    
    luxData = 0.0;

}

void testApp::changeScene(LightSensorType &scene){
    sensorType = scene;
    
    
    switch (sensorType) {
        case SENSOR_TOUCH:
            break;
        case SENSOR_MOTION_2D:
//            if (naviMenu.bToggle == false){
//                sensorType = SENSOR_MOTION_3D;
//            }
            break;
        case SENSOR_MOTION_3D:
//            if (naviMenu.bToggle == true){
//                sensorType = SENSOR_MOTION_2D;
//            }
            break;
        case SENSOR_PRESSURE_ALTITUDE:
            break;
        case SENSOR_TEMP_HUMIDITY:
            break;
        case SENSOR_COLOR:
            colorSensor.reset();
//            if (naviMenu.bToggle == false){
//                sensorType = SENSOR_LUX;
//            }
            break;
        case SENSOR_LUX:
//            if (naviMenu.bToggle == true){
//                sensorType = SENSOR_COLOR;
//            }
            break;
        default:
            break;
    }

    
}

void testApp::changeMode(LightVisualType &mode){
    visualType = mode;
}

testApp::~testApp(){
    cout << "tcp closed" << endl;
    TCP.close();
}