#include "pch.h"
#include "Grade.h"
 
Grade::Grade() {};
Grade::Grade(Student& student, Course& course, int& value)
{
	this->student = student;
	this->course = course;
	this->value = value;
}

int Grade::get_value() 
{
	return value;
}

Course Grade::get_course()
{
	return course;
}

Student Grade::get_student()
{
	return student;
}