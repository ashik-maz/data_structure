#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100;
int stk[MAX_SIZE];
int top_level = -1;
void push( int element){
    if(top_level<MAX_SIZE-1){
        top_level++;
        stk[top_level]=element;
    }
}

void pop()
{
    if(top_level > -1){
        top_level--;
    }
}

void display()
{
    cout << stk[0] << endl;
}

int main()
{
    string s;
    getline(cin, s);
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') && s[i+1] == ' ')
        {
            int a = stk[top_level];
            pop();
            int b = stk[top_level];
            pop();

            if(s[i] == '+'){
                push(b+a);
            }
            else if(s[i] == '-'){
                push(b-a);
            }
            else if(s[i] == '*'){
                push(b*a);
            }
            else{
                push(b/a);
            }

        }
        else if (s[i] == ' ')
        {
            continue;
        }
        else if (s[i] == '$')
        {
            display();
            break;
        }
        else
        {
            sum = 0;
            bool isNegative = false;
            if(s[i] == '-'){
                isNegative = true;
                i++;
            }
            while(i<s.length() && s[i] != ' '){
                sum = (sum * 10) + (s[i] - '0');
                i++;
            }
            if(isNegative) sum = -sum;
            push(sum);
        }
    }
    return 0;
}

// 5 6 2 + * 12 4 / - $
