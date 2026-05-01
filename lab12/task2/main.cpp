#include <iostream>
#include <set>
#include "Time.h"

using namespace std;

typedef set<Time> TSet;
typedef TSet::iterator it;

// создание множества
TSet make_set(int n)
{
    TSet s;
    Time t;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter element #" << i + 1 << endl;
        cin >> t;
        s.insert(t);
    }

    return s;
}

// печать множества
void print_set(const TSet& s)
{
    if (s.empty())
    {
        cout << "Set is empty\n";
        return;
    }

    for (TSet::const_iterator i = s.begin(); i != s.end(); ++i)
        cout << *i << "  ";
    cout << endl;
}

// минимум
Time min_elem(const TSet& s)
{
    return *s.begin();
}

// максимум
Time max_elem(const TSet& s)
{
    TSet::const_reverse_iterator i = s.rbegin();
    return *i;
}

// среднее арифметическое
Time average(const TSet& s)
{
    TSet::const_iterator i = s.begin();
    Time sum = *i;
    ++i;

    int count = 1;
    for (; i != s.end(); ++i)
    {
        sum = sum + *i;
        count++;
    }

    return sum / count;
}

// задание 3: добавить минимум
void add_min(TSet& s)
{
    if (s.empty()) return;
    Time mn = min_elem(s);
    s.insert(mn);
}

// задание 4: удалить по ключу
void delete_by_key(TSet& s, const Time& key)
{
    s.erase(key);
}

// задание 5: добавить (min + max) ко всем
void add_min_max_to_all(TSet& s)
{
    if (s.empty()) return;

    Time mn = min_elem(s);
    Time mx = max_elem(s);
    Time sum = mn + mx;

    TSet temp;
    for (TSet::const_iterator i = s.begin(); i != s.end(); ++i)
        temp.insert(*i + sum);

    s = temp;
}

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

    TSet s = make_set(n);

    cout << "\nInitial set:\n";
    print_set(s);

    cout << "\nAverage = " << average(s) << endl;

    // задание 3
    add_min(s);
    cout << "\nAfter adding minimal element:\n";
    print_set(s);

    // задание 4
    Time key;
    cout << "\nEnter key to delete:\n";
    cin >> key;
    delete_by_key(s, key);

    cout << "\nAfter deleting key:\n";
    print_set(s);

    // задание 5
    add_min_max_to_all(s);
    cout << "\nAfter adding (min + max) to each element:\n";
    print_set(s);

    return 0;
}