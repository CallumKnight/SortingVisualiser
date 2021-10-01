#pragma once

#include "ofMain.h"
#include "BaseSort.h"
#include "Gui.h"
#include <vector>

class DataDisplay{

    public:
        DataDisplay();
        ~DataDisplay();

        void setup();
        void update();
        void draw();
        void togglePlayback();
        void setGuiParams(int numElems, float speed, bool algoToggle);

    private:
        void setDisplayDimensions(int dispWidth, int dispHeight);
        void generateRandomElements(int numElements);
        
        std::vector<float> elements;
        int displayWidth;
        int displayHeight;
        bool playbackStatus;
        float playbackSpeed;
        bool swappingElements;
        float swapOffset;

        Gui gui;
        BaseSort* sortingAlgorithm;
};

