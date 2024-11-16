#include "pch.h"
#include "Enrollment.h"

Enrollment::Enrollment() {};

Enrollment::Enrollment(Student& student, Course& course, string& date)
{
	this->student = student;
	this->course = course;
	this->date = date;
}

Student Enrollment::get_student()
{
	return student;
}

Course Enrollment::get_course() 
{
	return course;
}

string Enrollment::get_date() 
{
	return date;
}

void Enrollment::set_student(Student& student) 
{
	this->student = student;
}

void Enrollment::set_course(Course& course)
{
	this->course = course;
}

void Enrollment::set_date(string& date) 
{
	this->date = date;
}
