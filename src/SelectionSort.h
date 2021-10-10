#pragma once

#include "BaseSort.h"
#include <vector>

class SelectionSort : public BaseSort{

    public:
        SelectionSort();
        virtual ~SelectionSort();

        virtual void sort(const std::vector<float> &elements);
    
    private:
        bool cascadingSwap;
};