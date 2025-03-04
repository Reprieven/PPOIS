#include "pch.h"
#include "Date.h"
Date::Date(const std::string& Day, const std::string& Month, const std::string& Year)
{
	day = Day;
	month = Month;
	year = Year;
}

Date::Date() {};
std::string Date::get_date() 
{
	return day + "." + month + "." + year;
}