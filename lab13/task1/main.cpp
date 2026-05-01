#include <iostream>
#include <list>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef list<Time> TList;

Time g_key;
Time g_sum;

// создание списка
TList make_list(int n)
{
    TList l;
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
void print_list(const TList& l)
{
    if (l.empty())
    {
        cout << "List is empty\n";
        return;
    }

    for (TList::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << "  ";
    cout << endl;
}

// предикат для поиска/удаления по ключу
struct EqualKey
{
    bool operator()(const Time& t) const
    {
        return t == g_key;
    }
};

// функция для for_each: прибавить сумму min+max
void add_sum(Time& t)
{
    t = t + g_sum;
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

    TList l = make_list(n);

    cout << "\nInitial list:\n";
    print_list(l);

    // минимум и максимум
    Time mn = *min_element(l.begin(), l.end());
    Time mx = *max_element(l.begin(), l.end());

    cout << "\nMin = " << mn << endl;
    cout << "Max = " << mx << endl;

    // задание 3: добавить минимум в конец
    l.push_back(mn);
    cout << "\nAfter adding minimal element to the end:\n";
    print_list(l);

    // задание 4: найти и удалить по ключу
    cout << "\nEnter key to delete:\n";
    cin >> g_key;

    TList::iterator found = find_if(l.begin(), l.end(), EqualKey());
    if (found != l.end())
        cout << "Found: " << *found << endl;
    else
        cout << "Not found\n";

    l.remove_if(EqualKey());

    cout << "\nAfter deleting key:\n";
    print_list(l);

    // задание 5: к каждому прибавить min + max
    if (!l.empty())
    {
        mn = *min_element(l.begin(), l.end());
        mx = *max_element(l.begin(), l.end());
        g_sum = mn + mx;

        for_each(l.begin(), l.end(), add_sum);
    }

    cout << "\nAfter adding (min + max) to each element:\n";
    print_list(l);

    return 0;
}