#pragma once
#include"pch.h"
#include"Department.h"

TEST(DepartmentTest, TitleOperationsTest)
{
	string department_title = "IIT";

	Department department1;
	department1.set_tilte(department_title);
	EXPECT_EQ(department_title, department1.get_title());
}

TEST(DepartmentTest, IdOperationsTest)
{
	int department_id = 17;
	Department department1;
	department1.set_id(department_id);
	EXPECT_EQ(department_id, department1.get_id());
};

TEST(DepartmentTest, CourseAddTest)
{
	string department_title = "IIT";
	int department_id = 17;

	string course_title = "MOIS";
	int course_id = 13;

	int teacher_id = 38;
	int teacher_phone = 3217465;
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);

	Course course1(course_title, course_id, teacher1);
	course_title = "SNI";
	course_id = 14;
	Course course2(course_title, course_id, teacher1);

	vector<Course>course_list = { course1 };
	
	Department department1(department_title, department_id, course_list);
	department1.add_course(course2);
	course_list.push_back(course2);
	
	EXPECT_EQ(department1.get_courses_list(), course_list);
}

TEST(DepartmentTest, CourseDeleteTest)
{
	string department_title = "IIT";
	int department_id = 17;

	string course_title = "MOIS";
	int course_id = 13;

	int teacher_id = 38;
	int teacher_phone = 3217465;
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);

	Course course1(course_title, course_id, teacher1);
	course_title = "SNI";
	course_id = 14;
	Course course2(course_title, course_id, teacher1);

	vector<Course>course_list = { course1 };

	Department department1(department_title, department_id, course_list);
	department1.add_course(course2);
	department1.delete_course(course2);
	EXPECT_EQ(course_list, department1.get_courses_list());
}