#pragma once
#include"Course.h"
class Exam
{
private:
	Course course;
	string time;
	string date;
	string type;
public:
	Exam();
	Exam(Course& course, string& date, string& time, string& type);
	string get_type();
	string get_date();
	string get_time();
	Course get_course();
	void set_type(string& type);
	void set_date(string& date);
	void set_time(string& time);
	void set_course(Course& course);
};

