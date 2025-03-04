#pragma once
#include"Client.h"
class Review
{
private:
	Client client;
	int grade;
	std::string comment;
	std::string date;
public:
	Review(Client& Client, const int& Grade, const std::string& Comment, const std::string& Date);
	int get_grade();
};

