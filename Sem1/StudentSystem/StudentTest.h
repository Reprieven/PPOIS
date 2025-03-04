#pragma once
#include"pch.h"
#include"Student.h"

TEST(StudentTest, IdTest)
{
	int student_id = 33;
	Student student1;
	student1.set_id(student_id);
	EXPECT_EQ(student1.get_id(), student_id);
}

TEST(StudentTest, PhoneTest)
{
	int student_phone = 293453211;
	Student student1;
	student1.set_phone_number(student_phone);
	EXPECT_EQ(student1.get_phone_number(), student_phone);
}

TEST(StudentTest, FIOTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	last_name = "Иванов";
	first_name = "Иван";
	patronymic = "Иванович";

	student1.set_FIO(last_name, first_name, patronymic);
	string FIO = last_name + " " + first_name + " " + patronymic;
	EXPECT_EQ(FIO, student1.get_FIO());
}