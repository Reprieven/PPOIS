#pragma once
#include "pch.h"
#include "ServiceCenter.h"

TEST(ServiceCenterTest, CashboxOpperationsTest)
{
	std::string name = "Профессионал";
	std::string address = "ул. Касимовых д. 64";
	int phone_number = 294872533;
	std::string last_name = "Коханов";
	std::string first_name = "Михаил";
	std::string patronymic = "Генадьевич";
	int years_of_exp = 13;
	std::string speciality = "Инженер-механик";
	Mechanic mechanic1(last_name, first_name, patronymic, years_of_exp, speciality);
	vector<Mechanic>mechanic_list = { mechanic1 };

	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	vector<Order>order_list = { order1 };

	Check check1(112, 345, order1);
	int amount_of_money = 220;
	vector<Check> checks = { check1 };
	Cashbox cash1(amount_of_money, checks);

	ServiceCenter service_center1(name, address, phone_number, cash1, mechanic_list, order_list);

	cash1.clear_cashbox();
	cash1 = service_center1.get_cashbox();
	cash1.add_money(120);
	service_center1.set_cashbox(cash1);
	EXPECT_EQ(cash1.get_amount_of_money(), 340);

}