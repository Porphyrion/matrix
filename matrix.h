#pragma once
#include <vector>
#include <map>
#include "element.h"

template<class T, T N>
class Matrix{
  using valueType = T;

public:
    Matrix() : proxyElement(N, this)
    {};


    class ProxyElement{
    public:
        ProxyElement(valueType defaultValue_, Matrix<valueType, N> * matrixPtr_) : defaultValue(defaultValue_),
            matrixPtr(matrixPtr_)
        {};

        ProxyElement operator[](int y){
            return *this;
        };

         operator valueType() const{
            return defaultValue;
        }


    private:
        valueType defaultValue;
        Matrix<valueType, N> *  matrixPtr;
    };

    ProxyElement * operator[](valueType x){
        return &proxyElement;
    };

private:
  ProxyElement proxyElement;
  valueType defaultValue = N;
};
