#include"Date.h"
Date::Date()
{
	month = 1;
	day = 1;
	year = 2000;
}
Date::Date(int m, int d, int y)
{
	bool flag = false, flag1 = false;
	if (m < 13 && m>0)
	{
		month = m;
	}
	else
	{
		month = 1;
		day = 1;
		year = 2000;
		flag = true;
	}
	if (flag == false)
	{
		if (d < 31 && d>0)
		{
			day = d;
		}
		else
		{
			month = 1;
			day = 1;
			year = 2000;
			flag1 = true;
			
		}
	}
	if (flag == false && flag1 == false)
	{
		if (y > 999 && y < 10000)
		{
			year = y;
		}
		else
		{
			month = 1;
			day = 1;
			year = 2000;
		}
	}

}
ostream& operator<<(ostream& object, const Date&a)
{
	object << a.months[a.month - 1] << " " << a.day << "," << a.year<<endl;
	return object;
}
bool Date::operator==(Date&a)
{
	if (month == a.month && year == a.year && day == a.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Date Date::operator+(int a)
{
	Date temp;
	int aa, b, c;
	b= month*day;
	b = b + a;
	b = b/360;
	temp.year = b;
	c = month + a;
	c = c % 12;
	temp.month = c;
	aa = day + a;
	aa = aa % 30;
	temp.day = aa;
	return temp;
}
istream& operator>>(istream& object1, Date& a)
{
	cout << "please enter month" << endl;
	object1 >> a.month;
	cout << "please enter day" << endl;
	object1 >> a.day;
	cout << "please enter yeat" << endl;
	object1 >> a.year;
	if (a.month > 12)
	{
		cout << "wrong month input setting to default" << endl;
		a.month = 1;
	}
	if (a.day > 30)
	{
		cout << "wrong day input setting to default" << endl;
		a.day = 1;
	}
	if (a.year < 1000 || a.year>9999)
	{
		cout << "wrong year input setting to default" << endl;
		a.year = 2000;
	}
	return object1;
}
const Date& Date::operator=(const Date&a)
{
	this->day = day;
	this->month = month;
	this->year = year;
	return*this;
}
int Date::operator[](int a)
{
	if (a == 0)
	{
		return day;
	}
	if (a == 1)
	{
		return month;
	}
	if (a == 2)
	{
		return year;
	}
}
Date Date::operator--()
{
	Date temp;
	temp.day = day;
	temp.month = month;
	temp.year = year;
	temp.day = temp.day - 1;
	if (temp.day == 0)
	{
		temp.day = 30;
		temp.month = temp.month - 1;
		if (month == 0)
		{
			temp.month = 12;
			temp.year = temp.year - 1;
		}
	}
	return temp;
}
Date Date::operator--(int i)
{
	Date temp = *this;
	this->day--;
	return temp;
}
Date::~Date()
{

}