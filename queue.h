#ifndef QUEUE_H
#define QUEUE_H

template <class Item>
class Queue
{
private:
    struct Node { Item item; struct Node * next; };
    Node * front;
    Node * rear;
    int qsize;
public:
    Queue();
    ~Queue();
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
    int queuesize() const;

};


template <class Item>
Queue<Item>::Queue()
{
    front = rear = nullptr;
    qsize = 0;
}

template <class Item>
bool Queue<Item>::enqueue(const Item &item)
{
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    qsize++;

    if (front == nullptr)
        front = add;
    else
        rear ->next = add;
    rear = add;
    return true;
}

template <class Item>
bool Queue<Item>::dequeue(Item &item)
{
    if (front == nullptr)
        return false;
    item = front ->item;
    qsize--;
    Node * temp = front;
    front = front -> next;
    delete temp;
    if (qsize == 0)
        rear = nullptr;
    return true;
}

template <class Item>
int Queue<Item>::queuesize() const
{
    return qsize;
}

template <class Item>
Queue<Item>::~Queue()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front -> next;
        delete temp;
    }
}

#endif // QUEUE_H
