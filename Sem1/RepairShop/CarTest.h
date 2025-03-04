#pragma once
#include"Car.h"
#include "pch.h"
TEST(CarTest, GetBrandTest)
{
	std::string brand = "Audi";
	int year = 2020;
	std::string VIN = "X7MXKN7FP6M004128";
	int mileage = 10000;
	Car car(brand, year, VIN, mileage);
	EXPECT_EQ(car.get_brand(), brand);
};

TEST(CarTest, GetYearTest)
{
	std::string brand = "Audi";
	int year = 2020;
	std::string VIN = "X7MXKN7FP6M004128";
	int mileage = 10000;
	Car car(brand, year, VIN, mileage);
	EXPECT_EQ(car.get_year_of_production(), year);
};

TEST(CarTest, GetVINTest)
{
	std::string brand = "Audi";
	int year = 2020;
	std::string VIN = "X7MXKN7FP6M004128";
	int mileage = 10000;
	Car car(brand, year, VIN, mileage);
	EXPECT_EQ(car.get_VIN(), VIN);
};

TEST(CarTest, GetMiliageTest)
{
	std::string brand = "Audi";
	int year = 2020;
	std::string VIN = "X7MXKN7FP6M004128";
	int mileage = 10000;
	Car car(brand, year, VIN, mileage);
	EXPECT_EQ(car.get_mileage(), mileage);
}
