#pragma once
#include"Component.h"
#include<vector>
class Warehouse
{
private:
	std::string name;
	std::string address;
	std::vector<Component> components_list;
public:
	Warehouse(const std::string& Name, const std::string& Address, std::vector<Component>& Components_list);
	std::vector<Component> get_components_list();
	void add_components(Component&component);
};

