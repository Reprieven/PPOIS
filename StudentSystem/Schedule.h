#pragma once
#include"Course.h"
class Schedule
{
private:
	Course course;
	string date;
	string time;
	int classroom_number;
public:
	Schedule();
	Schedule(Course& course, string& date, string& time, int& classroom_number);
	int get_classroom_number();
	string get_date();
	string get_time();
	Course get_course();
	void set_classroom_number(int& classroom_number);
	void set_date(string& date);
	void set_time(string& time);
	void set_course(Course& course);
};

