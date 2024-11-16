#pragma once
#include"Student.h"
#include"Course.h"
class Grade
{
private:
	int value;
	Student student;
	Course course;
public:
	Grade();
	Grade(Student& student, Course& course, int& value);
	int get_value();
	Course get_course();
	Student get_student();
};

