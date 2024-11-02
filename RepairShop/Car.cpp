#include "pch.h"
#include "Car.h"

Car::Car(const string& br, const int& year, const string& id,const int& mil) 
{
	brand = br;
	year_of_production = year;
	VIN = id;
	mileage = mil;
};
Car::Car() {};
string Car::get_brand() 
{
	return brand;
}

int Car::get_year_of_production() 
{
	return year_of_production;
}

string Car:: get_VIN() 
{
	return VIN;
}

int Car::get_mileage() 
{
	return mileage;
}