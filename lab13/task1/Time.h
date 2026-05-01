#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int min;
	int sec;

	void normalize();

public:
	Time();
	Time(int m, int s);
	Time(const Time& t);
	~Time();

	int getMin() const;
	int getSec() const;

	void setMin(int m);
	void setSec(int s);

	Time& operator=(const Time& t);

	Time operator+(const Time& t) const;
	Time operator/(const int& n) const;

	bool operator<(const Time& t) const;
	bool operator>(const Time& t) const;
	bool operator==(const Time& t) const;
	bool operator!=(const Time& t) const;

	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};