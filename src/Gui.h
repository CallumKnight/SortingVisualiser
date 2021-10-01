#pragma once

#include "ofxGui.h"

class Gui{

    public:
        Gui();
        virtual ~Gui();

        void setup();
        void draw();
        int getElements();
        float getSpeed();

    protected:
        ofxPanel gui;
		ofParameterGroup sliderGroup;
		ofParameter<int> elementsSlider;
		ofParameter<float> speedSlider;
};