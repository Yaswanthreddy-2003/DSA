//map.count() and map.find()
//map.count() returns 1 if the key is present in the map and 0 if the key is not present in the map.
//map.find() returns the iterator to the key if the key is present in the map and map.end() if the key is not present in the map.
//map.count() is used to check whether the key is present in the map or not.
//map.find() is used to get the iterator to the key if the key is present in the map.

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,int>mp={{1,2},{2,3},{3,4}};
    cout<<mp.count(1)<<endl; //1
    cout<<mp.count(4)<<endl; //0
    
    auto it=mp.find(1);
    if(it!=mp.end){
        cout<<it->first<<" "<<it->second<<endl;

    }else{
        cout<<"key not found"<<endl;
    }//1 2
}