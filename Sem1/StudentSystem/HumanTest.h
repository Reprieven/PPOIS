#pragma once
#include"pch.h"
#include"Human.h"

TEST(HumanTest, GetFIOTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	Human human1(last_name, first_name, patronymic);
	string FIO = last_name + " " + first_name + " " + patronymic;
	EXPECT_EQ(FIO, human1.get_FIO());
}

TEST(HumanTest, SetFIOTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	Human human1;
	human1.set_FIO(last_name, first_name, patronymic);
	string FIO = last_name + " " + first_name + " " + patronymic;
	EXPECT_EQ(FIO, human1.get_FIO());
}