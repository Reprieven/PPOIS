#pragma once
#include"Student.h"
#include"Course.h"
class Skips
{
private:
	Student student;
	Course course;
	string month;
	int skips_number = 0;
public:
	Skips();
	Skips(Student& student, Course& course, string& month, int& skips_number);
	Student get_student();
	Course get_course();
	string get_month();
	int get_skips_number();
	void set_student(Student& student);
	void set_course(Course& course);
	void set_month(string& month);
	void add_skips(int& skips_num);
};

