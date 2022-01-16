#pragma once
#include <vector>

template <class T>
class SortAlgoritm
{
public:
    void bubbleSort(std::vector<T>& v)
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            for (unsigned int j = 0; j < v.size() - 1; j++)
            {
                if (v[j] > v[j + 1])  std::swap(v[j], v[j + 1]);
            }
        }
    }

    void insertionSort(std::vector<T>& v)
    {
        T key;
        int j;
        for (int i = 1; i < v.size(); i++)
        {
            key = v[i];
            j = i - 1;

            while (j >= 0 && v[j] > key)
            {
                v[j + 1] = v[j];
                j--;
            }

            v[j + 1] = key;
        }
    }

    void selectionSort(std::vector<T>& v)
    {
        unsigned int i, j, min_idx;

        for (i = 0; i < v.size() - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < v.size(); j++)
                if (v[j] < v[min_idx])
                    min_idx = j;

            std::swap(v[min_idx], v[i]);
        }
    }
};

