#pragma once

#include "BaseSort.h"
#include <vector>

class BubbleSort : public BaseSort{

    public:
        BubbleSort();
        virtual ~BubbleSort();

        virtual void sort(const std::vector<float> &elements);
};