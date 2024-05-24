#include<bits/stdc++.h>
#include <sstream>
using namespace std;

int SIZE=100;
int top=-1;

void Push(int Stack[],string data)
{
    if(top<SIZE-1)
    {
        top++;
        Stack[top]=stoi(data);
    }
}
void Push(int Stack[],int data)
{
    if(top<SIZE-1)
    {
        top++;
        Stack[top]=data;
    }
}
void Pop()
{
   if(top!=-1)
   top--;
}
int Top(int Stack[])
{
    int data;
   if(top!=-1)
    data= Stack[top];
   return data;
}

int Postfix(string& expression, int Stack[]) {

    stringstream ss(expression);
    string sbstr;

    while (ss >> sbstr) {
        if (isdigit(sbstr[0])) {
            Push(Stack,sbstr);
        } else {
            int a = Top(Stack);
            Pop();
            int b = Top(Stack);
            Pop();

            switch (sbstr[0]) {
                case '+':
                    Push(Stack,b + a);
                    break;
                case '-':
                    Push(Stack,b - a);
                    break;
                case '*':
                    Push(Stack,b * a);
                    break;
                case '/':
                    Push(Stack,b / a);
                    break;
                default:
                    cout << "Invalid operator: " << sbstr << endl;
                    return -1;
            }
        }
    }

    return Top(Stack);
}


int main()
{
    int Stack[SIZE];
     string expression;
    cout << "Enter the postfix expression: ";
    getline(cin, expression);
    int result =Postfix(expression,Stack);
    cout << "Result: " << result << endl;
    return 0;
}




