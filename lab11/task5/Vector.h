#pragma once
#include <iostream>
#include <queue>

using namespace std;

template<class T>
class Vector
{
private:
    queue<T> q;

public:
    Vector() {}

    Vector(int n)
    {
        T x;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter element #" << i + 1 << endl;
            cin >> x;
            q.push(x);
        }
    }

    void Print()
    {
        if (q.empty())
        {
            cout << "Queue is empty\n";
            return;
        }

        queue<T> temp = q;
        while (!temp.empty())
        {
            cout << temp.front() << "  ";
            temp.pop();
        }
        cout << endl;
    }

    T Min()
    {
        queue<T> temp = q;
        T mn = temp.front();
        temp.pop();

        while (!temp.empty())
        {
            if (temp.front() < mn)
                mn = temp.front();
            temp.pop();
        }

        return mn;
    }

    T Max()
    {
        queue<T> temp = q;
        T mx = temp.front();
        temp.pop();

        while (!temp.empty())
        {
            if (temp.front() > mx)
                mx = temp.front();
            temp.pop();
        }

        return mx;
    }

    T Average()
    {
        queue<T> temp = q;
        int count = 1;
        T sum = temp.front();
        temp.pop();

        while (!temp.empty())
        {
            sum = sum + temp.front();
            temp.pop();
            count++;
        }

        return sum / count;
    }

    void AddMinToEnd()
    {
        if (q.empty()) return;
        T mn = Min();
        q.push(mn);
    }

    void DeleteByKey(const T& key)
    {
        queue<T> temp;
        bool deleted = false;

        while (!q.empty())
        {
            T cur = q.front();
            q.pop();

            if (!deleted && cur == key)
            {
                deleted = true;
                continue;
            }

            temp.push(cur);
        }

        q = temp;
    }

    void AddMinMaxToAll()
    {
        if (q.empty()) return;

        T mn = Min();
        T mx = Max();
        T sum = mn + mx;

        queue<T> temp;

        while (!q.empty())
        {
            T cur = q.front();
            q.pop();
            temp.push(cur + sum);
        }

        q = temp;
    }
};