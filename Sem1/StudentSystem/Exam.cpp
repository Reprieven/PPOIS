#include "pch.h"
#include "Exam.h"
Exam::Exam() {};

Exam::Exam(Course& course, string& date, string& time, string& type)
{
	this->course = course;
	this->date = date;
	this->time = time;
	this->type = type;
}

string Exam::get_type()
{
	return type;
}

string Exam::get_date()
{
	return date;
}

string Exam::get_time()
{
	return time;
}

Course Exam::get_course()
{
	return course;
}

void Exam::set_type(string& type)
{
	this->type = type;
}

void Exam::set_date(string& date)
{
	this->date = date;
}

void Exam::set_time(string& time)
{
	this->time = time;
}

void Exam::set_course(Course& course)
{
	this->course = course;
}