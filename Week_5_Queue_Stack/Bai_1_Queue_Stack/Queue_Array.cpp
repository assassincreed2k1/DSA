#include <iostream>
using namespace std;

#define MAX 1000

class Queue
{
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == MAX - 1;
    }

    void enqueue(int value)
    {
        if(isFull()){
            return;
        }
        if(isEmpty()){
            front = 0;
        }
        arr[rear++] = value;
    }

    int dequeue()
    {
        if(isEmpty()){
            return -1;
        }
        int value = arr[front];
        if(front>=rear){
            front = rear = -1;
        } else{
            front++;
        }
        return value;
    }

    void display()
    {
        if(isEmpty()){
            return;
        }
        for (int i = front; i < rear;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    int arr[MAX];
    int front;
    int rear;
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}