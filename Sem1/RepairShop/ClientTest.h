#pragma once
#include "pch.h"
#include "Client.h"
TEST(ClientTest, GetNumberTest)
{
	int phone_number = 293562532;
	std::string last_name = "Климков";
	std::string first_name = "Марат";
	std::string patrinymic = "Петрович";
	Client client1("Климков", "Марат", "Петрович", phone_number, "ул. Козлова 28");
	EXPECT_EQ(phone_number, client1.get_number());
};

TEST(ClientTest, GetFIOTest)
{
	int phone_number = 293562532;
	std::string last_name = "Климков";
	std::string first_name = "Марат";
	std::string patronymic = "Петрович";
	Client client1(last_name, first_name, patronymic, phone_number, "ул. Козлова 28");
	std::string FIO = last_name + " " + first_name + " " + patronymic;
	EXPECT_EQ(FIO, client1.get_FIO());
};

TEST(ClientTest, GetAddressTest) 
{
	std::string address = "ул.Козлова 28";
	Client client1("Климков", "Марат", "Петрович", 293562532,address);
	EXPECT_EQ(address, client1.get_address());
}