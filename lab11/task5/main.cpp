#include <iostream>
#include "Time.h"
#include "Vector.h"

using namespace std;

int main()
{
	int n;
	cout << "Number of elements: ";
	cin >> n;

	if (n <= 0)
	{
		cout << "Wrong size\n";
		return 0;
	}

	Vector<Time> vec(n);

	cout << "\nInitial queue:\n";
	vec.Print();

	cout << "\nAverage = " << vec.Average() << endl;

	vec.AddMinToEnd();
	cout << "\nAfter adding minimal element to the end:\n";
	vec.Print();

	Time key;
	cout << "\nEnter key to delete:\n";
	cin >> key;
	vec.DeleteByKey(key);

	cout << "\nAfter deleting key:\n";
	vec.Print();

	vec.AddMinMaxToAll();
	cout << "\nAfter adding (min + max) to each element:\n";
	vec.Print();

	return 0;
}