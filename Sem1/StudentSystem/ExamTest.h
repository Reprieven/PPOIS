#pragma once
#include"pch.h"
#include"Exam.h"

TEST(ExamTest, CourseOperationsTest)
{
	string title = "MOIS";
	int course_id = 13;

	int teacher_id = 38;
	int teacher_phone = 3217465;
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1(title, course_id, teacher1);

	Exam exam1;
	exam1.set_course(course1);
	EXPECT_EQ(exam1.get_course(), course1);
};

TEST(ExamTest, DateOperationsTest)
{
	string exam_date = "15.11.2024";

	Exam exam1;
	exam1.set_date(exam_date);
	EXPECT_EQ(exam1.get_date(), exam_date);
};

TEST(ExamTest, TimeOperationsTest)
{
	string title = "MOIS";
	int course_id = 13;

	int teacher_id = 38;
	int teacher_phone = 3217465;
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1(title, course_id, teacher1);
	string exam_date = "15.11.2024";
	string exam_time = "11:00";
	string exam_type = "Зачет";

	Exam exam1(course1, exam_date, exam_time, exam_type);

	exam_time = "9:00";
	exam1.set_time(exam_time);
	EXPECT_EQ(exam1.get_time(), exam_time);
};

TEST(ExamTest, TypeOperationsTest)
{
	string exam_type = "Зачет";
	Exam exam1;
	exam1.set_type(exam_type);
	EXPECT_EQ(exam1.get_type(), exam_type);
};

