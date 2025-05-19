//printing elements in a map
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<char,int>mp;
    mp["a"]=5;
    mp['b']=10;

    for(auto &it:mp){
        cout<<it.first<<"->"<<it.second<<endl;
    }//piring all ele in map

    //specific ele
    //method 1
    cout<<"value of apple: "<<mp[a]<<endl;
    //using map.find()
    auto it=map.find(a);

    if(it!=mp.end()){
        cout<<"value of "<<a<<": "<<it->second<<endl;
    }else{
        cout<<"key not found"<<endl;
    }
}