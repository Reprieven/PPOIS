#pragma once
#include"Student.h"
using namespace std;
class Notification
{
private:
	string title;
	string content;
	Student student;
public:
	Notification();
	Notification(string& title, string& content, Student& student);
	string get_title();
	string get_content();
	Student get_student();
	void set_title(string& title);
	void set_content(string& content);
	void set_student(Student& student);
};

