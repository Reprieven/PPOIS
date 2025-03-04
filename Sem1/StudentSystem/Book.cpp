#include "pch.h"
#include "Book.h"
Book::Book() {};

Book::Book(int& id, string& title, string& author, int& quantity)
{
	this->id = id;
	this->title = title;
	this->author = author;
	this->quantity = quantity;
}

int Book::get_id()
{
	return id;
}

int Book::get_quantity() 
{
	return quantity;
}

void Book::set_quantity(int& quantity) 
{
	this->quantity = quantity;
}

void Book::set_id(int& id)
{
	this->id = id;
}

bool Book::operator==(const Book& other) const
{
	if (id == other.id)
	{
		return true;
	}
	return false;
}
