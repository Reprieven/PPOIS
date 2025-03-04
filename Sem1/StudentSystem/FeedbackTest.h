#pragma once
#include"pch.h"
#include"Feedback.h"

TEST(FeedbackTest, StudentOperationsTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);
	Feedback review1;
	review1.set_student(student1);

	EXPECT_EQ(student1.get_id(), review1.get_student().get_id());
};

TEST(FeedbackTest, CourseOperationsTest)
{
	string title = "MOIS";
	int course_id = 13;

	int teacher_id = 38;
	int teacher_phone = 3217465;
	string last_name = "Иванов";
	string first_name = "Иван";
	string patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1(title, course_id, teacher1);

	Feedback review1;
	review1.set_course(course1);

	EXPECT_EQ(course1, review1.get_course());
};


TEST(FeedbackTest, GradeOperationsTest)
{
	int grade = 10;
	Feedback review1;
	review1.set_grade(grade);

	EXPECT_EQ(grade, review1.get_grade());
};

TEST(FeedbackTest, ContentOperationsTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);


	string title = "MOIS";
	int course_id = 13;
	int teacher_id = 38;
	int teacher_phone = 3217465;
	last_name = "Иванов";
	first_name = "Иван";
	patronymic = "Иванович";
	string position = "Доктор технических наук";
	Teacher teacher1(last_name, first_name, patronymic, teacher_id, teacher_phone, position);
	Course course1(title, course_id, teacher1);
	
	string review_content = "Очень понравились лекции по курсу МОИС";
	int course_grade = 10;

	Feedback review1(student1,course1,course_grade,review_content);
	review_content = "Очень понравились лекции и лабораторные работы по курсу МОИС";
	review1.set_content(review_content);

	EXPECT_EQ(review_content, review1.get_content());
};


