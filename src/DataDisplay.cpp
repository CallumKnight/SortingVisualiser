#include "DataDisplay.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include <ctime>
#include <cstdlib>

#define DEFAULT_NUM_OF_ELEMENTS 50

DataDisplay::DataDisplay(){

    sortingAlgorithm = new SelectionSort();
}

DataDisplay::~DataDisplay(){
    
    delete sortingAlgorithm;
}

void DataDisplay::setup(){

    gui.setup();
    setDisplayDimensions(ofGetWidth(), ofGetHeight());
    generateRandomElements(gui.getElements());
    playbackStatus = false;
    playbackSpeed = gui.getSpeed();
    swappingElements = false;
    swapOffset = 0;
}

void DataDisplay::update(){

    if(!swappingElements){

        if(playbackStatus){

            sortingAlgorithm->sort(elements);
            swappingElements = sortingAlgorithm->getSwapStatus();
            playbackStatus = !sortingAlgorithm->isSortComplete();
        }
        else{

            if(gui.getElements() != elements.size()){
                sortingAlgorithm->reset();
                generateRandomElements(gui.getElements());
            }
            playbackSpeed = gui.getSpeed();
        }
    }
}

void DataDisplay::draw(){

    float currentTime = ofGetElapsedTimef();
    
    float barSpacing = 0.4*(static_cast<float>(displayWidth)/elements.size());
    float barWidth = 0.6*(static_cast<float>(displayWidth)/elements.size());
    float barFootprint = barSpacing + barWidth;

    ofColor barColor;
    ofColor barContour(255); // White

    ofBackground(0);

    for(int i = 0; i < elements.size(); i++){

        barColor.set(((elements[i]/displayHeight)*200)+55, 55, 55);

        if(i == sortingAlgorithm->getElementIndex()){

            ofFill();
            ofSetColor(barColor);
            ofDrawRectangle((barFootprint*i) + swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
            ofNoFill();  
            ofSetColor(barContour);
            ofDrawRectangle((barFootprint*i) + swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
        }
        else if(i == sortingAlgorithm->getCompareElementIndex()){

            ofFill();
            ofSetColor(barColor);
            ofDrawRectangle((barFootprint*i) - swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
            ofNoFill();  
            ofSetColor(barContour);
            ofDrawRectangle((barFootprint*i) - swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
        }
        else{

            ofFill();
            ofSetColor(barColor);
            ofDrawRectangle(barFootprint*i, ofGetHeight(), barWidth, elements[i]*(-1));
        }
    }

    if(swappingElements){

        swapOffset++;

        if(swapOffset >= ((barFootprint*sortingAlgorithm->getCompareElementIndex()) - (barFootprint*sortingAlgorithm->getElementIndex()))){
            
            swap(elements[sortingAlgorithm->getElementIndex()], elements[sortingAlgorithm->getCompareElementIndex()]);
            swapOffset = 0;
            swappingElements = false;
        }

        while((ofGetElapsedTimef() - currentTime) < (0.01*(1/playbackSpeed))){
            // Delay
        }
    }
    else if(playbackStatus){

        while((ofGetElapsedTimef() - currentTime) < (0.1/playbackSpeed)){
            // Delay
        }
    }      
    else{

        gui.draw();
    }

    // Speed control could be improved
}

void DataDisplay::togglePlayback(){
    
    playbackStatus = !playbackStatus;

}

void DataDisplay::setDisplayDimensions(int dispWidth, int dispHeight){

    displayWidth = dispWidth;
    displayHeight = dispHeight;
}

void DataDisplay::generateRandomElements(int numElements){

    float element;
    
    srand(time(NULL));
    elements.clear();

    for(int i = 0; i < numElements; i++){ 
       
       element = (rand() % displayHeight) + 1;
       elements.push_back(element);
    }
}