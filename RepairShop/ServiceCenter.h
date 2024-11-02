#pragma once
#include"Mechanic.h"
#include"Order.h"
#include"Cashbox.h"
#include<vector>
class ServiceCenter
{
private:
	std::string name;
	std::string address;
	int phone_number;
	std::vector<Mechanic> mechanics_list;
	std::vector<Order> orders_list;
	Cashbox cashbox;
public:
	ServiceCenter(const std::string& Name, const std::string& Address, const int& Phone_number,
		Cashbox& Cashbox, vector<Mechanic>& Mechanics_list, vector<Order>& Orders_list);
	Cashbox get_cashbox();
	void set_cashbox(Cashbox&new_cashbox);

};

