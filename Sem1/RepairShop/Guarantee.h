#pragma once
#include"Component.h"
#include"Order.h"
#include"Date.h"
#include<string>
class Guarantee
{
private:
	int guarantee_id;
	std::string start_date;
	std::string finish_date;
	Component component;
	Order order;
public:
	Guarantee(const int& Guarantee_id, const string& Start_date, const string& Finish_date, Component& component, Order& order);
	bool check_date(Date&date);
};

