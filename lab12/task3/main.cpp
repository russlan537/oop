#include <iostream>
#include "Time.h"
#include "Container.h"

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

	Container<Time> c(n);

	cout << "\nInitial container:\n";
	c.Print();

	cout << "\nAverage = " << c.Average() << endl;

	c.AddMin();
	cout << "\nAfter adding minimal element:\n";
	c.Print();

	Time key;
	cout << "\nEnter key to delete:\n";
	cin >> key;
	c.DeleteByKey(key);

	cout << "\nAfter deleting key:\n";
	c.Print();

	c.AddMinMaxToAll();
	cout << "\nAfter adding (min + max) to each element:\n";
	c.Print();

	return 0;
}