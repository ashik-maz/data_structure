///Implementation of Stack using C++

#include <iostream>

using namespace std;

template <typename Type>
class Stack {
    int MAX_SIZE = 1e6;
    int last = -1;
    Type *arr = new Type[MAX_SIZE];
public:
    void push(Type val) {
        ++last;
        arr[last] = val;
    }
    void pop() {
        --last;
    }
    Type top() {
        return arr[last];
    }
    int size() {
        return last+1;
    }
    bool empty() {
        if (last == -1) return true;
        return false;
    }
};

int main() {
    Stack <int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    cout << "Size is: " << S.size() << "\n";
    cout << "Elements are:\n";
    while (!S.empty()) {
        cout << S.top() << "\n";
        S.pop();
    }
}