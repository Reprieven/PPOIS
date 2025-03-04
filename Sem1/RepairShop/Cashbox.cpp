#include "pch.h"
#include "CashBox.h"

Cashbox::Cashbox(const int& Amount_of_money, std::vector<Check>& Checks_list)
{
	amount_of_money = Amount_of_money;
	checks_list = Checks_list;
};

Cashbox::Cashbox() {};
int Cashbox::get_amount_of_money()
{
	return amount_of_money;
}

std::vector<Check> Cashbox::get_checks_list()
{
	return checks_list;
}

void Cashbox:: add_money(const int&value) 
{
	amount_of_money += value;
}

void Cashbox::clear_cashbox()
{
	amount_of_money = 0;
}

void Cashbox::add_check(Check&check) 
{
	checks_list.push_back(check);
}