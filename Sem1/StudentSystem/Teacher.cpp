#include "pch.h"
#include "Teacher.h"
Teacher::Teacher() {};
Teacher::Teacher(string& last_name, string& first_name, string& patronymic, int& id, int& phone_number, string& position) 
{
	this->last_name = last_name;
	this->first_name = first_name;
	this->patronymic = patronymic;
	this->id = id;
	this->phone_number = phone_number;
	this->position = position;
}
int Teacher::get_id()
{
	return id;
}

int Teacher::get_phone_number() 
{
	return phone_number;
}

string Teacher::get_position()
{
	return position;
}

void Teacher::set_id(int& id)
{
	this->id = id;
}

void Teacher::set_phone_number(int& phone_number)
{
	this->phone_number = phone_number;
}

void Teacher::set_position(string& position)
{
	this->position = position;
}
