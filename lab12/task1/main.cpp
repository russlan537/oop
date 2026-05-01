#include <iostream>
#include <set>

using namespace std;

typedef set<float> TSet;
typedef TSet::iterator it;

// создание множества
TSet make_set(int n)
{
    TSet s;
    float a;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element #" << i + 1 << ": ";
        cin >> a;
        s.insert(a);
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
        cout << *i << " ";
    cout << endl;
}

// поиск минимального элемента
float min_elem(const TSet& s)
{
    return *s.begin();
}

// поиск максимального элемента
float max_elem(const TSet& s)
{
    TSet::const_reverse_iterator i = s.rbegin();
    return *i;
}

// задание 3: добавить минимальный элемент
void add_min(TSet& s)
{
    if (s.empty()) return;

    float mn = min_elem(s);
    s.insert(mn);
}

// задание 4: удалить элемент по ключу
void delete_by_key(TSet& s, float key)
{
    s.erase(key);
}

// задание 5: к каждому элементу добавить (min + max)
void add_min_max_to_all(TSet& s)
{
    if (s.empty()) return;

    float mn = min_elem(s);
    float mx = max_elem(s);
    float sum = mn + mx;

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

    // задание 3
    add_min(s);
    cout << "\nAfter adding minimal element:\n";
    print_set(s);

    // задание 4
    float key;
    cout << "\nEnter key to delete: ";
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