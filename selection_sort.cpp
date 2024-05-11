#include<bits/stdc++.h>
using namespace std;
vector<int> selection(vector<int>&v){
    for(int i=0;i<v.size();++i){
        int minIndex=i;
        for(int j=i+1;j<v.size();++j){
            if(v[j]<v[minIndex]) minIndex=j;   
        }
        swap(v[minIndex],v[i]);
    }
    return v;
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &i:v) cin>>i;
    selection(v);
    for(auto &i:v) cout<<i<<" ";
    return 0;
}
