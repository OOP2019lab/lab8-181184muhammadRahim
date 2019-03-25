#include<iostream>
#include<string>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& object, const Date&a);
	friend istream& operator>>(istream& object1, Date& a);
public:
	Date();
	Date(int m, int d, int y);
	bool operator==(Date&a);
	Date operator+(int a);
	const Date& operator=(const Date&a);
	int operator[](int a);
	Date operator--();
	Date operator--(int i);
	~Date();
    private:
	int day;
	int month;
	int year;
	string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

};

