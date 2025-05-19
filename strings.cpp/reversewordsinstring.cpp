//eg: "the sky is blue"
//output: "blue is sky the"

//" hello world "
//output: "world hello"

//"a good   example"
//output: "example good a"  

//here we need to consider the gaps,even though there can be multiple spaces between the words, we need to consider only one space between the words.
//the gaps before beginninng of the string and after the end of the string should be ignored.

//brute force approach
//store the words in a stack and pop the words from the stack and store it in a string, also add gap between the words. like string=stack.top()+" "+string;
//time complexity is O(n) where n is the length of the string.
//space complexity is O(n) where n is the length of the string.

//efficient approach
//try to do without using the stack.
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    //coding without using stack
    string temp;
    string ans="";
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch!=' '){
            temp+=ch;
        }else{
            if(!temp.empty()){  
            if(!ans.empty()){
                ans=temp+" "+ans;
            }else{
                ans=temp;
            }
            temp="";
            }
        }
    }
    if(!temp.empty()){
        if(!ans.empty()){
            ans=temp+" "+ans;
        }else{
            ans=temp;
        }
    }
    return ans;
}
//time complexity is O(n) where n is the length of the string.
//space complexity is O(n) where n is the length of the string.