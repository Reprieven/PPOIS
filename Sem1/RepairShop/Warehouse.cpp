#include "pch.h"
#include "Warehouse.h"


Warehouse::Warehouse(const std::string& Name, const std::string& Address, std::vector<Component>& Components_list)
{
	name = Name;
	address = Address;
	components_list = Components_list;
}

std::vector<Component> Warehouse::get_components_list()
{
	return components_list;
}

void Warehouse:: add_components(Component& component)
{
	components_list.push_back(component);
}


