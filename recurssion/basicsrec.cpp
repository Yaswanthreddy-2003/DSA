//print 1 to n
#include <bits/stdc++.h>
using namespace std;
void print(int n){
    if(n==0){
        return;
    }
    print(n-1);
    cout<<n<<" ";
}
int main(){
    int k=10;
    print(n);


}
// Time complexity: O(n)
// Space complexity: O(n) for the recursion stack

//print n to 1
void print(int n){
    if(n==0)return;
    cout<<n<<" ";
    print(n-1);
}

//factorial of n
int fact(int n){
    if(n==0)return 1;
    return n*fact(n-1);
}
int main(){
    int n=5;
    cout<<fact(n)<<endl;
}

//factorial
int fact(int n){
    if(n==1)return 1;
    return n*fact(n-1);
}
int main(){
    int n=5;
    cout<<fact(n)<<endl;
}
// Time complexity: O(n)
// Space complexity: O(n) for the recursion stack

//fibonacci
int fib(int n){
    if(n==0||n==1)return n;
    return fib(n-1)+fib(n-2);
}
int main(){
    int n=5;
    cout<<fib(n)<<endl;
}
// Time complexity: O(2^n) exponential
//recursive equation: t(n)=t(n-1)+t(n-2)+O(1)
// Space complexity: O(n) for the recursion stack

//reverse array
void reverse(vector<int>&arr,int left,int right){
    if(left>=right)return;
    swap(arr[left],arr[right]);
    reverse(arr,left+1,right-1)
}
int main(){
    vector<int>arr={1,2,3,4,5};
    reverse(arr,0,arr.size()-1);
    for(auto i:arr)cout<<i<<" ";
    cout<<endl;
}
// Time complexity: O(n)
// Space complexity: O(n) for the recursion stack
//recursive equation: t(n)=t(n-1)+O(1)


//sum of n natural numbers
int sum(int n){
    if(n==0)return 0;
    return n+sum(n-1);
}
// Time complexity: O(n)
// Space complexity: O(n) for the recursion stack
//recursive equation: t(n)=t(n-1)+O(1)

//sum of digits of a number
int digsum(int n){
    if(n==0)return 0;
    return n%10+digsum(n/10);
}
//t(n)=t(n/10)+O(1)
//t(n)=t(n/10^k)+k*O(1)
//recursion stops before n becomes 0
n/10^k=1=>k=log(n)
//t(n)=t(1)+c*log(n)
//t(1) is constant and as the function grows to infinity, the constant becomes negligible
//t(n)=O(log(n))

//palindrome
bool ispal(string s,int left,int right){
    if(left>=right)return true;
    if(s[left]!=s[right])return false;
    return ispal(s,left+1,right-1);
}