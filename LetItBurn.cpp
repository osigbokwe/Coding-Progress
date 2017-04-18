// LetItBurn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Apartment.h"
#include <ctime>
#include <cstdlib>


int main()
{
	std::cout << "Please enter the number of rows in the apartment: ";
	int rows;
	std::cin >> rows;

	std::cout << "Please enter the number of columns in the apartment: ";
	int cols;
	std::cin >> cols;

	srand(static_cast<unsigned int>(time(0)));

	rand();


	Apartment apartment(rows, cols);

	std::cout << apartment;

    return 0;
}

