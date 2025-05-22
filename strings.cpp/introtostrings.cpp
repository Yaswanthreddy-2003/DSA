//diff between string and char is string terminates with null character(\0) and char doesn't.
//char str[size];

//ascii stores values of characters in the form of integers.
//ascii value for 'a' to 'z' is  97 to 122, 'A' to 'Z' is 65 to 90, '0' to '9' is 48 to 57.

//char stores  8 bits of data c++

//string is a class in c++ and char is a data type in c++.

#include <bits/stdc++.h>
using namespace std;

int main(){
    char x='a';
    int y=x;
    cout<<y<<endl;
    return 0;
}
//value of x is stored in y. so the output is 97.

//there is difference betwen string str and string str[] in c++.
//string str is a string class in c++ and string str[] is an array of strings in c++.
//string str is a sequence of characters and string str[] is an array of strings.

string str="hello";
str+="world";
cout<<str<<endl;//output is helloworld.

//u can't concatenate strings to str[] array.
//string str[]={"hello","world"};
//str+="world";//error
//instead u can concatenate strings to str[0] or str[1].

//check whether string is palindrome 
#include <bits/stdc++.h>
using namespace std;
bool pal(string str){
    int n=str.length();
    for(int i=0;i<n;i++){
        bool b=false;
        if(str[i]==str[n-1-i]){
            b=true;
            break;
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    string str="yassu";
    bool result=pal(str);
    cout<<result;
}
//output is 0.
//time complexity is O(n) where n is the length of the string.
//space complexity is O(1).

//substring and subsequence
//substring is a contiguous sequence of characters within a string.
//subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
//the order should not be changed in subsequence.

//String="abcd"
//substrings are "",a,b,c,d,ab,bc,cd,abc,bcd,abcd.
//total number of substrings are n(n+1)/2 where n is the length of the string.

//subsequences are "",a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd.
//total number of subsequences are 2^n where n is the length of the string.

//check whether a string is subseq or not
//iterative approach
bool subseq(string &s1,string &s2){
    int n=s1.length();
    int m=s2.length();
    if(m==0){
        return true;
    }
    int j=0;
    for(int i=0;i<n&&j<m;i++){
        if(s1[i]==s2[j]){
            j++;
        }
    }
    return j==m;
}
int main(){
    string s1="ABCDEFG";
    string s2="ADE";
    bool result=subseq(s1,s2);
    cout<<result;
}
//Time complexity is O(n+m)~O(n) where n is the length of the string.
//space complexity is O(1)

//recursive approach
bool sabseq(string &s1,string &s2,int i,int j,int n,int m){
    
    if(m==0)return true;
    if(j==m)return true;
    if(i==n)return false;
    if(s1[i]==s2[j]){
        return sabseq(s1,s2,i+1,j+1,n,m);
    }else{
        return sabseq(s1,s2,i+1,j,n,m);
    }
}
//to decrease the number of variables in recursive function
bool sabseq(string &s1,string &s2,int n;int m){
    if(m==0)return true;
    if(n==0)return false;
    if(s1[n-1]==s2[m-1]){
        return sabseq(s1,s2,n-1,m-1);
    }else{
        return sabseq(s1,s2,n-1,m);}
}
int main(){
    int i=0;
    int j=0;
    int n=s1.length();
    int m=s2.length();
    bool result=sabseq(s1,s2,i,j,n,m);
    cout<<result;
}
//result is 1
//time complexity is O(n+m)~O(n)
//space complexity is O(n+m)



