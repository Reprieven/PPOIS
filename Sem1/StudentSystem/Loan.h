#pragma once
#include"Student.h"
#include"Book.h"
class Loan
{
private:
	Student student;
	Book book;
	int id;
	string loan_date;
	string return_date;
public:
	Loan();
	Loan(Student& student, Book& book, int& id, string& loan_date, string return_date = "Книга не была возвращена");
	int get_id();
	Student get_student();
	Book get_book();
	string get_loan_date();
	string get_return_date();
	void set_return_date(string& return_date);

};

