#pragma once
#include"Check.h"
#include<vector>
class Cashbox
{
private:
	int amount_of_money;
	vector<Check> checks_list;
public:
	Cashbox(const int& Amount_of_money, std::vector<Check>& Checks_list);
	Cashbox();
	int get_amount_of_money();
	std::vector<Check> get_checks_list();
	void add_money(const int & value);
	void clear_cashbox();
	void add_check(Check&check);
	
};

