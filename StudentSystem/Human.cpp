#include "pch.h"
#include "Human.h"

Human::Human() {};
Human::Human(string& last_name, string& first_name, string& patronymic)
{
	this->last_name = last_name;
	this->first_name = first_name;
	this->patronymic = patronymic;
}
string Human::get_FIO()
{
	return last_name + " " + first_name + " " + patronymic;
}

void Human::set_FIO(string& last_name,string& first_name,string& patronymic)
{
	this->last_name = last_name;
	this->first_name = first_name;
	this->patronymic = patronymic;
}
