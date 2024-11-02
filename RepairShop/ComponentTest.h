#pragma once
#include "pch.h"
#include "Component.h"

TEST(ComponentTest, GetIDTest)
{
	std::string name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1(name, id, price, quantity);
	EXPECT_EQ(id, component1.get_component_id());
};

TEST(ComponentTest, EqualTest) 
{
	std::string name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity= 13;
	Component component1(name, id, price, quantity);
	name = "Вал коленчатый Белаз";
	id = 12645;
	price = 250;
	quantity = 12;
	Component component2(name, id, price, quantity);
	EXPECT_TRUE(component1 == component2);
}

TEST(ComponentTest, NotEqualTest)
{
	std::string name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1(name, id, price, quantity);
	name = "Вал коленчатый Белаз";
	id = 12644;
	price = 250;
	quantity = 12;
	Component component2(name, id, price, quantity);
	EXPECT_FALSE(component1 == component2);
}

TEST(ComponentTest, GetPriceTest)
{
	std::string name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1(name, id, price, quantity);
	EXPECT_EQ(price, component1.get_component_price());
};

TEST(ComponentTest, GetQuantityTest)
{
	std::string name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1(name, id, price, quantity);
	EXPECT_EQ(quantity, component1.get_quantity_in_stock());
};

TEST(ComponentTest, SetTest)
{
	std::string name = "Вал коленчатый Камаз";
	int id = 12645;
	int price = 200;
	int quantity = 13;
	Component component1;
	component1.set_name(name);
	component1.set_component_id(id);
	component1.set_price(price);
	component1.set_quantity_in_stock(quantity);
	EXPECT_EQ(name, component1.get_component_name());
	EXPECT_EQ(id, component1.get_component_id());
	EXPECT_EQ(price, component1.get_component_price());
	EXPECT_EQ(quantity, component1.get_quantity_in_stock());
};