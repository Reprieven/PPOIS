#include "pch.h"
#include "Work.h"

Work::Work(const std::string& Title, const std::string& Description, const int& Price, const std::string& Time)
{
	title = Title;
	description = Description;
	price = Price;
	time = Time;
};

Work::Work() {};

int Work::get_price() 
{
	return price;
}