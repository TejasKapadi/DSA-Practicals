#include <iostream>
using namespace std;

const int MAX = 5;

class queue
{
private:
    int a[MAX];
    int front;
    int rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
    }

    int empty(void)
    {
        if (front == -1 && rear == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int full(void)
    {
        if (rear == MAX - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int x)
    {
        if (full())
        {
            cout << "\nQueue is full";
            return;
        }

        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }

        a[rear] = x;
    }

    int dequeue(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        int x = a[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return x;
    }

    int peek(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        return a[front];
    }

    void display(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return;
        }

        cout << "\nQueue elements:";
        for (int i = front; i <= rear; i++)
        {
            cout << "\t" << a[i];
        }
    }
};

int main()
{
    int x;
    queue q;

    q.enqueue(7);
    q.enqueue(10);
    q.enqueue(18);
    q.enqueue(19);
    q.enqueue(45);

    q.display();

    if (!q.empty())
    {
        x = q.dequeue();
        cout << "\nRemoved: " << x;
    }

    q.display();

    x = q.peek();
    cout << "\nFront element is: " << x;

    return 0;
}
/*
//Output:
PS D:\Tejas> cd "d:\Tejas\" ; if ($?) { g++ Queue_using_array.cpp -o Queue_using_array } ; if ($?) { .\Queue_using_array }

Queue elements: 7       10      18      19      45
Removed: 7
Queue elements: 10      18      19      45
Front element is: 10

*/