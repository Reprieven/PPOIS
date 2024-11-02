#pragma once
#include"pch.h"
#include"Review.h"

TEST(ReviewTest, GetGradeTest) 
{
	int phone_number = 293562532;
	std::string last_name = "Климков";
	std::string first_name = "Марат";
	std::string patrinymic = "Петрович";
	Client client1("Климков", "Марат", "Петрович", phone_number, "ул. Козлова 28");
	int grade = 10;
	std::string comment = "Хороший сервисный центр";
	std::string date = "01.11.2024";
	Review review1(client1, grade, comment, date);
	EXPECT_EQ(grade, review1.get_grade());
}