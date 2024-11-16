#include "pch.h"
#include "Loan.h"

Loan::Loan() {};

Loan::Loan(Student& student, Book& book, int& id, string& loan_date, string return_date) 
{
	this->student = student;
	this->book = book;
	this->id = id;
	this->loan_date = loan_date;
	this->return_date = return_date;
}

int Loan::get_id()
{
	return id;
}

Student Loan::get_student()
{
	return student;
}

Book Loan::get_book()
{
	return book;
}

string Loan::get_loan_date() 
{
	return loan_date;
}

string Loan::get_return_date()
{
	return return_date;
}

void Loan::set_return_date(string& return_date) 
{
	this->return_date = return_date;
}