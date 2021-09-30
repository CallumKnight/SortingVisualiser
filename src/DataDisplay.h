#pragma once

#include "ofMain.h"
#include "BaseSort.h"
#include <vector>

class DataDisplay{

    public:
        DataDisplay();
        ~DataDisplay();

        void setup(int numElements, int dispWidth = ofGetWidth(), int dispHeight = ofGetHeight());
        void update();
        void draw();
        void togglePlayback();

    private:
        void setDisplayDimensions(int dispWidth, int dispHeight);
        void generateRandomElements(int numElements);
        
        std::vector<float> elements;
        int displayWidth;
        int displayHeight;
        bool start;
        bool swappingElements;
        float swapOffset;

        BaseSort* sortingAlgorithm;
};

