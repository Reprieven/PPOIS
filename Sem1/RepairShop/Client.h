#pragma once
#include"Human.h"
class Client:public Human
{
private:
	int phone_number;
	std::string address;
public:
	Client();
	Client(const string& Last_name, const string& First_name, const string& Patronymic, const int& Phone_number, const string& Address);
	int get_number();
	string get_address();
};

