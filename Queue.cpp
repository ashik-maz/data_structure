#include<bits/stdc++.h>
using namespace std;
#define MAX 3
int arr[MAX];
int top=-1;
int font=0;
void printstack(){
    if(top>=font){
    cout<<"Queue: ";
    for(int i=font;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;}
    else if(top>=MAX)
        cout<<"Overflow\n";
    else if(font>top)
        cout<<"Overflow\n";
    else cout<<"Empty Queue";
}
void push(){
    if(top<MAX){
        ++top;
        int x;
        cout<<"Enter Element: ";
        cin>>x;
        arr[top]=x;
    }
    else cout<<"Overflow\n";
    
}

void pop(){
    if(font<=top)
        font++;
    else
        cout<<"Underflow";
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