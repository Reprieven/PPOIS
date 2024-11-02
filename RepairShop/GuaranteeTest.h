#pragma once
#include"pch.h"
#include"Guarantee.h"
TEST(GuaranteeTest, CheckDateTest)
{

	std::string name = "Вал коленчатый Камаз";
	int component_id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1(name, component_id, price, quantity);
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "08.08.2023", car1, client1);
	int guarantee_id = 121342;
	std::string start_date = "12.08.2023";
	std::string end_date = "12.08.2025";
	Guarantee guarantee1(guarantee_id, start_date, end_date, component1, order1);
	
	Date date1("01", "11", "2024");
	EXPECT_TRUE(guarantee1.check_date(date1));

	Date date2("01", "11", "2026");
	EXPECT_FALSE(guarantee1.check_date(date2));
}