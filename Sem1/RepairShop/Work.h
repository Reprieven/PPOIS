#pragma once
#include<string>
class Work
{
protected:
	std::string title;
	std::string description;
	int price;
	std::string time;
public:
	Work();
	Work(const std::string& Title, const std::string& Description, const int& Price, const std::string& Time);
	int get_price();
};

