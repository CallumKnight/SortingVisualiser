#include "SelectionSort.h"

SelectionSort::SelectionSort(): BaseSort(){

    // Calls BaseSort constructor

    // Sets SelectionSort parameters
    cascadingSwap = false;
}

SelectionSort::~SelectionSort(){
    
    // Will automatically call base class destructor after calling this one
}

void SelectionSort::sort(const std::vector<float> &elements){

    if(!cascadingSwap){

        elementIndex++;

        if(elementIndex > (elements.size() - 1)){
            cascadingSwap = true;
            elementIndex = compareElementIndex + 1;
        }
        else{
            
            if(elements[elementIndex] <= elements[compareElementIndex]){
            
                compareElementIndex = elementIndex;
            }
        }
    }
    else{

        swapStatus = true;

        elementIndex--;
        compareElementIndex--;

        if(elementIndex <= iteration){
            
            cascadingSwap = false;
            swapStatus = false;

            iteration++;
            if(iteration >= (elements.size() - 1)){
                sortComplete = true;
                elementIndex = 0;
                compareElementIndex = elementIndex;
                iteration = 0;
            }
            else{
                elementIndex = iteration - 1;
                compareElementIndex = iteration;
            }
        }
    }
}