#pragma once
#include"pch.h"
#include"Enrollment.h"

TEST(EnrollmentTest, DateOpperationsTest)
{
	string date = "15.11.2024";
	Enrollment enrollment1;
	enrollment1.set_date(date);
	EXPECT_EQ(enrollment1.get_date(), date);
}

TEST(EnrollmentTest, CourseOpperationsTest)
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

	Enrollment enrolment1;
	enrolment1.set_course(course1);
	EXPECT_EQ(enrolment1.get_course(), course1);
}

TEST(EnrollmentTest, StudentOpperationsTest)
{
	string date = "15.11.2024";
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

	Enrollment enrolment1(student1,course1,date);

	student_phone = 3459123;
	student1.set_phone_number(student_phone);

	enrolment1.set_student(student1);

	EXPECT_EQ(enrolment1.get_student().get_id(), student_id);
}