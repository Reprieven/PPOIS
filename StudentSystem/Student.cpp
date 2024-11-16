#include "pch.h"
#include "Student.h"

Student::Student() {};
Student::Student(string& last_name, string& first_name, string& patronymic, int& id, int& phone_number)
{
	this->last_name = last_name;
	this->first_name = first_name;
	this->patronymic = patronymic;
	this->id = id;
	this->phone_number = phone_number;
}

int Student:: get_id() 
{
	return id;
}

int Student:: get_phone_number() 
{
	return phone_number;
}

void Student::set_id(int& id) 
{
	this->id = id;
}

void Student::set_phone_number(int& phone_number) 
{
	this->phone_number = phone_number;
}

