#include "pch.h"
#include "Library.h"

Library::Library() {};

Library::Library(vector<Book>& book_list, bool status) 
{
	this->book_list = book_list;
	this->status = status;
}

vector<Book> Library::get_book_list() 
{
	return book_list;
}

bool Library::get_status() 
{
	return status;
}

void Library::set_status(bool status)
{
	this->status = status;
}

void Library::add_book(Book& book) 
{
	book_list.push_back(book);
}

void Library::delete_book(Book& book) 
{
	auto iter = remove(book_list.begin(), book_list.end(), book);
	book_list.erase(iter, book_list.end());
}