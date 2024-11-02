#pragma once
#include "pch.h"
#include "Warehouse.h"

TEST(WarehouseTest, GetComponentsListTest)
{
	std::string warehouse_name = "Склад N1";
	std::string address = "ул. Корба д. 23";

	std::string component_name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1(component_name, id, price, quantity);
	std::vector<Component>component_list = { component1 };
	Warehouse warehouse1(warehouse_name, address, component_list);
	EXPECT_EQ(component_list, warehouse1.get_components_list());
};

TEST(WarehouseTest, AddComponentTest)
{
	std::string warehouse_name = "Склад N1";
	std::string address = "ул. Корба д. 23";

	std::string component_name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1(warehouse_name, id, price, quantity);
	std::vector<Component>component_list = { component1 };
	Warehouse warehouse1(component_name, address, component_list);

	std::string name = "Вал коленчатый Белаз";
	id = 12644;
	price = 250;
	quantity = 12;
	Component component2(name, id, price, quantity);

	warehouse1.add_components(component2);
	component_list.push_back(component2);
	EXPECT_EQ(component_list, warehouse1.get_components_list());
}