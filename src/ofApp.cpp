#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Set up GUI
    sliderGroup.setName("slider group");
    sliderGroup.add(rSlider.set("r slider", 100, 0, 255));
    sliderGroup.add(gSlider.set("g slider", 100, 0, 255));
    sliderGroup.add(bSlider.set("b slider", 100, 0, 255));
    gui.setup(sliderGroup);
}

//--------------------------------------------------------------
void ofApp::update(){

    dataDisplay.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    dataDisplay.draw();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key){
        case OF_KEY_RETURN:
            dataDisplay.togglePlayback();
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
