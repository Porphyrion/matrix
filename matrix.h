#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include "element.h"
#include "proxy.h"

template<class T>
class RealElement;


template<class T, T N>
class Matrix{

    using iteratorType = typename std::map<std::pair<long, long>, RealElement<T>* >::iterator;
public:
    Matrix() : defaultElement(new RealElement<T>(N))
    {};

    Proxy<T, N> operator[](long x){
        Proxy<T, N> proxy(this, x);
        return proxy;
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
    };

    class Iterator{
    public:
        Iterator(iteratorType  matrixIt_):iterator(matrixIt_){};

        iteratorType getInsideIterator(){
            return this->iterator;
        }

        void operator++(){
            iterator++;
        };

        std::tuple<long, long, T> operator*(){
            return std::make_tuple(iterator->first.first, iterator->first.second, iterator->second->getValue());
        };

        void operator--(){
            iterator--;
        }

        bool operator !=(Iterator& other){
            return iterator != other.getInsideIterator();
        }

        bool operator ==(Iterator& other){
            return iterator == other.getInsideIterator();
        }

    private:
        iteratorType  iterator;
    };


    Iterator begin(){
        return Iterator(matrix.begin());
    };

    Iterator end(){
        return Iterator(matrix.end());
    };
private:
  RealElement<T> * defaultElement;
  std::map<std::pair<long, long>, RealElement<T>* > matrix;
};
