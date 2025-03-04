#pragma once
#include"pch.h"
#include"Book.h"

TEST(BookTest, EqualTest)
{
	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);
	quantity = 2;
	Book book2(book_id, title, author, quantity);
	EXPECT_TRUE(book1 == book2);
	book_id = 3332138;
	book2.set_id(book_id);
	EXPECT_FALSE(book1 == book2);
}

TEST(BookTest, GetIdTest) 
{
	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);
	EXPECT_EQ(book1.get_id(), book_id);
}

TEST(BookTest, GetQuantityTest)
{
	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);
	EXPECT_EQ(book1.get_quantity(), quantity);
}


TEST(BookTest, SetQuantityTest)
{
	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);
	quantity = 0;
	book1.set_quantity(quantity);
	EXPECT_EQ(book1.get_quantity(), 0);
}

TEST(BookTest, SetIdTest)
{
	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);
	book_id = 2164581;
	book1.set_id(book_id);
	EXPECT_EQ(book1.get_id(), 2164581);
}
