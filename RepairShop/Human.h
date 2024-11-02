#pragma once
using namespace std;
class Human
{
protected:
	string last_name;
	string first_name;
	string patronymic;
public:
	Human();
	Human(std::string Last_name, std::string First_name, std::string Patronymic);
	string get_FIO();
};

