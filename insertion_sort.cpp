#include<bits/stdc++.h>
using namespace std;
vector<int> insertion(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
    return v;
}

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &i:v) cin>>i;
    insertion(v);
    for(auto &i:v) cout<<i<<" ";
    return 0;
}
