#include "Gui.h"

Gui::Gui(){
    
    // Does nothing
}

Gui::~Gui(){
    
    // Does nothing
}

void Gui::setup(){

    sliderGroup.setName("slider group");
    sliderGroup.add(elementsSlider.set("elements slider", 50, 2, 300));
    sliderGroup.add(speedSlider.set("speed slider", 0.5, 0.1, 1));
    gui.setup(sliderGroup);
}

void Gui::draw(){

        gui.draw();
}

int Gui::getElements(){

    return elementsSlider;
}

float Gui::getSpeed(){

    return speedSlider;
}