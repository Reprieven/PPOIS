#pragma once
#include"pch.h"
#include"Library.h"

TEST(LibraryTest, StatusTest) 
{
	bool status = true;
	Library library1;
	library1.set_status(status);
	EXPECT_TRUE(library1.get_status());
}

TEST(LibraryTest, AddBookTest)
{
	bool status = true;
	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);
	vector<Book> book_list = {};
	Library library1(book_list,status);
	library1.add_book(book1);
	book_list.push_back(book1);
	
	EXPECT_EQ(book_list, library1.get_book_list());
}

TEST(LibraryTest, DeleteBookTest)
{
	bool status = true;
	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);

	title = "Изучаем Python";
	author = "Эрик Мэтиз";
	book_id = 563738;
	quantity = 1;
	Book book2(book_id, title, author, quantity);

	vector<Book> book_list = {};
	Library library1(book_list, status);
	library1.add_book(book1);
	library1.add_book(book2);
	library1.delete_book(book2);

	book_list.push_back(book1);

	EXPECT_EQ(book_list, library1.get_book_list());
}