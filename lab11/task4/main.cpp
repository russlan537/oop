#include <iostream>
#include <queue>
#include "Time.h"

using namespace std;

typedef queue<Time> Queue;

// создание очереди
Queue make_queue(int n)
{
    Queue q;
    Time t;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter element #" << i + 1 << endl;
        cin >> t;
        q.push(t);
    }

    return q;
}

// печать очереди
void print_queue(Queue q)
{
    if (q.empty())
    {
        cout << "Queue is empty\n";
        return;
    }

    while (!q.empty())
    {
        cout << q.front() << "  ";
        q.pop();
    }
    cout << endl;
}

// минимум
Time min_elem(Queue q)
{
    Time mn = q.front();
    q.pop();

    while (!q.empty())
    {
        if (q.front() < mn)
            mn = q.front();
        q.pop();
    }

    return mn;
}

// максимум
Time max_elem(Queue q)
{
    Time mx = q.front();
    q.pop();

    while (!q.empty())
    {
        if (q.front() > mx)
            mx = q.front();
        q.pop();
    }

    return mx;
}

// среднее арифметическое
Time average(Queue q)
{
    int count = 1;
    Time sum = q.front();
    q.pop();

    while (!q.empty())
    {
        sum = sum + q.front();
        q.pop();
        count++;
    }

    return sum / count;
}

// добавить минимум в конец очереди
void add_min_to_end(Queue& q)
{
    if (q.empty()) return;
    Time mn = min_elem(q);
    q.push(mn);
}

// удалить первый элемент с заданным ключом
void delete_by_key(Queue& q, const Time& key)
{
    Queue temp;
    bool deleted = false;

    while (!q.empty())
    {
        Time t = q.front();
        q.pop();

        if (!deleted && t == key)
        {
            deleted = true;
            continue;
        }

        temp.push(t);
    }

    q = temp;
}

// прибавить ко всем (min + max)
void add_min_max_to_all(Queue& q)
{
    if (q.empty()) return;

    Time mn = min_elem(q);
    Time mx = max_elem(q);
    Time sum = mn + mx;

    Queue temp;

    while (!q.empty())
    {
        Time t = q.front();
        q.pop();
        temp.push(t + sum);
    }

    q = temp;
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

    Queue q = make_queue(n);

    cout << "\nInitial queue:\n";
    print_queue(q);

    cout << "\nAverage = " << average(q) << endl;

    // добавим минимум в конец
    add_min_to_end(q);
    cout << "\nAfter adding minimal element to the end:\n";
    print_queue(q);

    // удалить по ключу
    Time key;
    cout << "\nEnter key to delete:\n";
    cin >> key;
    delete_by_key(q, key);

    cout << "\nAfter deleting key:\n";
    print_queue(q);

    // прибавить min + max ко всем
    add_min_max_to_all(q);
    cout << "\nAfter adding (min + max) to each element:\n";
    print_queue(q);

    return 0;
}