#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include<algorithm>
#include<Windows.h>
class Spots
{
private:
	int size=4;
	int** plate;
	int random();
	bool not_there(int value, int **plate);

public:
	Spots();
	Spots(Spots& other);
	Spots(int ** known_plate);
	~Spots();
	void show();
	void move(int value, std::string  direction);
	bool is_correct();
	int get_element(int row, int column);
	int** get_plate();
	int get_size();
	int* operator [](int i);
	friend std::ostream& operator <<(std::ostream& outlet, Spots& game);
	bool operator ==(const Spots& other) const;
	bool operator !=(const Spots& other) const;
};

