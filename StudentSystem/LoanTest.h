#pragma once
#include"pch.h"
#include"Loan.h"

TEST(LoanTest, GetStudentTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);

	int loan_id = 12728;
	string loan_date = "01.10.2024";
	Loan loan1(student1, book1, loan_id, loan_date);
	EXPECT_EQ(loan1.get_student().get_id(), student1.get_id());
}

TEST(LoanTest, GetIdTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);

	int loan_id = 12728;
	string loan_date = "01.10.2024";
	Loan loan1(student1, book1, loan_id, loan_date);
	EXPECT_EQ(loan1.get_id(), loan_id);
}

TEST(LoanTest, GetBookTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);

	int loan_id = 12728;
	string loan_date = "01.10.2024";
	Loan loan1(student1, book1, loan_id, loan_date);
	EXPECT_EQ(loan1.get_book(), book1);
}

TEST(LoanTest, GetLoanDateTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);

	int loan_id = 12728;
	string loan_date = "01.10.2024";
	Loan loan1(student1, book1, loan_id, loan_date);
	EXPECT_EQ(loan1.get_loan_date(), loan_date);
}

TEST(LoanTest, ReturnDateTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	string title = "Мартин Иден";
	string author = "Джек Лондон";
	int book_id = 2167404;
	int quantity = 4;
	Book book1(book_id, title, author, quantity);

	int loan_id = 12728;
	string loan_date = "01.10.2024";
	string return_date = "15.11.2024";
	Loan loan1(student1, book1, loan_id, loan_date);
	loan1.set_return_date(return_date);
	EXPECT_EQ(loan1.get_return_date(), return_date);
}
