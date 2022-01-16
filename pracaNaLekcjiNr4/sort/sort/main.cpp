//https://4programmers.net/Forum/C_i_C++/293867-nierozpoznany_zewnetrzny_symbol_public_thiscall

#include <iostream>
#include <algorithm>
#include "VectorAddition.h"
#include "SortAlgoritm.h"

char getAlgoritm()
{
	char algoritm;
	std::cout << "wybierz algorytm sortowania" << std::endl;
	std::cout << "1) bouble sort" << std::endl;
	std::cout << "2) insertion sort" << std::endl;
	std::cout << "3) selection sort" << std::endl;
	std::cout << "4) std sort" << std::endl;

	std::cin >> algoritm;

	return algoritm;
}

int main()
{
	int size;
	char type;

	std::cout << "podaj ilosc elementow" << std::endl;
	std::cin >> size;

	//funkcje i klasy dla int
	std::vector<int>* arrayInt = new std::vector<int>(size);
	VectorAddition<int>* vectorFunctionsInt = new VectorAddition<int>;
	SortAlgoritm<int>* sortAlgoritmInt = new SortAlgoritm<int>;

	//funkcje i klasy dla float
	std::vector<float>* arrayFloat = new std::vector<float>(size);
	VectorAddition<float>* vectorFunctionsFloat = new VectorAddition<float>;
	SortAlgoritm<float>* sortAlgoritmFloat = new SortAlgoritm<float>;

	//funkcje i klasy dla char
	std::vector<char>* arrayChar = new std::vector<char>(size);
	VectorAddition<char>* vectorFunctionsChar = new VectorAddition<char>;
	SortAlgoritm<char>* sortAlgoritmChar = new SortAlgoritm<char>;

	std::cout << "podaj typ datnych" << std::endl;
	std::cout << "1) int" << std::endl;
	std::cout << "2) float" << std::endl;
	std::cout << "3) char" << std::endl;

	std::cin >> type;

	switch (type)
	{
		case '1':
			vectorFunctionsInt->fillVector(*arrayInt, 1000);
			vectorFunctionsInt->printVector(*arrayInt);

			switch (getAlgoritm())
			{
			case '1':
				sortAlgoritmInt->bubbleSort(*arrayInt);
				break;
			case '2':
				sortAlgoritmInt->insertionSort(*arrayInt);
				break;
			case '3':
				sortAlgoritmInt->selectionSort(*arrayInt);
				break;
			case '4':
				std::sort(arrayInt->begin(), arrayInt->end());
				break;
			}

			std::cout << "posortowane: " << std::endl;
			vectorFunctionsInt->printVector(*arrayInt);

			break;
	
		case '2':
			vectorFunctionsFloat->fillVector(*arrayFloat, 1000);
			vectorFunctionsFloat->printVector(*arrayFloat);

			switch (getAlgoritm())
			{
			case '1':
				sortAlgoritmFloat->bubbleSort(*arrayFloat);
				break;
			case '2':
				sortAlgoritmFloat->insertionSort(*arrayFloat);
				break;
			case '3':
				sortAlgoritmFloat->selectionSort(*arrayFloat);
				break;
			case '4':
				std::sort(arrayFloat->begin(), arrayFloat->end());
				break;
			}

			std::cout << "posortowane: " << std::endl;
			vectorFunctionsFloat->printVector(*arrayFloat);

			break;

		case '3':
			vectorFunctionsChar->fillVector(*arrayChar, 255);
			vectorFunctionsChar->printVector(*arrayChar);
			
			switch (getAlgoritm())
			{
			case '1':
				sortAlgoritmChar->bubbleSort(*arrayChar);
				break;
			case '2':
				sortAlgoritmChar->insertionSort(*arrayChar);
				break;
			case '3':
				sortAlgoritmChar->selectionSort(*arrayChar);
				break;
			case '4':
				std::sort(arrayChar->begin(), arrayChar->end());
				break;
			}

			std::cout << "posortowane: " << std::endl;
			vectorFunctionsChar->printVector(*arrayChar);
			
			break;
	}
	return 0;
}