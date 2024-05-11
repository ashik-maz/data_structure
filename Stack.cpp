#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int arr[MAX];
int top=-1;
void printstack(){
    if(top==-1) cout<<"Stack Empty\n";
    else if(top>MAX)
        cout<<"Overflow\n";
    else if(top<-1)
        cout<<"Overflow\n";
    else{
    cout<<"Stack: ";
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
}
void push(){
    if(top<MAX){
        ++top;
        int x;
        cout<<"Enter Element: ";
        cin>>x;
        arr[top]=x;
    }
    
}

void pop(){
    if(top>-1)
        top--;
    
}

void menu(){
    cout<<"Enter your choich:\n1.Push\n2.Pop\n3.exit\n";
}

int main(){
    while(1){
    system("cls");
    printstack();
    menu();
    int x;
    cin>>x;
    switch (x)
    {
    case 1:
        push();
        printstack();
        menu();
        break;
    case 2:
        pop();
        printstack();
        menu();
        break;
    case 3:
        system("cls");
        printstack();
        exit(0);

        break;
    default:
        break;
    }
    }

}