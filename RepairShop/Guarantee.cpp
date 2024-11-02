#include "pch.h"
#include "Guarantee.h"
Guarantee::Guarantee(const int& Guarantee_id, const string& Start_date, const string& Finish_date, 
	Component& Component, Order& Order)
{
	guarantee_id = Guarantee_id;
	start_date = Start_date;
	finish_date = Finish_date;
	component = Component;
	order = Order;
}

bool Guarantee::check_date(Date&date) 
{
	std::string today = date.get_date();

	std::string year =today.substr(6, 4);
	std::string finish_year=finish_date.substr(6, 4);
	std::string month = today.substr(3, 2);
	std::string finish_month = finish_date.substr(3, 2);
	std::string day = today.substr(0, 2);
	std::string finish_day = finish_date.substr(0, 2);
	
	if (stoi(year) < stoi(finish_year))
	{
		return true;
	}
	if(stoi(year) == stoi(finish_year))
	{
		if (stoi(month) < stoi(finish_month))
		{
			return true;
		}
		if (stoi(month) == stoi(finish_month))
		{
			if (stoi(day) <= stoi(finish_day)) 
			{
				return true;
			}
		}
	}
	return false;
}
