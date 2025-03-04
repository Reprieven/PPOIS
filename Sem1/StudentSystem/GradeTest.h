#pragma once
#include"pch.h"
#include"Grade.h"

TEST(GradeTest, GetStudentTest) 
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);


	string title = "MOIS";
	int course_id = 13;
	int teacher_id = 38;
	int teacher_phone = 3217465;
	last_name = "Иванов";
	first_name = "Иван";
	patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1(title, course_id, teacher1);

	int value = 9;

	Grade grade1(student1, course1, value);

	EXPECT_EQ(grade1.get_student().get_id(), student1.get_id());
}

TEST(GradeTest, GetCourseTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);


	string title = "MOIS";
	int course_id = 13;
	int teacher_id = 38;
	int teacher_phone = 3217465;
	last_name = "Иванов";
	first_name = "Иван";
	patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1(title, course_id, teacher1);

	int value = 9;

	Grade grade1(student1, course1, value);

	EXPECT_EQ(grade1.get_course(), course1);
}

TEST(GradeTest, GetValueTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);


	string title = "MOIS";
	int course_id = 13;
	int teacher_id = 38;
	int teacher_phone = 3217465;
	last_name = "Иванов";
	first_name = "Иван";
	patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1(title, course_id, teacher1);

	int value = 9;

	Grade grade1(student1, course1, value);

	EXPECT_EQ(grade1.get_value(), value);
}