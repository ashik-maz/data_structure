#include<iostream>
using namespace std;

int  SIZE= 5;
bool loop=true;
int top=-1;

void printStack(int Stack[],int top)
{
    int sizeStack=top;
    if(sizeStack>=0)
    {
        cout<<"Stack is : ";
         for(int i=sizeStack;i>=0;i--)
    {
        cout<<Stack[i ]<<"  ";
    }
    cout<<endl;
    }
    else
    {
        cout<<"Stack is empty"<<endl;
    }
}

void Push(int Stack[])
{
    int data;

    if(top<SIZE-1)
    {
        cout<<"Enter int element : ";
        cin>>data;
        top++;
        Stack[top]=data;
        system("CLS");
        printStack(Stack,top);
    }
    else
    {
        cout<<"Overflow\n"<<endl;
        printStack(Stack,top);
    }
}

void Pop(int Stack[])
{
    int data;
    if(top>=0)
    {
        cout<<"Poped element : "<<Stack[top]<<endl;
        top--;
        printStack(Stack,top);
    }
    else
    {
        cout<<"Underflow\n"<<endl;
        printStack(Stack,top);
    }
}

void Exit(int Stack[])
{
    loop=false;
    printStack(Stack,top);
}

int main()
{
    int Stack[SIZE];
        while(loop)
    {
    cout<<"Enter Choice : \n1.Push()\n2.Pop()\n3.Exit()\n";
    int choice;
    cin>>choice;
    system("CLS");

    switch(choice)
    {
    case 1:
        Push(Stack);
        break;
    case 2:
        Pop(Stack);
     break;
    case 3:
        Exit(Stack);
        break;
    default:
        cout<<"Input valid choice"<<endl;
    }
  }
}
