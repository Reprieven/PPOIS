#pragma once
#include "pch.h"
#include "Work.h"

TEST(WorkTest, GetPriceTest) 
{
	std::string title = "Установка зимней резины";
	std::string description = "Установка зимней резины Michelin Pilot Sport 4 на Honda Civic ";
	int price = 1083;
	std::string time = "12:35";
	Work work1(title, description, price, time);
	EXPECT_EQ(price, work1.get_price());
}