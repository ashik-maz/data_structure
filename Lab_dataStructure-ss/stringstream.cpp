#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str="Md Ibn Masud Sohan";
    stringstream ss(str);
    string str2;
    while(ss>> str2)
        cout<<str2<<" ";
}


