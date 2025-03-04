#pragma once
using namespace std;
class Book
{
private:
	string title;
	string author;
	int id;
	int quantity;
public:
	Book();
	Book(int& id, string& title, string& author, int& quantity);
	int get_id();
	int get_quantity();
	void set_quantity(int& quantity);
	void set_id(int& id);
	bool operator==(const Book& other) const;
};

