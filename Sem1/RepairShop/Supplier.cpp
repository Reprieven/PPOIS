#include "pch.h"
#include "Supplier.h"
Supplier::Supplier(const string& Last_name, const string& First_name, const string& Patronymic,
	const int& Phone_number, const string& Company_name)
{
	last_name = Last_name;
	first_name = First_name;
	patronymic = Patronymic;
	phone_number = Phone_number;
	company_name = Company_name;
}