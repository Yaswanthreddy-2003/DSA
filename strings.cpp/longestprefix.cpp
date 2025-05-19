//find the longest common prefix among array of strings.
//eg:["flower","flow","flight"]
//output:"fl"

//["dog","racecar","car"]
//output:""

//idea u sort all the arrays in the strings.
//then compare the first and last strings in the array.why compare first and last strings??
//because the first stringg is smallest in terms of alphabetical order and the last string is largest in terms of alphabetical order.
//if the first and last strings has common prefix, then it means all the strings in the array has common prefix.
//if the first and last strings has no common prefix, then it means there is no common prefix among the strings in the array.

#include <bits/stdc++.h>
using namespace std;
string prefix(vector<string>&ans){
    if(ans.size()==0)return "";
    if(ans.size()==1)return ans[0];
    string result="";
    sort(ans.begin(),ans.end());
    string first=ans[0];
    string last=ans[ans.size()-1];
    int i=0;
    while(i<first.length() && i<last.length() && first[i]==last[i]){
        result+=first[i];
        i++;

    }
    return result;
}