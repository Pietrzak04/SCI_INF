#pragma once
#include <vector>

template <class T>
class Sortowanie
{
public:
    void bubbleSort(std::vector<T> v);
    void insertionSort(std::vector<T> v);
    void printVector(std::vector<T> v);
};

