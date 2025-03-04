#include "pch.h"
#include "Client.h"

Client::Client(const string& Last_name, const string& First_name, const string& Patronymic, const int& Phone_number, const string& Address)
{
	last_name = Last_name;
	first_name = First_name;
	patronymic = Patronymic;
	phone_number = Phone_number;
	address = Address;
};
Client::Client() {};

int Client::get_number()
{
	return phone_number;
}

string Client::get_address() 
{
	return address;
}
