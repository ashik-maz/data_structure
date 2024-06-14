// Implementation lf queue
#include <iostream>
using namespace std;

template <typename Type>
class Queue
{
    int MAX_SIZE = 1e6;
    int last = -1;
    Type *arr = new Type[MAX_SIZE];

public:
    void push(Type value)
    {
        ++last;
        arr[last] = value;
    }

    void pop()
    {
        --last;
        for (int i = 0; i <= last; ++i)
        {
            arr[i] = arr[i + 1];
        }
    }

    Type front()
    {
        return arr[0];
    }

    int size()
    {
        return last + 1;
    }

    bool empty()
    {
        if (last == -1)
            return true;
        return false;
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
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}