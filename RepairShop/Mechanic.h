#pragma once
#include"Human.h"
class Mechanic : public Human
{
private:
	int years_of_experience;
	string specialism;
public:
	Mechanic();
	Mechanic(const string& lname, const string& fname, const string& patronym, const int& experience, const string& speciality);
	int get_years_of_expirience();
};

