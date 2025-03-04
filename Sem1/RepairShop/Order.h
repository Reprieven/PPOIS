#pragma once
#include"Car.h"
#include"Client.h"
class Order
{
private:
	int order_id;
	std::string date;
	bool status;
	Car car;
	Client client;
public:
	Order();
	Order(const int& Order_id, const string& Date, const Car& machine, const Client& customer, bool Status = false);
	bool get_order_status();
	void set_order_status(bool& new_status);
};
