#include "pch.h"
#include "Feedback.h"

Feedback::Feedback() {};

Feedback::Feedback(Student& student, Course& course, int& grade, string& content) 
{
	this->student = student;
	this->course = course;
	this->content = content;
	this->grade = grade;
}

Student Feedback::get_student() 
{
	return student;
}

Course Feedback::get_course() 
{
	return course;
}

int Feedback::get_grade() 
{
	return grade;
}

string Feedback::get_content()
{
	return content;
}

void Feedback::set_student(Student& student) 
{
	this->student = student;
}

void Feedback::set_course(Course& course) 
{
	this->course = course;
}

void Feedback::set_grade(int& grade)
{
	this->grade = grade;
}
void Feedback::set_content(string& content)
{
	this->content = content;
}