#pragma once
#include <iostream>
#include <list>

using namespace std;

template<class T>
class Vector
{
private:
    list<T> data;

public:
    Vector() {}

    Vector(int n)
    {
        T x;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter element #" << i + 1 << endl;
            cin >> x;
            data.push_back(x);
        }
    }

    void Print() const
    {
        if (data.empty())
        {
            cout << "Container is empty\n";
            return;
        }

        for (typename list<T>::const_iterator it = data.begin(); it != data.end(); ++it)
            cout << *it << "  ";
        cout << endl;
    }

    T Min() const
    {
        typename list<T>::const_iterator it = data.begin();
        T mn = *it;
        ++it;

        for (; it != data.end(); ++it)
        {
            if (*it < mn)
                mn = *it;
        }

        return mn;
    }

    T Max() const
    {
        typename list<T>::const_iterator it = data.begin();
        T mx = *it;
        ++it;

        for (; it != data.end(); ++it)
        {
            if (*it > mx)
                mx = *it;
        }

        return mx;
    }

    T Average() const
    {
        typename list<T>::const_iterator it = data.begin();
        T sum = *it;
        ++it;

        for (; it != data.end(); ++it)
            sum = sum + *it;

        return sum / (int)data.size();
    }

    void AddMinToEnd()
    {
        if (data.empty()) return;
        T mn = Min();
        data.push_back(mn);
    }

    void DeleteByKey(const T& key)
    {
        for (typename list<T>::iterator it = data.begin(); it != data.end(); )
        {
            if (*it == key)
            {
                it = data.erase(it);
                break;
            }
            else
            {
                ++it;
            }
        }
    }

    void AddMinMaxToAll()
    {
        if (data.empty()) return;

        T mn = Min();
        T mx = Max();
        T sum = mn + mx;

        for (typename list<T>::iterator it = data.begin(); it != data.end(); ++it)
            *it = *it + sum;
    }
};