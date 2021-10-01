#pragma once

#include <vector>

class BaseSort{

    public:
        BaseSort();
        virtual ~BaseSort();

        int getElementIndex();
        int getCompareElementIndex();
        bool getSwapStatus();
        bool isSortComplete();
        void reset();

        virtual void sort(const std::vector<float> &elements) = 0;

    protected:
        int iteration;
        int elementIndex;
        int compareElementIndex;
        bool swapStatus;
        bool sortComplete;
};