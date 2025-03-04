#include "pch.h"
#include "Order.h"

Order::Order() {};

Order::Order(const int& Order_id, const string& Date, const Car& machine, const Client& customer, bool Status)
{
	order_id = Order_id;
	date = Date;
	car = machine;
	client = customer;
	status = Status;
};
bool Order:: get_order_status()
{
	return status;
}

void Order::set_order_status(bool& new_status)
{
	status = new_status;
}
