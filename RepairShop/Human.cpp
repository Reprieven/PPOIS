#include "pch.h"
#include "Human.h"
Human::Human() {};
Human::Human(std::string Last_name, std::string First_name, std::string Patronymic) 
{
	last_name = Last_name;
	first_name = First_name;
	patronymic = Patronymic;
}
string Human::get_FIO() 
{
	return last_name + " " + first_name + " " + patronymic;
}