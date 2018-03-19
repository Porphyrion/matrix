#pragma once

#include "matrix.h"
#include <memory>

template<class T, T N>
class Matrix;


template<class T, T N>
class Proxy{
public:
    Proxy(Matrix<T, N> * matrixPtr_, long x_) :
    matrixPtr(matrixPtr_), element(0), x(x_)
    {};
    
    ~Proxy(){
    };
    
    Proxy& operator[](int y){
        coord = std::make_pair(x, y);
        element = matrixPtr->findByCoord(coord);
        return *this;
    };
    
    void operator=(T newValue){
        if(newValue != matrixPtr->getDefaultElement()){
            if(element != matrixPtr->getDefaultElement()){
                element = newValue;
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
        return element;
    }
    
private:
    long x;
    std::pair<long, long> coord;
    T element;
    Matrix<T, N>*  matrixPtr;
};
