#pragma once
#include"pch.h"
#include"Supplier.h"
TEST(SupplierTest, GetFIOTest)
{
	int phone_number = 293562532;
	std::string last_name = "Климков";
	std::string first_name = "Марат";
	std::string patronymic = "Петрович";
	std::string company = "ООО ДетальТорг";
	Supplier supplier1(last_name, first_name, patronymic, phone_number, company);
	std::string FIO = last_name + " " + first_name + " " + patronymic;
	EXPECT_EQ(FIO, supplier1.get_FIO());
};