#pragma once
#include"Human.h"
class Supplier:public Human
{
private:
	std::string company_name;
	int phone_number;
public:
	Supplier(const string& Last_name, const string& First_name, const string& Patronymic, 
		const int& Phone_number, const string& Company_name);
};

