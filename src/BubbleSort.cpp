#include "BubbleSort.h"

BubbleSort::BubbleSort(): BaseSort(){

    // Calls BaseSort constructor

    // Sets BubbleSort parameters
    elementIndex = -1;
    compareElementIndex = 0;
}

BubbleSort::~BubbleSort(){
    
    // Will automatically call base class destructor after calling this one
}

void BubbleSort::sort(const std::vector<float> &elements){

    elementIndex++;
    compareElementIndex = elementIndex + 1;

    if(elementIndex >= (elements.size() - iteration - 1)){
        elementIndex = 0;
        compareElementIndex = elementIndex + 1;
        iteration++;
    }

    if(iteration >= elements.size() - 1){
        elementIndex = 0;
        compareElementIndex = elementIndex + 1;
        iteration = 0;
        sortComplete = true;
    }

    if(elements[elementIndex] > elements[compareElementIndex]){
    
        swapStatus = true;
    }
    else{
        swapStatus = false;
    }
}