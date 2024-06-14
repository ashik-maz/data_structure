//double-ended queue (deque)

#include <iostream>
using namespace std;

template <typename Type>
class Deque
{
    int MAX_SIZE = 1e6;
    int frontIndex = 0;
    int rearIndex = -1;
    Type *arr = new Type[MAX_SIZE];

public:
    void push_front(Type value)
    {
        if (frontIndex == 0 && rearIndex == MAX_SIZE - 1)
        {
            cout << "Deque is full." << endl;
            return;
        }
        if (frontIndex == 0)
            frontIndex = MAX_SIZE - 1;
        else
            frontIndex--;
        arr[frontIndex] = value;
    }

    void push_back(Type value)
    {
        if (frontIndex == 0 && rearIndex == MAX_SIZE - 1)
        {
            cout << "Deque is full." << endl;
            return;
        }
        if (rearIndex == MAX_SIZE - 1)
            rearIndex = 0;
        else
            rearIndex++;
        arr[rearIndex] = value;
    }

    void pop_front()
    {
        if (frontIndex == rearIndex + 1)
        {
            cout << "Deque is empty." << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % MAX_SIZE;
    }

    void pop_back()
    {
        if (frontIndex == rearIndex + 1)
        {
            cout << "Deque is empty." << endl;
            return;
        }
        rearIndex = (rearIndex - 1 + MAX_SIZE) % MAX_SIZE;
    }

    Type front()
    {
        if (frontIndex == rearIndex + 1)
        {
            cout << "Deque is empty." << endl;
            return -1; // Return some invalid value indicating empty deque
        }
        return arr[frontIndex];
    }

    Type back()
    {
        if (frontIndex == rearIndex + 1)
        {
            cout << "Deque is empty." << endl;
            return -1; // Return some invalid value indicating empty deque
        }
        return arr[rearIndex];
    }

    int size()
    {
        if (rearIndex >= frontIndex)
            return rearIndex - frontIndex + 1;
        else
            return MAX_SIZE - frontIndex + rearIndex + 1;
    }

    bool empty()
    {
        return frontIndex == rearIndex + 1;
    }
};

int main()
{
    Deque<int> dq;
    dq.push_front(10);
    dq.push_back(1);
    dq.push_front(19);
    dq.push_back(11);
    dq.push_front(5);

    dq.pop_front();

    cout << "The size is : " << dq.size() << "\n";

    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    return 0;
}
