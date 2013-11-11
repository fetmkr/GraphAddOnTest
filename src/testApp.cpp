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
    ofAddListener(naviMenu.sensorTypeChanged, this, &testApp::changeSensorType);
    ofAddListener(naviMenu.visualTypeChanged, this, &testApp::changeVisualType);
    ofAddListener(naviMenu.demoTypeChanged, this, &testApp::changeDemoType);
    
    demoViewer.setup(160, 90);
    

    
    compassData = 0.0;

    accelXData = 0.0;
    accelYData = 0.0;
    accelZData = 0.0;

    gyroXData = 0.0;
    gyroYData = 0.0;
    gyroZData = 0.0;
    
    pressureData = 0.0;
    altData = 0.0;
    
    ambTempData = 0.0;
    objTempData = 0.0;
    humidData = 0.0;
    
    luxData = 0.0;
    
    sensorType = SENSOR_TOUCH;
    visualType = VISUAL_GRAPHIC;
    demoType = DEMO_NODEMO;

}

//--------------------------------------------------------------
void testApp::update(){
    
    //for each client lets send them a message letting them know what port they are connected on
	for(int i = 0; i < TCP.getLastID(); i++){
		if( !TCP.isClientConnected(i) )continue;
        
		TCP.send(i, "hello client - you are connected on port - "+ofToString(TCP.getClientPort(i)) );
	}

//    // fake data
//    float xtemp, ytemp,ztemp;
//    xtemp = 0.0;
//    ytemp = 0.0;
//    ztemp = 0.0;
//    //luxData = 0.0;
//    
//    xtemp = xtemp + ofSignedNoise(30*ofGetElapsedTimef()*1.0f)*20.0f;
//    ytemp = ytemp + ofSignedNoise(50*ofGetElapsedTimef()*1.0f)*40.0f;
//    ztemp = ztemp + ofSignedNoise(10*ofGetElapsedTimef()*1.0f)*30.0f;
//    
//    AccelXLine.addData(xtemp + 0.0);
//    AccelYLine.addData(ytemp+ 0.0);
//    AccelZLine.addData(ztemp+ 0.0);
    

    // set default data to 0.0
    compassLine.addData(compassData+ 0.0);

    AccelXLine.addData(accelXData + 0.0);
    AccelYLine.addData(accelYData+ 0.0);
    AccelZLine.addData(accelZData+ 0.0);
    
    GyroXLine.addData(gyroXData+ 0.0);
    GyroYLine.addData(gyroYData+ 0.0);
    GyroZLine.addData(gyroZData+ 0.0);
    
    pressureLine.addData(pressureData + 0.0);
    altLine.addData(altData+0.0);
    
    ambTempLine.addData(ambTempData + 0.0);
    objTempLine.addData(objTempData + 0.0);
    humidityLine.addData(humidData + 0.0);
    
    luxLine.addData(luxData+ 0.0);
    
    updateGrpahics();
    
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
                else if( idStr == "$ACX"){
                    accelXData = ofToFloat(dataStr);
                }
                else if( idStr == "$ACY"){
                    accelYData = ofToFloat(dataStr);
                }
                else if( idStr == "$ACZ"){
                    accelZData = ofToFloat(dataStr);
                }
                else if( idStr == "$GYX"){
                    gyroXData = ofToFloat(dataStr);
                }
                else if( idStr == "$GYY"){
                    gyroYData = ofToFloat(dataStr);
                }
                else if( idStr == "$GYZ"){
                    gyroZData = ofToFloat(dataStr);
                }
                else if( idStr == "$MAY"){
                    compassData = ofToFloat(dataStr);
                }
                else if (idStr == "$PRS" ){
                    pressureData = ofToFloat(dataStr);
                }
                else if (idStr == "$ALT" ){
                    altData = ofToFloat(dataStr);
                }
                else if (idStr == "$AMT" ){
                    ambTempData = ofToFloat(dataStr);
                }
                else if (idStr == "$OBT" ){
                    objTempData = ofToFloat(dataStr);
                }
                else if (idStr == "$HUM" ){
                    humidData = ofToFloat(dataStr);
                }
                
            }
        }
		//draw the info text and the received text bellow it
		ofDrawBitmapString(info, xPos, yPos);
		ofDrawBitmapString(storeText[i], 25, yPos + 20);
        
	}
    ofPopStyle();
    
    
    
    naviMenu.draw(0, 90);
    
    demoViewer.draw(demoType);
    
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
    
    AccelXLine.setup("X", ofColor(255,0,0));
    AccelXLine.setMinForDrawing(-20);
    AccelXLine.setMaxForDrawing(20);
    
    AccelYLine.setup("Y", ofColor(0,255,0));
    AccelYLine.setMinForDrawing(-20);
    AccelYLine.setMaxForDrawing(20);
    
    AccelZLine.setup("Z", ofColor(0,0,255));
    AccelZLine.setMinForDrawing(-20);
    AccelZLine.setMaxForDrawing(20);
    
    compassLine.setup("C", ofColor(255,255,0));
    compassLine.setMinForDrawing(-50);
    compassLine.setMaxForDrawing(50);
    
    
    GyroXLine.setup("X", ofColor(255,255,0));
    GyroXLine.setMinForDrawing(-5);
    GyroXLine.setMaxForDrawing(5);
    
    GyroYLine.setup("Y", ofColor(0,255,255));
    GyroYLine.setMinForDrawing(-5);
    GyroYLine.setMaxForDrawing(5);

    GyroZLine.setup("Z", ofColor(255,0,255));
    GyroZLine.setMinForDrawing(-5);
    GyroZLine.setMaxForDrawing(5);

    
    pressureLine.setup("P", ofColor(0,0,255));
    pressureLine.setMinForDrawing(950);
    pressureLine.setMaxForDrawing(1050);
    
    altLine.setup("A", ofColor(0,255,0));
    altLine.setMinForDrawing(-20);
    altLine.setMaxForDrawing(-10);
    
    ambTempLine.setup("A", ofColor(255,255,0));
    ambTempLine.setMinForDrawing(-40);
    ambTempLine.setMaxForDrawing(125);
    
    objTempLine.setup("O", ofColor(255,0,0));
    objTempLine.setMinForDrawing(-40);
    objTempLine.setMaxForDrawing(125);
    
    humidityLine.setup("H", ofColor(0,0,255));
    humidityLine.setMinForDrawing(0);
    humidityLine.setMaxForDrawing(100);
    
    colorLine.setup("C", ofColor(255,255,0));
    colorLine.setMinForDrawing(0);
    colorLine.setMaxForDrawing(255);
    
    luxLine.setup("L", ofColor(255,255,0));
    luxLine.setMinForDrawing(0.96);
    luxLine.setMaxForDrawing(64000);
    
    // setup before add the lines
    // otherwise the button will not be shown
    touchSensor.setup();
    motionSensor2D.setup();
    motionSensor3D.setup();
    pressAltSensor.setup();
    tempHumidSensor.setup();
    colorSensor.setup();
    luxSensor.setup();
    
    touchSensor.setInfo("TOUCH GESTURE", "lighting control gesture using touch sensor");
    motionSensor2D.setInfo("MOTION GESTURE 1", "lighting control gesture using accelrelometer & magnetometer");
    motionSensor3D.setInfo("MOTION GESTURE 2", "lighting control gesture using gyro sensor");
    pressAltSensor.setInfo("PRESSURE & ALTITUDE", "lighting congrol based on environmental data");
    tempHumidSensor.setInfo("TEMPERATURE & HUMIDITY", "lighting congrol based on environmental data");
    colorSensor.setInfo("COLOR CONTROL", "adjusting color mood using color sensor");
    luxSensor.setInfo("LUX CONTROL", "adjusting brightness using lux sensor");

    
    touchSensor.addLine(&touchProxiLine);
    touchSensor.addLine(&touchPressLine);
    touchSensor.addLine(&touchWheelLine);
    touchSensor.addLine(&touchGestureLine);
    touchSensor.addLine(&touchSleepLine);

    
    motionSensor2D.addLine(&compassLine);
    motionSensor2D.addLine(&AccelXLine);
    motionSensor2D.addLine(&AccelYLine);
    motionSensor2D.addLine(&AccelZLine);

    
    motionSensor2D.addGroup("COMPASS");
    motionSensor2D.addGroup("ACCELEROMETER");
    
    motionSensor2D.addLineToGroup(&compassLine, "COMPASS");
    
    motionSensor2D.addLineToGroup(&AccelXLine, "ACCELEROMETER");
    motionSensor2D.addLineToGroup(&AccelYLine, "ACCELEROMETER");
    motionSensor2D.addLineToGroup(&AccelZLine, "ACCELEROMETER");
    

    motionSensor3D.addLine(&GyroXLine);
    motionSensor3D.addLine(&GyroYLine);
    motionSensor3D.addLine(&GyroZLine);

    motionSensor3D.addGroup("GYRO");
    motionSensor3D.addLineToGroup(&GyroXLine, "GYRO");
    motionSensor3D.addLineToGroup(&GyroYLine, "GYRO");
    motionSensor3D.addLineToGroup(&GyroZLine, "GYRO");

    
    pressAltSensor.addLine(&pressureLine);
    pressAltSensor.addLine(&altLine);
    
    pressAltSensor.addGroup("PRESSURE");
    pressAltSensor.addGroup("ALTITUDE");
    
    pressAltSensor.addLineToGroup(&pressureLine, "PRESSURE");
    pressAltSensor.addLineToGroup(&altLine, "ALTITUDE");

    
    tempHumidSensor.addLine(&ambTempLine);
    tempHumidSensor.addLine(&objTempLine);
    tempHumidSensor.addLine(&humidityLine);
    
    tempHumidSensor.addGroup("AMB TEMP");
    tempHumidSensor.addGroup("OBJ TEMP");
    tempHumidSensor.addGroup("HUMIDITY");
    
    tempHumidSensor.addLineToGroup(&ambTempLine, "AMB TEMP");
    tempHumidSensor.addLineToGroup(&objTempLine, "OBJ TEMP");
    tempHumidSensor.addLineToGroup(&humidityLine, "HUMIDITY");

    
    colorSensor.addLine(&colorLine);
    colorSensor.addGroup("COLOR");
    colorSensor.addLineToGroup(&colorLine, "COLOR");

    
    luxSensor.addLine(&luxLine);
    luxSensor.addGroup("LUX");
    luxSensor.addLineToGroup(&luxLine, "LUX");
}

void testApp::updateGrpahics(){
    motionSensor2D.setAccelVal(accelXData, accelYData, accelZData);
    motionSensor2D.setCompassVal(compassData);
    motionSensor3D.setGyroVal(gyroXData, gyroYData, gyroZData);
    luxSensor.setLuxVal(ofMap(luxData, 0.0, 2000, 0.0, 255));
    pressAltSensor.setPressAltVal(pressureData, altData);
    tempHumidSensor.setTempHumidVal(ambTempData, objTempData, humidData);
}


void testApp::changeSensorType(LightSensorType &sensor){
    sensorType = sensor;
    
    
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

void testApp::changeVisualType(LightVisualType &visual){
    visualType = visual;
}

void testApp::changeDemoType(LightDemoType &demo){
    demoType = demo;
}


testApp::~testApp(){
    cout << "tcp closed" << endl;
    TCP.close();
}