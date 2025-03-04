#pragma once
#include"Student.h"
#include"Course.h"
class Enrollment
{
private:
	Student student;
	Course course;
	string date;
public:
	Enrollment();
	Enrollment(Student& student, Course& course, string& date);
	Student get_student();
	Course get_course();
	string get_date();
	void set_student(Student& student);
	void set_course(Course& course);
	void set_date(string& date);
};

