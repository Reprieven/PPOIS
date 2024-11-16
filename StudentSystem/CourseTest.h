#pragma once
#include"pch.h"
#include"Course.h"

TEST(CourseTest, GetTitleTest)
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

	EXPECT_EQ(title, course1.get_title());
}

TEST(CourseTest, GetIdTest)
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

	EXPECT_EQ(course_id, course1.get_id());
}

TEST(CourseTest, GetTeacherTest)
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

	EXPECT_EQ(teacher_id, course1.get_teacher().get_id());
}

TEST(CourseTest, SetIdTest)
{
	int course_id = 13;
	Course course1;
	course1.set_id(course_id);

	EXPECT_EQ(course_id, course1.get_id());
}

TEST(CourseTest, SetTitleTest)
{
	string title = "MOIS";
	Course course1;
	course1.set_title(title);

	EXPECT_EQ(title, course1.get_title());
}

TEST(CourseTest, SetTeacherTest)
{
	int teacher_id = 38;
	int teacher_phone = 3217465;
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1;

	course1.set_teacher(teacher1);

	EXPECT_EQ(teacher_id, course1.get_teacher().get_id());
}

TEST(CourseTest, EqualTest)
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
	
	title = "SNI";
	course_id = 14;
	Course course2(title, course_id, teacher1);

	Course course3(course1);

	EXPECT_TRUE(course1 == course3);
	EXPECT_FALSE(course1 == course2);
}

