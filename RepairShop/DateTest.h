#pragma once
#include "pch.h"
#include"Date.h"
TEST(DateTest, GetDate) 
{
	std::string day = "1";
	std::string month = "11";
	std::string year = "2024";
	Date date(day, month, year);
	EXPECT_EQ("1.11.2024", date.get_date());
}