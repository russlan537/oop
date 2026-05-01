#include <iostream>
#include <list>
#include "Time.h"

using namespace std;

typedef list<Time> List;

// создание списка
List make_list(int n)
{
    List l;
    Time t;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter element #" << i + 1 << endl;
        cin >> t;
        l.push_back(t);
    }
    return l;
}

// печать списка
void print_list(const List& l)
{
    if (l.empty())
    {
        cout << "List is empty\n";
        return;
    }

    for (List::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << "  ";
    cout << endl;
}

// минимум
Time min_elem(const List& l)
{
    List::const_iterator it = l.begin();
    Time mn = *it;
    ++it;

    for (; it != l.end(); ++it)
    {
        if (*it < mn)
            mn = *it;
    }

    return mn;
}

// максимум
Time max_elem(const List& l)
{
    List::const_iterator it = l.begin();
    Time mx = *it;
    ++it;

    for (; it != l.end(); ++it)
    {
        if (*it > mx)
            mx = *it;
    }

    return mx;
}

// среднее арифметическое
Time average(const List& l)
{
    List::const_iterator it = l.begin();
    Time sum = *it;
    ++it;

    for (; it != l.end(); ++it)
        sum = sum + *it;

    return sum / (int)l.size();
}

// добавить минимум в конец
void add_min_to_end(List& l)
{
    if (l.empty()) return;
    Time mn = min_elem(l);
    l.push_back(mn);
}

// удалить по ключу
void delete_by_key(List& l, const Time& key)
{
    for (List::iterator it = l.begin(); it != l.end(); )
    {
        if (*it == key)
        {
            it = l.erase(it);
            break;
        }
        else
        {
            ++it;
        }
    }
}

// прибавить ко всем (min + max)
void add_min_max_to_all(List& l)
{
    if (l.empty()) return;

    Time mn = min_elem(l);
    Time mx = max_elem(l);
    Time sum = mn + mx;

    for (List::iterator it = l.begin(); it != l.end(); ++it)
        *it = *it + sum;
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

    List l = make_list(n);

    cout << "\nInitial list:\n";
    print_list(l);

    cout << "\nAverage = " << average(l) << endl;

    // задание 3
    add_min_to_end(l);
    cout << "\nAfter adding minimal element to the end:\n";
    print_list(l);

    // задание 4
    Time key;
    cout << "\nEnter key to delete:\n";
    cin >> key;
    delete_by_key(l, key);

    cout << "\nAfter deleting element with key:\n";
    print_list(l);

    // задание 5
    add_min_max_to_all(l);
    cout << "\nAfter adding (min + max) to each element:\n";
    print_list(l);

    return 0;
}