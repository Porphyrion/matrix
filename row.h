#pragma once


#include <memory>
#include "matrix.h"
#include "element.h"

template<class T>
class Row{

using valueType = T;
public:
    Row(T defaultValue_,std::shared_ptr<Matrix> matrixPtr_) : defaultValue(defaultValue_),
                        matrixPtr(matrixPtr_){};


private:
    valueType defaultValue;
    std::shared_ptr<Matrix> matrixPtr;
};
