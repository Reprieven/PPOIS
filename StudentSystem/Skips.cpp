#include "pch.h"
#include "Skips.h"

Skips::Skips() {};

Skips::Skips(Student& student, Course& course, string& month, int& skips_number)
{
	this->student = student;
	this->course = course;
	this->month = month;
	this->skips_number = skips_number;
}

Student Skips::get_student() 
{
	return student;
}

Course Skips::get_course()
{
	return course;
}

string Skips::get_month() 
{
	return month;
}

int Skips::get_skips_number() 
{
	return skips_number;
}

void Skips::set_student(Student& student) 
{
	this->student = student;
}

void Skips::set_course(Course& course) 
{
	this->course = course;
}

void Skips::set_month(string& month) 
{
	this->month = month;
}

void Skips::add_skips(int& skips_num)
{
	this->skips_number += skips_num;
}