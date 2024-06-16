#include <iostream>
using namespace std;

template <typename Type>
class Stack{
    int MAX_SIZE=1e6;
    int last=-1;
    Type *arr =new Type[MAX_SIZE];

    public:
    void push(Type value){
        ++last;
        arr[last]=value;
    }
    void pop(){
        --last;
    }
    Type top(){
        return arr[last];
    }
    int size(){
        return last+1;
    }

    bool empty(){
        if(last==-1) return true;
        return false;
    }

    Type operator[](int index){
        if(index<0 || index>=last){
            cout<<"Out of range !";
        }
        return arr[index];
    }
};

int main(){
    Stack <int> st;
    st.push(1);
    st.push(19);
    st.push(13);
    st.push(32);
    st.push(33);
    st.pop();
    cout<<"size of Stack= "<<st.size()<<"\n";


    cout<<st[2];


    cout<<"element Are: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}