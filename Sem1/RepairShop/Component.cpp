#include "pch.h"
#include "Component.h"

Component::Component() {};
Component::Component(const std::string& Name, const int& Component_id, const int& Price, const int& Quantity_in_stock)
{
	name = Name;
	component_id = Component_id;
	price = Price;
	quantity_in_stock = Quantity_in_stock;
}

int Component:: get_component_id() 
{
	return component_id;
}

int Component::get_component_price() 
{
	return price;
}

int Component::get_quantity_in_stock() 
{
	return quantity_in_stock;
}

std::string Component::get_component_name() 
{
	return name;
}

void Component::set_quantity_in_stock(int& value) 
{
	quantity_in_stock = value;
}

void Component::set_price(int& value)
{
	price = value;
}

void Component:: set_name(std::string& new_name)
{
	name = new_name;
}

void Component::set_component_id(int& new_id) 
{
	component_id = new_id;
}

bool Component::operator==(const Component& other) const
{
	if (component_id == other.component_id)
	{
		return true;
	}
	return false;
}