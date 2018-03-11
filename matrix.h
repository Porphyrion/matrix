#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include "element.h"
#include "proxy.h"

template<class T>
class RealElement;


template<class T, T N>
class Matrix{
public:
    Matrix() : proxy(new Proxy<T, N>(this, 0)), defaultElement(new RealElement<T>(N))
    {};

    Proxy<T, N> operator[](long x){
        Proxy<T, N> p(this, x);
        return p;
    };

    size_t size(){
        return matrix.size();
    }

    RealElement<T>* getDefaultElement(){
        return defaultElement;
    };

    RealElement<T>* findByCoord(std::tuple<long, long> coordinates){
        auto it = matrix.find(coordinates);
        if( it == matrix.end()){
            return defaultElement;
        }
        else{
            return it->second;
        }
    };

    void removeElement(std::pair<long, long> coordinates){
        matrix.erase(matrix.find(coordinates));
    };

    void insertElement(std::pair<long, long> coordinates, T value){
        matrix.emplace(coordinates, new RealElement<T>(value));
    }


private:
  Proxy<T, N> * proxy;
  RealElement<T> * defaultElement;
  std::map<std::pair<long, long>, RealElement<T>* > matrix;
};
