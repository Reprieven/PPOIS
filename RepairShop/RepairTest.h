#pragma once
#include "pch.h"
#include "Repair.h"
TEST(RepairTest, GetPriceTest)
{
	std::string title = "Установка зимней резины";
	std::string description = "Установка зимней резины Michelin Pilot Sport 4 на Honda Civic ";
	int repair_price = 1083;
	std::string time = "12:35";

	std::string last_name = "Климков";
	std::string first_name = "Марат";
	std::string patronymic = "Петрович";
	int years_of_exp = 13;
	std::string speciality = "Инженер-механик";
	Mechanic mechanic1(last_name, first_name, patronymic, years_of_exp, speciality);

	std::string name = "Шины Michelin Pilot Sport 4";
	int id = 12625;
	int component_price = 200;
	int quantity = 4;
	Component component1(name, id, component_price, quantity);
	vector<Component>component_list = { component1 };
	Repair repair1(title, description, repair_price, time, mechanic1, component_list);
	EXPECT_EQ(repair_price, repair1.get_price());
}