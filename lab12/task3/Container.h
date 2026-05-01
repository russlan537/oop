#pragma once
#include <iostream>
#include <set>

using namespace std;

template<class T>
class Container
{
private:
	set<T> data;

public:
	Container() {}

	Container(int n)
	{
		T x;
		for (int i = 0; i < n; i++)
		{
			cout << "\nEnter element #" << i + 1 << endl;
			cin >> x;
			data.insert(x);
		}
	}

	void Print() const
	{
		if (data.empty())
		{
			cout << "Container is empty\n";
			return;
		}

		for (typename set<T>::const_iterator it = data.begin(); it != data.end(); ++it)
			cout << *it << "  ";
		cout << endl;
	}

	T Min() const
	{
		return *data.begin();
	}

	T Max() const
	{
		typename set<T>::const_reverse_iterator it = data.rbegin();
		return *it;
	}

	T Average() const
	{
		typename set<T>::const_iterator it = data.begin();
		T sum = *it;
		++it;

		int count = 1;
		for (; it != data.end(); ++it)
		{
			sum = sum + *it;
			count++;
		}

		return sum / count;
	}

	void AddMin()
	{
		if (data.empty()) return;
		T mn = Min();
		data.insert(mn);
	}

	void DeleteByKey(const T& key)
	{
		data.erase(key);
	}

	void AddMinMaxToAll()
	{
		if (data.empty()) return;

		T mn = Min();
		T mx = Max();
		T sum = mn + mx;

		set<T> temp;
		for (typename set<T>::const_iterator it = data.begin(); it != data.end(); ++it)
			temp.insert(*it + sum);

		data = temp;
	}
};