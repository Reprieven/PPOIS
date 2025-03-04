#pragma once
#include"Component.h"
#include"Mechanic.h"
#include"Work.h"
#include<vector>
class Repair:public Work
{
private:
	Mechanic mechanic;
	vector<Component> components_list;
public:
	Repair(const std::string& Title, const std::string& Description, const int& Price,
		const std::string& Time, Mechanic& Mechanic, std::vector<Component>&Components_list);
	int get_price();
};

