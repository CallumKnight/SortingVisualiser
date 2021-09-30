#include "DataDisplay.h"
#include "BubbleSort.h"
#include <ctime>
#include <cstdlib>

#define DEFAULT_NUM_OF_ELEMENTS 10

DataDisplay::DataDisplay(){

    setDisplayDimensions(ofGetWidth(), ofGetHeight());
    generateRandomElements(DEFAULT_NUM_OF_ELEMENTS);

    start = false;
    swappingElements = false;
    swapOffset = 0;

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

    for(int i = 0; i < elements.size(); i++){

        int r = (elements[i]/displayHeight)*barColorR;
        int g = (elements[i]/displayHeight)*barColorG;
        int b = (elements[i]/displayHeight)*barColorB;

        if(i == sortingAlgorithm->getElementIndex()){

            ofFill();
            ofSetColor(r, g, b);
            ofDrawRectangle((barFootprint*i) + swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
            ofNoFill();  
            ofSetColor(barColorContour);
            ofDrawRectangle((barFootprint*i) + swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
        }
        else if(i == sortingAlgorithm->getCompareElementIndex()){

            ofFill();
            ofSetColor(r, g, b);
            ofDrawRectangle((barFootprint*i) - swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
            ofNoFill();  
            ofSetColor(barColorContour);
            ofDrawRectangle((barFootprint*i) - swapOffset, ofGetHeight(), barWidth, elements[i]*(-1));
        }
        else{

            ofFill();
            ofSetColor(r, g, b);
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

        while((ofGetElapsedTimef() - currentTime) < 0.002){
            // Delay
        }

    }
    else{
        
        while((ofGetElapsedTimef() - currentTime) < 0.2){
            // Delay
        }
    }
}

void DataDisplay::togglePlayback(){
    
    start = !start;
}

void DataDisplay::setColors(int r, int g, int b, int contour, int background){

    barColorR = r;
    barColorG = g;
    barColorB = b;
    barColorContour = contour;
    ofBackground(background);
}

// void DataDisplay::setNumElements(int numElements){

//     // When !start and !swappingElements
//     // Set sorting algorithm to default values
//     // Generate random elements of the new set amount
    
//     generateRandomElements(numElements);

// }

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