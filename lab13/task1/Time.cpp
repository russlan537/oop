#include "Time.h"

Time::Time()
{
    min = 0;
    sec = 0;
}

Time::Time(int m, int s)
{
    min = m;
    sec = s;
    normalize();
}

Time::Time(const Time& t)
{
    min = t.min;
    sec = t.sec;
}

Time::~Time() {}

void Time::normalize()
{
    if (sec >= 60)
    {
        min += sec / 60;
        sec %= 60;
    }

    if (sec < 0)
    {
        int total = min * 60 + sec;
        if (total < 0)
        {
            min = 0;
            sec = 0;
        }
        else
        {
            min = total / 60;
            sec = total % 60;
        }
    }

    if (min < 0)
    {
        min = 0;
        sec = 0;
    }
}

int Time::getMin() const
{
    return min;
}

int Time::getSec() const
{
    return sec;
}

void Time::setMin(int m)
{
    min = m;
    normalize();
}

void Time::setSec(int s)
{
    sec = s;
    normalize();
}

Time& Time::operator=(const Time& t)
{
    if (this == &t)
        return *this;

    min = t.min;
    sec = t.sec;
    return *this;
}

Time Time::operator+(const Time& t) const
{
    int total1 = min * 60 + sec;
    int total2 = t.min * 60 + t.sec;
    int sum = total1 + total2;

    return Time(sum / 60, sum % 60);
}

Time Time::operator/(const int& n) const
{
    int total = min * 60 + sec;
    total /= n;
    return Time(total / 60, total % 60);
}

bool Time::operator<(const Time& t) const
{
    if (min < t.min) return true;
    if (min == t.min && sec < t.sec) return true;
    return false;
}

bool Time::operator>(const Time& t) const
{
    if (min > t.min) return true;
    if (min == t.min && sec > t.sec) return true;
    return false;
}

bool Time::operator==(const Time& t) const
{
    return min == t.min && sec == t.sec;
}

bool Time::operator!=(const Time& t) const
{
    return !(*this == t);
}

istream& operator>>(istream& in, Time& t)
{
    cout << "Minutes: ";
    in >> t.min;
    cout << "Seconds: ";
    in >> t.sec;
    t.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
    out << t.getMin() << ":" << t.getSec();
    return out;
}