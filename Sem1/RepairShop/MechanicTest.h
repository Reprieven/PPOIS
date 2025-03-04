#pragma once
#include"pch.h"
#include"Mechanic.h"
TEST(MechanicTest, GetTest) 
{
	std::string last_name = "Климков";
	std::string first_name = "Марат";
	std::string patronymic = "Петрович";
	std::string FIO = last_name + " " + first_name + " " + patronymic;
	int years_of_exp = 13;
	std::string speciality = "Инженер-механик";
	Mechanic mechanic1(last_name, first_name, patronymic,years_of_exp,speciality);
	EXPECT_EQ(mechanic1.get_years_of_expirience(), years_of_exp);
	EXPECT_EQ(FIO, mechanic1.get_FIO());
}