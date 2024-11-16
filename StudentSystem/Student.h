#pragma once
#include"Human.h"
class Student : public Human
{
private:
	int id;
	int phone_number;
public:
	Student();
	Student(string& last_name, string& first_name, string& patronymic, int& id, int& phone_number);
	int get_id();
	int get_phone_number();
	void set_id(int& id);
	void set_phone_number(int& phone_number);
};

