#pragma once
using namespace std;
class Human
{
	protected:
		string last_name;
		string first_name;
		string patronymic;
	public:
		Human();
		Human(string& last_name, string& first_name, string& patronymic);
		string get_FIO(); 
		void set_FIO(string& last_name, string& first_name, string& patronymic);
};

