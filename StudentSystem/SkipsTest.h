#pragma once
#include"pch.h"
#include"Skips.h"

TEST(SkipsTest, StudentTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	Skips skip_stat;
	skip_stat.set_student(student1);
	EXPECT_EQ(skip_stat.get_student().get_id(), student1.get_id());
}

TEST(SkipsTest, CourseTest)
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

	Skips skip_stat;
	skip_stat.set_course(course1);
	EXPECT_EQ(skip_stat.get_course(), course1);
}

TEST(SkipsTest, MonthTest)
{
	string month = "Ноябрь";

	Skips skip_stat;
	skip_stat.set_month(month);
	EXPECT_EQ(skip_stat.get_month(), month);
}

TEST(SkipsTest, GetSkipsNumTest)
{
	int skips_num = 3;
	string month = "Ноябрь";

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

	Skips skip_stat(student1, course1, month, skips_num);

	EXPECT_EQ(skips_num, skip_stat.get_skips_number());
}

TEST(SkipsTest, AddSkipsTest)
{
	int skips_num = 4;
	Skips skip_stat;
	skip_stat.add_skips(skips_num);
	EXPECT_EQ(skips_num, skip_stat.get_skips_number());
}

