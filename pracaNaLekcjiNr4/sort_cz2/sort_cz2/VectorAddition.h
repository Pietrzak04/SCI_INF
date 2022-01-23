#pragma once
#include <time.h> 
#include <vector>
#include <iostream>

template <class T>
class VectorAddition
{
public:
	void fillVector(std::vector<T>& v, unsigned int maxValue)
	{
		srand(time(NULL));

		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (typeid(T) == typeid(float))
			{
				v.at(i) = randomFloat(maxValue);
			}else{
				v.at(i) = randomInt(maxValue);
			}
		}
	}

	void printVector(std::vector<T>& v)
	{
		for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}

private:
	int randomInt(unsigned int maxValue)
	{
		return rand() % maxValue;
	}

	float randomFloat(unsigned int maxValue)
	{
		return float(rand() % maxValue) + static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
	}
};

