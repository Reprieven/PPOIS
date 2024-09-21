#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include<algorithm>
#include<Windows.h>
class spots
{
private:
	int size=4;
	int** plate;
	int random();
	bool not_there(int value, int **plate);

public:
	spots();
	spots(spots& other);
	~spots();
	void move(int value, std::string  direction);
	bool is_correct(int** plate);
	int get_element(int row, int column);
	int** get_plate();
	int get_size();
	int* operator [](int i);
	friend std::ostream& operator <<(std::ostream& outlet, spots& game);
	bool operator ==(const spots& other) const;
	bool operator !=(const spots& other) const;
};

