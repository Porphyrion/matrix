#pragma once

template<class T>
class RealElement{
public:
    RealElement(T val) : value(val){};

    T getValue(){
        return value;
    };

    void setValue(T value_){
        value = value_;
    }

    T value;
};
