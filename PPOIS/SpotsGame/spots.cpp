#include "pch.h"
#include "spots.h"

int spots::random() 
{
	return rand() % (size * size);
}

bool spots::not_there(int value, int** plate)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (plate[i][j] == value)
			{
				return false;
			}
		}
	}
	return true;
}

spots::spots()
{
	srand(time(NULL));
	int value = 0;
	plate = new int* [size];
	for (int i = 0; i < size; i++)
	{
		plate[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			plate[i][j] = -1;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			while (true)
			{
				value = random();
				if (not_there(value, plate))
				{
					plate[i][j] = value;
					break;
				}
			}
		}
	}
}

spots::spots(spots& other) 
{
	plate = new int* [size];
	for (int i = 0; i < size; i++)
	{
		plate[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			plate[i][j] = other.plate[i][j];
		}
	}
}

spots::~spots()
{
	for (int i = 0; i < size; i++)
	{
		delete[] plate[i];
	}
	delete[] plate;
}

void spots::move(int value, std::string direction)
{
	int row = 0, column = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (plate[i][j] == value)
			{
				row = i;
				column = j;
			}
		}
	}
	switch (direction[0])
	{
	case 'u':
		if (row != 0 && plate[row - 1][column] == 0)
		{
			std::swap(plate[row][column], plate[row - 1][column]);
		}
		break;
	case 'd':
		if (row != size - 1 && plate[row + 1][column] == 0)
		{
			std::swap(plate[row][column], plate[row + 1][column]);
		}
		break;
	case 'l':
		if (column != 0 && plate[row][column - 1] == 0)
		{
			std::swap(plate[row][column], plate[row][column - 1]);
		}
		break;
	case 'r':
		if (column != size - 1 && plate[row][column + 1] == 0)
		{
			std::swap(plate[row][column], plate[row][column + 1]);
		}
		break;
	default:
		break;
	}
}

bool spots::is_correct(int** plate)
{
	int check_value = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (check_value == size * size)
			{
				return true;
			}
			if (plate[i][j] != check_value)
			{
				return false;
			}
			check_value++;
		}
	}
}

int spots::get_element(int row, int column)
{
	return plate[row][column];
}

int** spots::get_plate()
{
	int** plate_copy = new int* [size];
	for (int i = 0; i < size; i++) 
	{
		plate_copy[i] = new int[size];
		for (int j = 0; j < size; j++) 
		{
			plate_copy[i][j] = plate[i][j];
		}
	}
	return plate_copy;
}

int spots::get_size() 
{
	return size;
}

int*spots::operator [](int i)
{
	return plate[i];
}

std::ostream& operator <<(std::ostream& outlet, spots& game)
{
	for (int i = 0; i <game.size; i++)
	{
		for (int j = 0; j < game.size; j++) 
		{
			outlet << std::setw(2) << game.plate[i][j] << " ";
		}
		outlet << "\n";
	}
	return outlet;
}

bool spots::operator==(const spots& other) const
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			if (plate[i][j] != other.plate[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool spots::operator!=(const spots& other) const
{
	if (*this == other) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}

