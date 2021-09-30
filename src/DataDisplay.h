#pragma once

#include "ofMain.h"
#include "BaseSort.h"
#include <vector>

class DataDisplay{

    public:
        DataDisplay();
        ~DataDisplay();

        void update();
        void draw();
        void togglePlayback();
        void setColors(int r, int g, int b, int contour, int background);
        // void setNumElements(int numElements);

    private:
        void setDisplayDimensions(int dispWidth, int dispHeight);
        void generateRandomElements(int numElements);
        
        std::vector<float> elements;
        int displayWidth;
        int displayHeight;
        bool start;
        bool swappingElements;
        float swapOffset;
        int barColorR;
        int barColorG;
        int barColorB;
        int barColorContour;

        BaseSort* sortingAlgorithm;
};

