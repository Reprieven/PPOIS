#include "pch.h"
#include "Department.h"
Department::Department() {};

Department::Department(string& title, int& id, vector<Course>& courses_list) 
{
	this->title = title;
	this->id = id;
	this->courses_list = courses_list;
}
string Department::get_title()
{
	return title;
}

int Department::get_id() 
{
	return id;
}

vector<Course>Department::get_courses_list()
{
	return courses_list;
}

void Department::set_tilte(string& title)
{
	this->title = title;
}

void Department::set_id(int& id)
{
	this->id = id;
}

void Department::add_course(Course& course) 
{
	courses_list.push_back(course);
}

void Department::delete_course(Course& course) 
{
	auto iter = remove(courses_list.begin(), courses_list.end(), course);
	courses_list.erase(iter, courses_list.end());
}

