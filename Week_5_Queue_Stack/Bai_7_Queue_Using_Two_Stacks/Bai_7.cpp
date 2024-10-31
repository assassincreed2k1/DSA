#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *nextNode;
};

struct Queue
{
    Node *head;
    Node *tail;
};

void initialize(Queue &q)
{
    q.head = nullptr;
    q.tail = nullptr;
}

void add(Queue &q, int x)
{
    Node *newNode = new Node();
    newNode->value = x;
    newNode->nextNode = nullptr;

    if (q.tail == nullptr)
    {
        q.head = newNode;
        q.tail = newNode;
        return;
    }

    q.tail->nextNode = newNode;
    q.tail = newNode;
}

int remove(Queue &q)
{
    if (q.head == nullptr)
    {
        cout << "Queue empty!\n";
        return -1;
    }

    Node *temp = q.head;
    int data = temp->value;
    q.head = q.head->nextNode;

    if (q.head == nullptr)
    {
        q.tail = nullptr;
    }
    delete temp;
    return data;
}

int main()
{
    int requests;
    cin >> requests;

    Queue queue;
    initialize(queue);

    while (requests > 0)
    {
        int operation;
        cin >> operation;
        if (operation == 1)
        {
            int value;
            cin >> value;
            add(queue, value);
        }
        else if (operation == 2)
        {
            remove(queue);
        }
        else if (operation == 3)
        {
            cout << queue.head->value << "\n";
        }
        requests--;
    }
}
