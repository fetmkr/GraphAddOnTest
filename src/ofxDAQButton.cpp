//
//  ofxDAQButton.cpp
//  LightingDataVisualizer
//
//  Created by songhojun on 10/29/13.
//
//

#include "ofxDAQButton.h"

ofxDAQButton::ofxDAQButton(){
    bWasSetup = false;
}

ofxDAQButton::~ofxDAQButton(){
    clearEvents();
}

void ofxDAQButton::setup(float width, float height, bool bToggle, bool bDefaultVal, ButtonShapeType shape){
    
    shapeType = shape;
    
    if ( shapeType == BUTTON_SHAPE_RECT){
        buttonWidth = width;
        buttonHeight = height;
        buttonRect = ofRectangle(0, 0, buttonWidth, buttonHeight);
    }
    else if ( shapeType == BUTTON_SHAPE_CIRCLE){
        buttonRadius = width/2;
    }

    bToggleButton = bToggle;
    bIsPressed = bDefaultVal;
    bHasFocus = false;
    bIsPressed = false;
    bIsDragged = false;
    dragType = BUTTON_DRAG_NONE;
    
    // default color
    pressedColor = ofColor(0);
    releasedColor = ofColor(0);
    
    // default mouse XY
    mouseX = -1000.0;
    mouseY = -1000.0;
    startMouseX = -1000;
    startMouseY = -1000;
    
    bShowButton = true;
    
    if(!bWasSetup){
        ofRegisterMouseEvents(this);
        //        ofAddListener(ofEvents().mouseMoved, this, &ofxDAQButton::mouseMoved);
        //        ofAddListener(ofEvents().mousePressed, this, &ofxDAQButton::mousePressed);
        //        ofAddListener(ofEvents().mouseReleased, this, &ofxDAQButton::mouseReleased);
        //        ofAddListener(ofEvents().mouseDragged, this, &ofxDAQButton::mouseDragged);
		bWasSetup = true;
	}
}





void ofxDAQButton::clearEvents(){
    if(bWasSetup){
        ofUnregisterMouseEvents(this);
        //        ofRemoveListener(ofEvents().mouseMoved, this, &ofxDAQButton::mouseMoved);
        //        ofRemoveListener(ofEvents().mousePressed, this, &ofxDAQButton::mousePressed);
        //        ofRemoveListener(ofEvents().mouseReleased, this, &ofxDAQButton::mouseReleased);
        //        ofRemoveListener(ofEvents().mouseDragged, this, &ofxDAQButton::mouseDragged);
	}
	bWasSetup = false;
}

void ofxDAQButton::draw(float x, float y){
    transX = x;
    transY = y;
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(transX, transY);
    
    ofSetColor(255, 255, 255);    
    if (bShowButton) {
        ofSetCircleResolution(80);

        if(bIsPressed){
            showPressed();
        }
        
        showReleased();
    }

    ofPopMatrix();
    ofPopStyle();
    
}

void ofxDAQButton::setPressedColor(ofColor c){
    pressedColor = c;
}
void ofxDAQButton::setReleasedColor(ofColor c){
    releasedColor = c;
}

void ofxDAQButton::showPressed(){
    ofFill();
    ofSetColor(pressedColor);
    
    if(shapeType == BUTTON_SHAPE_RECT){
        ofRect(buttonRect);
    }else if (shapeType == BUTTON_SHAPE_CIRCLE) {
        ofCircle(0, 0, buttonRadius);
    }
}

void ofxDAQButton::showReleased(){
    ofNoFill();
    ofSetColor(releasedColor);
    
    if(shapeType == BUTTON_SHAPE_RECT){
        ofRect(buttonRect);
    }else if (shapeType == BUTTON_SHAPE_CIRCLE) {
        ofCircle(0, 0, buttonRadius);
    }
}

void ofxDAQButton::resize(float width, float height){
    buttonWidth = width;
    buttonHeight = height;
    buttonRect.setWidth(width);
    buttonRect.setHeight(height);
}

bool ofxDAQButton::isPressed(){
    return bIsPressed;
}

void ofxDAQButton::mouseMoved(ofMouseEventArgs& event){
    bHasFocus = false;
    if(IsInside(event.x, event.y) && !bIsPressed){

        
        mouseX = event.x;
        mouseY = event.y;
    }
}

void ofxDAQButton::mouseDragged(ofMouseEventArgs& event){
    if(bHasFocus){
        if(IsInside(event.x, event.y))
            
        {
            // evaluate drag value
            if(event.x - startMouseX > 0){
                //cout << "To the Right" << endl;
                dragType = BUTTON_DRAG_RIGHT;
            }
            else{
                //cout << "To the Left" << endl;
                dragType = BUTTON_DRAG_LEFT;
            }
            
            if(event.y - startMouseY < 0){
                //cout << "To Up" << endl;
                dragType = BUTTON_DRAG_UP;
            }
            else{
                //cout << "To Down" << endl;
                dragType = BUTTON_DRAG_DOWN;
            }
            
            startMouseY = event.y;
            startMouseX = event.x;
            
            bIsDragged = true;

        }
    }
}

void ofxDAQButton::mousePressed(ofMouseEventArgs& event){
    bHasFocus = false;
    if(IsInside(event.x, event.y))

    {

        bHasFocus = true;
        if (bToggleButton) {
            bIsPressed = !bIsPressed;

        }
        else{
            bIsPressed = true;
        }
        
        startMouseX = event.x;
        startMouseY = event.y;
    }
}

void ofxDAQButton::mouseReleased(ofMouseEventArgs& event){
    if (bHasFocus) {        
        if(IsInside(event.x, event.y) && !bIsPressed){
            mouseX = event.x;
            mouseY = event.y;
        }
        
        if (bToggleButton) {
        }
        else{
            bIsPressed = false;
        }
        bIsDragged = false;
        dragType = BUTTON_DRAG_NONE;
    }
    bHasFocus = false;
}

bool ofxDAQButton::IsInside(float x, float y){
    if(shapeType == BUTTON_SHAPE_RECT){
        return buttonRect.inside(x-transX, y-transY);
    }else if (shapeType == BUTTON_SHAPE_CIRCLE) {
        if( ofDist(0, 0, x-transX, y-transY) > buttonRadius){
            return false;
        }
        else {
            return true;
        }
    }
    
    return false;
}

void ofxDAQButton::showButton(bool bShow){
    bShowButton = bShow;
}

ofVec2f ofxDAQButton::getMouseXY(){
    return ofVec2f(mouseX, mouseY);
}


ButtonDragType ofxDAQButton::getDragType(){
    return dragType;
}