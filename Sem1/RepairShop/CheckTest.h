#pragma once
#include "pch.h"
#include "Check.h"
TEST(CheckTest, AmountOperationsTest)
{
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	Check check1(112, 345, order1);
	EXPECT_EQ(345, check1.get_amount());
	int new_amount = 200;
	check1.set_ammount(new_amount);
	EXPECT_EQ(new_amount, check1.get_amount());
};

TEST(CheckTest, StatusOperationsTest)
{
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	Check check1(112, 345, order1);
	EXPECT_FALSE(check1.get_status());
	bool new_status = true;
	check1.set_status(new_status);
	EXPECT_TRUE(check1.get_status());
};

TEST(CheckTest, EqualTest)
{
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	Check check1(112, 345, order1);
	Check check2(113, 29, order1);
	EXPECT_FALSE(check1 == check2);
};
