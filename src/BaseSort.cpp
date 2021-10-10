#include "BaseSort.h"

BaseSort::BaseSort(){

    iteration = 0;
    elementIndex = -1;
    compareElementIndex = 0;
    swapStatus = false;
    sortComplete = false;
}

BaseSort::~BaseSort(){

    // Does nothing
}

int BaseSort::getElementIndex(){

    return elementIndex;
}

int BaseSort::getCompareElementIndex(){

    return compareElementIndex;
}

bool BaseSort::getSwapStatus(){

    return swapStatus;
}

bool BaseSort::isSortComplete(){

    return sortComplete;
}

void BaseSort::reset(){

    iteration = 0;
    elementIndex = 0;
    compareElementIndex = 1;
    swapStatus = false;
    sortComplete = false;
}