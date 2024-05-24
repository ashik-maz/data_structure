
#include<iostream>
using namespace std;

int  SIZE= 3;
bool loop=true;
int top=-1,low=-1;

void printQueue(int Queue[],int top,int low)
{
    int sizeQueue=top;
    if(sizeQueue>=0  && low!=SIZE-1)
    {
        cout<<"Queue is : ";
         for(int i=low;i<=sizeQueue;i++)
    {
        cout<<Queue[i ]<<"  ";
    }
    cout<<endl;
    }
    else
    {
        cout<<"Queue is empty"<<endl;
    }
}

void Push(int Queue[])
{
    int data;

    if(top<SIZE-1)
    {
        cout<<"Enter int element : ";
        cin>>data;
        top++;
        low=0;
        Queue[top]=data;
        system("CLS");
        printQueue(Queue,top,low);
    }
    else
    {
        cout<<"Overflow\n"<<endl;
        printQueue(Queue,top,low);
    }
}

void Pop(int Queue[])
{
    int data;
    if(top>=low)
    {
        cout<<"Poped element : "<<Queue[low]<<endl;
        low++;
        printQueue(Queue,top,low);
    }
    else
    {
        cout<<"Underflow\n"<<endl;
        printQueue(Queue,top,low);
    }
}

void Exit(int Queue[])
{
    loop=false;
    printQueue(Queue,top,low);
}

int main()
{
    int Queue[SIZE];
        while(loop)
    {
    cout<<"Enter Choice : \n1.Push()\n2.Pop()\n3.Exit()\n";
    int choice;
    cin>>choice;
    system("CLS");

    switch(choice)
    {
    case 1:
        Push(Queue);
        break;
    case 2:
        Pop(Queue);
     break;
    case 3:
        Exit(Queue);
        break;
    default:
        cout<<"Input valid choice"<<endl;
    }
  }
}
