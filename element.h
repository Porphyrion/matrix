#pragma once

#include <vector>
#include <tuple>
#include <map>

template<class T>
class Element{
public:
    T value;
};


template<class T>
class realElement : public Element<T>{
public:
    realElement(T val) : value(val){};
    T value;
};
/*template<class T>
class ProxyElement{
    using valueType = T;
public:
    ProxyElement(valueType defaultValue_, std::unique_ptr<Matrix<T, defaultValue_>> matrixPtr_) : defaultValue(defaultValue_),
     matrixPtr(matrixPtr_)
    {};

private:
    valueType defaultValue;
    std::unique_ptr<valueType> matrixPtr;
};*/
