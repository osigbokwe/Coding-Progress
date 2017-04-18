#include "stdafx.h"
#include "Apartment.h"
#include <cstdlib>

Apartment::Apartment(int rows, int cols): m_rows(rows), m_cols(cols)
{
	m_status = new char*[rows];

	for (int i = 0; i < rows; i++)
		m_status[i] = new char[cols];


	for (int i = 0; i < rows ; i++)
	{
		m_status[i][0] = '#';
		m_status[i][cols - 1] = '#';
	}

	for (int j = 1; j < (cols - 1); j++)
	{
		m_status[0][j] = '#';
		m_status[rows - 1][j] = '#';
	}
	
	int state;

	for (int i = 1; i < (rows - 1); i++)
		for (int j = 1; j < (cols - 1); j++)
		{
			state = getRandomNumber(1, 8);

			switch (state)
			{
				case 1:
					m_status[i][j] = 'S'; break;
				case 2:
					m_status[i][j] = 'F'; break;
				case 3:
					m_status[i][j] = '#'; break;
				case 4:
					m_status[i][j] = '|'; break;
				case 5:
					m_status[i][j] = '/'; break;
				case 6:
					m_status[i][j] = '='; break;
				case 7:
					m_status[i][j] = '_'; break;
				case 8:
					m_status[i][j] = ' ' ; break;
			}
		}
		

}

void Apartment::computeEndState()
{
	bool done = false;  // flag to mark when we're done selecting which tiles have smoke on them.


	// Loop to query the user for tiles where smoke appears.
	while (!done)
	{
		std::cout << "Please enter the row index of the tile where smoke appears: ";
		int row;
		std::cin >> row;

		std::cout << "Please enter the column index of the tile where smoke appears: ";
		int col;
		std::cin >> col;


		// Index checking for the row and column values the user just put in.
		if (row < 0 || row > (m_rows-1) || col < 0 || col > (m_cols - 1))
		{
			std::cout << "Those indices are not in bounds.\n";
			continue;
		}

		// Check the status of the tile before "applying smoke" to that tile and change accordingly.
		switch (m_status[row][col])
		{
		case 'S':
			m_status[row][col] = 'F'; break;
		case 'F':
			m_status[row][col] = 'F'; break;
		case '#':
		case '|':
		case '/':
		case '=':
		case '_':
			std::cout << "Please pick an appropriate tile.\n"; continue;
		case ' ':
			m_status[row][col] = 'S'; break;
		}

	}
}

Apartment::~Apartment()
{
	for (int i = 0; i < m_rows; i++)
		delete[] m_status[i];
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

std::ostream& operator<<(std::ostream &out, Apartment &building)
{
	for (int i = 0; i < building.getRows(); i++) 
	{
		for (int j = 0; j < building.getCols(); j++)
			out << building(i, j) << ' ';
		out << '\n';
	}

	return out;
}
