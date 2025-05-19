//Given a string, find the leftmost repeating character of the string. i.e The first character that appeared again in the further string.
//eg: geeksforgeeks
//output: g

//brute force approach
//use for loops and find the first character that is repeating and return that character
#include<bitset>/stdc++.h>
using namespace std;
int leftmost(string &str){
    int n=str.length();
    for(int i=0;i<n;i++){//for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            if(str[i]==str[j]){
                return i;
            }
        }
    }
    return -1;
}
int main(){
    string str="geeksforgeeks";
    int n=leftmost(str);
    if(n==-1){
        cout<<"No repeating character";
    }
    else{
        cout<<str[n];
    }
}
//output is g
//time complexity is O(n^2) where n is the length of the string.
//space complexity is O(1).

//efficient approach
//use hashing to store the frequency of the characters and return the first character that is repeating.
int leftmost(string &str){
    int count[256]={0};
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]>1){
            return i;
        }
    }
    return -1;
}
//time complexity is O(n++256)~O(n) where n is the length of the string.
//space complexity is O(256)~O(1).constant space complexity 0(1)

//we are using two for loops in the above approach. we can optimize the above approach by using only one for loop.

//efficient approach 2
//use hashing to store the frequency of the characters and return the first character that is repeating.
int leftmost(string& str){
    int count[256]={0};
    fill(count,count+256,-1);
    int res=INT_MAX;
    for(int i=0;i<str.length();i++){
        if(count[str[i]]==-1){
            count[str[i]]=i;
        }else{
            res=min(res,count[str[i]]);
        }
    }
    if(res==INT_MAX){
        return -1;
    }else{
        return res;
    }
}