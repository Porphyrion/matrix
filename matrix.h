#pragma once
#include <map>
#include <algorithm>
#include <tuple>
#include <memory>
#include "proxy.h"


template<class T, T N>
class Matrix{
    
    using IteratorType = typename std::map<std::pair<long, long>, T>::iterator;
    
public:
    Matrix() : defaultElement(N)
    {};
    
    ~Matrix(){
    }
    
    Proxy<T, N> operator[](long x){
        Proxy<T, N> proxy(this, x);
        return proxy;
    };
    
    size_t size(){
        return matrix.size();
    }
    
    T getDefaultElement(){
        return defaultElement;
    };
    
    //поиск элемента
    const T& findByCoord(std::pair<long, long> coordinates) const {
        auto it = matrix.find(coordinates);
        if( it == matrix.end()){
            return defaultElement;
        }
        else{
            return it->second;
        }
    };
    
    //удаление элемента
    void removeElement(std::pair<long, long> coordinates){
        matrix.erase(matrix.find(coordinates));
    };
    
    //вставка элемента
    void insertElement(std::pair<long, long> coordinates, T value){
        matrix.emplace(coordinates, value);
    };
    
    //итератор
    class Iterator{
    public:
        Iterator(IteratorType  matrixIt_):iterator(matrixIt_){};
        
        IteratorType getInsideIterator(){
            return this->iterator;
        }
        
        void operator++(){
            iterator++;
        };
        
        std::tuple<long, long, T> operator*(){
            return std::make_tuple(iterator->first.first, iterator->first.second, iterator->second);
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
        IteratorType  iterator;
    };
    
    
    Iterator begin(){
        return Iterator(matrix.begin());
    };
    
    Iterator end(){
        return Iterator(matrix.end());
    };
private:
    
    const T defaultElement;
    std::map<std::pair<long, long>, T > matrix;
};
