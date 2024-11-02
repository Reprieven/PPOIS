#include "pch.h"
#include "Review.h"
Review::Review(Client& Client, const int& Grade, const std::string& Comment, const std::string& Date)
{
	client = Client;
	grade = Grade;
	comment = Comment;
	date = Date;
}
int Review::get_grade() 
{
	return grade;
}