#pragma once
#include "pch.h"
#include "Order.h"

TEST(OrderTest, StatusTest)
{
	Client client1("Климков", "Марат", "Петрович", 293562532, "ул. Козлова 28");
	Car car1("Audi", 2020, "X7MXKN7FP6M004128", 10000);
	Order order1(123, "12.10.2024", car1, client1);
	EXPECT_FALSE(order1.get_order_status());
	bool new_status = true;
	order1.set_order_status(new_status);
	EXPECT_TRUE(order1.get_order_status());
}