#pragma once

#include "matrix.h"
#include "element.h"

template<class T, T N>
class Matrix;

template<class T>
class RealElement;

template<class T, T N>
class Proxy{
public:
    Proxy(Matrix<T, N> * matrixPtr_, long x_) :
        matrixPtr(matrixPtr_), element(nullptr), x(x_)
    {};

    Proxy& operator[](int y){
        coord = std::make_pair(x, y);
        element = matrixPtr->findByCoord(coord);

        return *this;
    };

    void operator=(T newValue){
        if(newValue != matrixPtr->getDefaultElement()->getValue()){
            if(element != matrixPtr->getDefaultElement()){
                element->setValue(newValue);
            }
            else{
                matrixPtr->insertElement(coord, newValue);
            }
        }
        else{
            if(element != matrixPtr->getDefaultElement()){
                matrixPtr->removeElement(coord);
                return;
            }
            else return;
        }

    };

    operator T(){
        return element->getValue();
    }

private:
    long x;
    std::pair<long, long> coord;
    RealElement<T> * element;
    Matrix<T, N>*  matrixPtr;
};
