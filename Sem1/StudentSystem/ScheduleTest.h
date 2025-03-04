#pragma once
#include"pch.h"
#include"Schedule.h"

TEST(ScheduleTest, ClassroomNumTest)
{
	int classroom_num = 612;
	Schedule lesson;
	lesson.set_classroom_number(classroom_num);
	EXPECT_EQ(classroom_num, lesson.get_classroom_number());
}

TEST(ScheduleTest, DateTest) 
{
	string date = "15.11.2024";
	Schedule lesson;
	lesson.set_date(date);
	EXPECT_EQ(lesson.get_date(), date);
}

TEST(ScheduleTest, CourseTest)
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
	Schedule lesson;
	lesson.set_course(course1);
	EXPECT_EQ(lesson.get_course(), course1);
}
TEST(ScheduleTest, TimeTest) 
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
	
	string date = "15.11.2024";
	int classroom_num = 612;
	string time = "10:35";
	Schedule lesson(course1, date, time, classroom_num);
	time = "9:00";
	lesson.set_time(time);
	EXPECT_EQ(lesson.get_time(), time);
}