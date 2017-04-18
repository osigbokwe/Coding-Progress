#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>

int getRandomNumber(int min, int max);

class Apartment
{
private:
	char ** m_status; // array to hold state of each room in the apartment
	int m_rows;
	int m_cols;

protected:
	char operator() (int row, int col) { return m_status[row][col]; }

public:
	Apartment(int rows, int cols); // constructor

	int getRows() { return m_rows; }

	int getCols() { return m_cols; }

	friend std::ostream& operator<< (std::ostream &out, Apartment &building); //print function

	void computeEndState(); //calculate the final state of the apartment after user indicates where smoke appears
	
	~Apartment(); //destructor

};





#endif
