#include <iostream>
#include <list>
using namespace std;

typedef list<float> List;

// создание списка
List make_list(int n)
{
    List l;
    float a;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element #" << i + 1 << ": ";
        cin >> a;
        l.push_back(a);
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
        cout << *it << " ";
    cout << endl;
}

// поиск минимального элемента
float min_elem(const List& l)
{
    List::const_iterator it = l.begin();
    float min = *it;
    ++it;

    for (; it != l.end(); ++it)
    {
        if (*it < min)
            min = *it;
    }
    return min;
}

// поиск максимального элемента
float max_elem(const List& l)
{
    List::const_iterator it = l.begin();
    float max = *it;
    ++it;

    for (; it != l.end(); ++it)
    {
        if (*it > max)
            max = *it;
    }
    return max;
}

// добавить минимальный элемент в конец
void add_min_to_end(List& l)
{
    if (l.empty()) return;
    float mn = min_elem(l);
    l.push_back(mn);
}

// удалить элемент с заданным ключом
void delete_by_key(List& l, float key)
{
    for (List::iterator it = l.begin(); it != l.end(); )
    {
        if (*it == key)
        {
            it = l.erase(it);
            break; // удаляем только первый найденный
        }
        else
        {
            ++it;
        }
    }
}

// к каждому элементу прибавить сумму min и max
void add_min_max_to_all(List& l)
{
    if (l.empty()) return;

    float mn = min_elem(l);
    float mx = max_elem(l);
    float sum = mn + mx;

    for (List::iterator it = l.begin(); it != l.end(); ++it)
        *it += sum;
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

    // задание 3
    add_min_to_end(l);
    cout << "\nAfter adding minimal element to the end:\n";
    print_list(l);

    // задание 4
    float key;
    cout << "\nEnter key to delete: ";
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