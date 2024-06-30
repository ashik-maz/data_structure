//circular queue
#include <iostream>
using namespace std;

template <typename Type>
class Queue
{
    int MAX_SIZE = 1e6;
    int front = 0;
    int rear = -1;
    int itemCount = 0;
    Type *arr = new Type[MAX_SIZE];

public:
    void push(Type value)
    {
        if (itemCount == MAX_SIZE)
        {
            cout << "Queue is full." << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        itemCount++;
    }

    void pop()
    {
        if (itemCount == 0)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        front = (front + 1) % MAX_SIZE;
        itemCount--;
    }

    Type front_element()
    {
        if (itemCount == 0)
        {
            cout << "Queue is empty." << endl;
            return -1; // Return some invalid value indicating empty queue
        }
        return arr[front];
    }

    int size()
    {
        return itemCount;
    }

    bool empty()
    {
        return itemCount == 0;
    }
};

int main()
{
    Queue<int> q;
    q.push(10);
    q.push(1);
    q.push(19);
    q.push(11);
    q.push(5);

    q.pop();

    cout << "The size is : " << q.size() << "\n";

    while (!q.empty())
    {
        cout << q.front_element() << " ";
        q.pop();
    }

    return 0;
}
