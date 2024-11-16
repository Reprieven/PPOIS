#include "pch.h"
#include "Course.h"

Course::Course() {};
Course::Course(string& title, int& id, Teacher& teacher) 
{
	this->title = title;
	this->id = id;
	this->teacher = teacher;
}

Course::Course(const Course& other) 
{
	this->title = other.title;
	this->id = other.id;
	this->teacher = other.teacher;
}

string Course::get_title()
{
	return title;
}

int Course::get_id() 
{
	return id;
}

Teacher Course::get_teacher()
{
	return teacher;
}

void Course::set_title(string& title)
{
	this->title = title;
}

void Course::set_id(int& id) 
{
	this->id = id;
}

void Course::set_teacher(Teacher& teacher) 
{
	this->teacher = teacher;
}

bool Course::operator==(const Course& other) const
{
	if (id == other.id)
	{
		return true;
	}
	return false;
}