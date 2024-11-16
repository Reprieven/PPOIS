#include "pch.h"
#include "Notification.h"

Notification::Notification() {};

Notification::Notification(string& title, string& content, Student& student) 
{
	this->title = title;
	this->content = content;
	this->student = student;
}

string Notification::get_title() 
{
	return title;
}

string Notification::get_content() 
{
	return content;
}

Student Notification::get_student()
{
	return student;
}

void Notification::set_title(string& title) 
{
	this->title = title;
}

void Notification::set_content(string& content) 
{
	this->content = content;
}

void Notification::set_student(Student& student) 
{
	this->student = student;
}