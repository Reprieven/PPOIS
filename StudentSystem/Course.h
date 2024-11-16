#pragma once
#include"Teacher.h"
using namespace std;
class Course
{
private:
	string title;
	int id;
	Teacher teacher;
public:
	Course();
	Course(string& title, int& id, Teacher& teacher);
	Course(const Course& other);
	string get_title();
	int get_id();
	Teacher get_teacher();
	void set_title(string& tilte);
	void set_id(int& id);
	void set_teacher(Teacher& teacher);
	bool operator==(const Course& other) const;
};

