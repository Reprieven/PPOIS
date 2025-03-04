#include "pch.h"
#include "Schedule.h"

Schedule::Schedule() {};

Schedule::Schedule(Course& course, string& date, string& time, int& classroom_number) 
{
	this->course = course;
	this->date = date;
	this->time = time;
	this->classroom_number = classroom_number;
}

int Schedule::get_classroom_number() 
{
	return classroom_number;
}

string Schedule::get_date()
{
	return date;
}

string Schedule::get_time()
{
	return time;
}

Course Schedule::get_course() 
{
	return course;
}

void Schedule::set_classroom_number(int& classroom_number)
{
	this->classroom_number = classroom_number;
}

void Schedule::set_date(string& date)
{
	this->date = date;
}

void Schedule::set_time(string& time)
{
	this->time = time;
}

void Schedule::set_course(Course& course) 
{
	this->course = course;
}