#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Set up GUI
    sliderGroup.setName("slider group");
    sliderGroup.add(elementsSlider.set("elements slider", 100, 2, 300));
    sliderGroup.add(speedSlider.set("speed slider", 0.5, 0.1, 1));
    sliderGroup.add(algorithmToggle.set(true));
    gui.setup(sliderGroup);
    displayGui = true;
    dataDisplay.setGuiParams(elementsSlider, speedSlider, algorithmToggle);
}

//--------------------------------------------------------------
void ofApp::update(){

    dataDisplay.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    dataDisplay.setGuiParams(elementsSlider, speedSlider, algorithmToggle); // This might belong in the update function, noticed bug when in update function, didnt always reset to first element properly - experiment
    dataDisplay.draw();
    if(displayGui){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key){
        case OF_KEY_RETURN:
            dataDisplay.togglePlayback();
            displayGui = ! displayGui;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
