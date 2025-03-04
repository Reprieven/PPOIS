#pragma once
#include"Student.h"
#include"Course.h"
class Feedback
{
private:
	Student student;
	Course course;
	int grade;
	string content;
public:
	Feedback();
	Feedback(Student& student, Course& course, int& grade, string& content);
	Student get_student();
	Course get_course();
	int get_grade();
	string get_content();
	void set_student(Student& student);
	void set_course(Course& course);
	void set_grade(int& grade);
	void set_content(string& content);
};

