#pragma once
class Component
{
private:
	std::string name;
	int component_id;
	int price;
	int quantity_in_stock;
public:
	Component();
	Component(const std::string& Name, const int& Component_id, const int& Price, const int& Quantity_in_stock);
	int get_component_id();
	int get_component_price();
	int get_quantity_in_stock();
	std::string get_component_name();
	void set_quantity_in_stock(int&value);
	void set_price(int& vaklue);
	void set_name(std::string& new_name);
	void set_component_id(int& new_id);
	bool operator==(const Component& other) const;
};

