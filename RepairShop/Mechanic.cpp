#include "pch.h"
#include "Mechanic.h"

Mechanic::Mechanic() {};
Mechanic::Mechanic(const string& lname, const string& fname, const string& patronym, const int& experience, const string& speciality)
{
	last_name = lname;
	first_name = fname;
	patronymic = patronym;
	years_of_experience = experience;
	specialism = speciality;
}
int Mechanic::get_years_of_expirience()
{
	return years_of_experience;
}
