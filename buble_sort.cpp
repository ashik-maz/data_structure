#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    for(auto &i:a) cin>>i;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])  {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(auto i:a) cout<<i<<" ";

}