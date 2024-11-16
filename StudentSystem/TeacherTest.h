#pragma once
#include"pch.h"
#include"Teacher.h"

TEST(TeacherTest, IdTest)
{
	int teacher_id = 38;
	Teacher teacher1;
	teacher1.set_id(teacher_id);
	EXPECT_EQ(teacher1.get_id(), teacher_id);
}

TEST(TeacherTest, PhoneTest)
{
	int teacher_phone = 3217465;
	Teacher teacher1;
	teacher1.set_phone_number(teacher_phone);
	EXPECT_EQ(teacher1.get_phone_number(), teacher_phone);
}

TEST(TeacherTest, PositionTest)
{
	int teacher_id = 38;
	int teacher_phone = 3217465;
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	position = "Профессор";
	teacher1.set_position(position);
	EXPECT_EQ(teacher1.get_position(), position);
}

TEST(TeacherTest, FIOTest)
{
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	Teacher teacher1;
	teacher1.set_FIO(last_name, first_name, patronymic);
	string FIO = last_name + " " + first_name + " " + patronymic;
	EXPECT_EQ(FIO, teacher1.get_FIO());
}
