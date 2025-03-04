#pragma once
#include"Book.h"
class Library
{
private:
	vector<Book> book_list;
	bool status;
public:
	Library();
	Library(vector<Book>& book_list, bool status = false);
	vector<Book> get_book_list();
	bool get_status();
	void set_status(bool status);
	void add_book(Book& book);
	void delete_book(Book& book);
};

