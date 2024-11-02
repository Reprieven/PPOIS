#pragma once
class Date
{
private:
	std::string day;
	std::string month;
	std::string year;
public:
	Date();
	Date(const std::string& Day, const std::string& Month, const std::string& Year);
	std::string get_date();
};

