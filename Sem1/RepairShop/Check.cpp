#include "pch.h"
#include "Check.h"
Check::Check(const int& Check_id, const int& Amount, Order& Order, bool Is_paid)
{
	check_id = Check_id;
	amount = Amount;
	order = Order;
	pay_status = Is_paid;
};
int Check::get_amount() 
{
	return amount;
}
bool Check:: get_status()
{
	return pay_status;
}
void Check:: set_ammount(int& price) 
{
	amount = price;
}
void Check::set_status(bool&is_paid ) 
{
	pay_status = is_paid;
}

bool Check::operator==(const Check& other) const
{
	if (check_id == other.check_id) 
	{
		return true;
	}
	return false;
}