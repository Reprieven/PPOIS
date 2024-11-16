#pragma once
#include"Course.h"
using namespace std;
class Department
{
private:
	string title;
	int id;
	vector<Course> courses_list;
public:

	Department();
	Department(string& title, int& id, vector<Course>& courses_list);
	string get_title();
	int get_id();
	vector<Course> get_courses_list();
	void set_tilte(string& title);
	void set_id(int& id);
	void add_course(Course& course);
	void delete_course(Course& course);

};

