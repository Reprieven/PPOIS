#include "pch.h"
#include "Repair.h"

Repair::Repair(const std::string& Title, const std::string& Description, const int& Price,
	const std::string& Time, Mechanic& Mechanic, std::vector<Component>& Components_list)
{
	title = Title;
	description = Description;
	price = Price;
	time = Time;
	mechanic = Mechanic;
	components_list = Components_list;
}

int Repair::get_price()
{
	return price;
}

