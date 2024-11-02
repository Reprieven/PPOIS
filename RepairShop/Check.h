#pragma once
#include"Order.h"
class Check
{
private:
	int check_id;
	int amount;
	Order order;
	bool pay_status;
public:
	Check(const int& Check_id, const int& Amount, Order& Order, bool pay_status = false);
	int get_amount();
	bool get_status();
	void set_ammount(int& price);
	void set_status(bool &is_paid);
	bool operator==(const Check& other) const;
};

