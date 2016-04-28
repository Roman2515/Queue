#include <iostream>
#include <queue.h>
using namespace std;

template <class T>
void Print_enqueue( Queue<T> & queue, const int value)
{
    T item;
    cout << "Output :\n\t";
    for (int i = 0; i < value; i++)
    {
        queue.dequeue(item);
        cout << item << " : ";
    }
}


int main()
{
    Queue<char> Q1;
    char item;

    for (int i = 0; i < 5; i++)
    {
        cin >> item;
        Q1.enqueue(item);
    }

    Print_enqueue(Q1, 3);

    for (int i = 0; i < 5; i++)
    {
        cin >> item;
        Q1.enqueue(item);
    }

    Print_enqueue(Q1, 7);
    return 0;
}

