#include "DataDisplay.h"
#include "BubbleSort.h"
#include <ctime>
#include <cstdlib>

#define DEFAULT_NUM_OF_ELEMENTS 50

DataDisplay::DataDisplay(){

    setDisplayDimensions(ofGetWidth(), ofGetHeight());
    generateRandomElements(DEFAULT_NUM_OF_ELEMENTS);

    start = false;
    swappingElements = false;
    swapOffset = 0;
    algorithmToggle = true;

    sortingAlgorithm = new BubbleSort();
}

DataDisplay::~DataDisplay(){
    
    delete sortingAlgorithm;
}

void DataDisplay::update(){

    if(start && !swappingElements){

        sortingAlgorithm->sort(elements);
        swappingElements = sortingAlgorithm->getSwapStatus();
        start = !sortingAlgorithm->isSortComplete();
    }
}

void DataDisplay::draw(){

    float currentTime = ofGetElapsedTimef();
    
    float barSpacing = 0.4*(static_cast<float>(displayWidth)/elements.size());
    float barWidth = 0.6*(static_cast<float>(displayWidth)/elements.size());
    float barFootprint = barSpacing + barWidth;

    ofColor barColor;
    ofColor barContour(255); // White

    for(int i = 0; i < elements.size(); i++){

        barColor.setHsb((elements[i]/displayHeight)*255, 255, 255); // Rainbow effect

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

        while((ofGetElapsedTimef() - currentTime) < 0.005*playbackSpeed){
            // Delay
        }

    }
    else{
        
        while((ofGetElapsedTimef() - currentTime) < 0.5*playbackSpeed){
            // Delay
        }
    }
}

void DataDisplay::togglePlayback(){
    
    start = !start;
}

void DataDisplay::setGuiParams(int numElems, float speed, bool algoToggle){

    if(!start && !swappingElements){ 
        if(numElems != elements.size()){
            generateRandomElements(numElems);
            sortingAlgorithm->reset();
        }
        playbackSpeed = speed;
        algorithmToggle = algoToggle;
    }

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