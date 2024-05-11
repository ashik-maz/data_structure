#include<bits/stdc++.h>
#include <sstream>
using namespace std;

int evaluatePostfix(string& expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            st.push(stoi(token));
        } else if (token == "-") {
            int a = st.top();
            st.pop();
            st.push(-a);
        } else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            switch (token[0]) {
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
                    cerr << "Invalid operator: " << token << endl;
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
    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;
    return 0;
}