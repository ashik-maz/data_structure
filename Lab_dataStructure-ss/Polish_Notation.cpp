#include<bits/stdc++.h>
#include <sstream>
using namespace std;

int Postfix(string& expression) {
    stack<int>st;
    stringstream ss(expression);
    string sbstr;

    while (ss >> sbstr) {
        if (isdigit(sbstr[0])) {
            st.push(stoi(sbstr));
        } else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            switch (sbstr[0]) {
                case '+':
                    st.push(b + a);
                    break;
                case '-':
                    st.push(b - a);
                    break;
                case '*':
                    st.push(b * a);
                    break;
                case '/':
                    st.push(b / a);
                    break;
                default:
                    cout << "Invalid operator: " << sbstr << endl;
                    return -1;
            }
        }
    }

    return st.top();
}

int main() {
    string expression;
    cout << "Enter the postfix expression: ";
    getline(cin, expression);
    int result =Postfix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
