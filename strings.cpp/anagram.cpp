//anagram
//two strings are said to be anagrams of each other if they have the same characters but in different order.the frequencies of the characters should be same.
//for example,listen and silent are anagrams of each other.
//the frequency of l,i,s,t,e,n in listen is 1,1,1,1,1 and the frequency of s,i,l,e,n,t in silent is 1,1,1,1,1.
//so the strings are anagrams of each other.

//brute
//1. sort the strings and compare them.

#include <bits/stdc++.h>
using namespace std;
bool anagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2){
        return true;
    }
    return false;
}
int main(){
    string s1="listen";
    string s2="silent";
    bool result=anagram(s1,s2);
    cout<<result;


}
//time complexity is O(nlogn) where n is the length of the string. for sorting the string it takes O(nlogn) time complexity.
//space complexity is O(1).

//2. using hash map
//create a hash map and store the frequency of the characters in the string.
//compare the hash maps of the strings.

#include <bits/stdc++.h>
using namespace std;
bool anagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    unordered_map<char,int>mp1,mp2;
    for(int i=0;i<s1.length();i++){
        mp1[s1[i]]++;
        mp2[s2[i]]++;
    }
    if(mp1==mp2){
        return true;
    }
    return false;
}
//time complexity is O(n) where n is the length of the string.
//space complexity is O(n) where n is the length of the string.

//method 2
bool anagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    int count[256]={0};
    for(int i=0;i<s1.length();i++){
        count[si[i]]++;
        count[s2[i]]--;
    }
    for(int i=0;i<256;i++){
        if(count[i]!=0){
            return false;
        }
    }
}
//time complexity is O(n+sizeof(char))~O(n) where n is the length of the string.
//space complexity is O(1).
//how is space complexity O(1)?
//size of array is 256,is a constant regarrdless of size of s1 and s2, which is a constant
//so the space complexity is O(1).

bool anagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    unordered_map<char,int>mp;
    for(int i=0;i<s1.length();i++){
        mp[s1[i]]++;
        mp[s2[i]]--;
    }
    for(auto x:mp){
        if(x.second!=0){
            return false;
        }
    }
}


