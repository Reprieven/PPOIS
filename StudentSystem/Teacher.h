#pragma once
#include"Human.h"
class Teacher : public Human
{
private:
	int id;
	int phone_number;
	string position;
public:
	Teacher();
	Teacher(string& last_name, string& first_name, string& patronymic, int& id, int& phone_number, string& position);
	int get_id();
	int get_phone_number();
	string get_position();
	void set_id(int& id);
	void set_phone_number(int& phone_number);
	void set_position(string& position);

};

