#pragma once
#include"pch.h"
#include"Human.h"
TEST(HumanTest, GetFIOTest)
{
	std::string last_name = "Климков";
	std::string first_name = "Марат";
	std::string patronymic = "Петрович";
	Human human1(last_name, first_name, patronymic);
	std::string FIO = last_name + " " + first_name + " " + patronymic;
	EXPECT_EQ(FIO, human1.get_FIO());
}