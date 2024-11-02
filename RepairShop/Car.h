#pragma once
#include<string>
using namespace std;
class Car
{
private:
	string brand;
	int year_of_production;
	string VIN;
	int mileage;
public:
	Car();
	Car(const string& br, const int& year, const string& id, const int& mil);
	string get_brand();
	int get_year_of_production();
	string get_VIN();
	int get_mileage();
};

