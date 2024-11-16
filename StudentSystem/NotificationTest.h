#pragma once
#include"pch.h"
#include"Notification.h"

TEST(NotificationTest, TitleTest) 
{
	string title = "Уведомление о зачислении";
	Notification notification1;
	notification1.set_title(title);
	EXPECT_EQ(notification1.get_title(), title);
}

TEST(NotificationTest, StudentTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);
	Notification notification1;
	notification1.set_student(student1);
	EXPECT_EQ(notification1.get_student().get_id(), student1.get_id());
}

TEST(NotificationTest, ContentTest)
{
	string last_name = "Климков";
	string first_name = "Марат";
	string patronymic = "Петрович";
	int student_id = 33;
	int student_phone = 293453211;
	Student student1(last_name, first_name, patronymic, student_id, student_phone);

	string title = "Уведомление о зачислении";
	string content = "Вы зачислены на курс МОИС";
	Notification notification1(title,content,student1);
	content = "Вы зачислены на курс БЖЧ";

	notification1.set_content(content);
	EXPECT_EQ(notification1.get_content(), content);

}