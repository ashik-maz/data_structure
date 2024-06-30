#include<bits/stdc++.h>
using namespace std;

bool itemcount(vector<int> list1, vector<int>list2){
    unordered_map<int,bool> list;

    for(int i=0;i<list1.size();i++){
        list.insert({list1[i],true});
    }

    for(int j=0;j<list2.size();j++){
        if(list[list2[j]]){
            return true;
        }
    }

    return false;
}

int main(){
    vector<int>list1 {1,2,3};
    vector<int>list2 {11,12,3};
//if find any value, it's return true;
    cout<<itemcount(list1,list2);
}