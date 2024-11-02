#pragma once
#include "pch.h"
#include"Cashbox.h"

TEST(CashboxTest, AddMoneyTest)
{
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	Check check1(112, 345, order1);
	int amount_of_money = 0;
	vector<Check> checks = { check1 };
	Cashbox cash1(amount_of_money, checks);
	int payment = 325;
	cash1.add_money(payment);
	EXPECT_EQ(payment, cash1.get_amount_of_money());
};

TEST(CashboxTest, ClearCashboxTest)
{
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	Check check1(112, 345, order1);
	int amount_of_money = 120;
	vector<Check> checks = { check1 };
	Cashbox cash1(amount_of_money, checks);
	cash1.clear_cashbox();
	EXPECT_EQ(0, cash1.get_amount_of_money());
};

TEST(CashboxTest, ChecksOperationsTest)
{
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	Check check1(112, 345, order1);
	int amount_of_money = 120;
	vector<Check> checks = {};
	Cashbox cash1(amount_of_money, checks);
	cash1.add_check(check1);
	vector<Check>test_checks = { check1 };
	EXPECT_EQ(test_checks, cash1.get_checks_list());
};