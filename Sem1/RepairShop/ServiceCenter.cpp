#include "pch.h"
#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(const std::string& Name, const std::string& Address, const int& Phone_number, 
	Cashbox& Cashbox,vector<Mechanic>& Mechanics_list, vector<Order>& Orders_list)
{
	name = Name;
	address = Address;
	phone_number = Phone_number;
	mechanics_list = Mechanics_list;
	cashbox = Cashbox;
	orders_list = Orders_list;
};

Cashbox ServiceCenter::get_cashbox() 
{
	return cashbox;
}

void ServiceCenter::set_cashbox(Cashbox&new_cashbox) 
{
	cashbox = new_cashbox;
}
