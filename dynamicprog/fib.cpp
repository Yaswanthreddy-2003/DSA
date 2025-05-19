//dynamic programming in c++
//what is dynamic programming?
//dp stores results of subproblems and use it later to solve main problem.
//2 types in dp
//1.top down dp(memoization)
//bottom up dp(tabulation)

//memoization
//main problem to base case and stores the value and uses it later.

//tabulation
//base case to main problem

//fibonaci
//0,1,1,2,3,5,8,13,21...

//memoization
#include<iostream>
#include <vector>
using namespace std;
int fun(vector<int>&dp,int n){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    dp[n]=fun(dp,n-1)+fun(dp,n-2);
    return dp[n];
}
using namespace std;
int main(){
    int n=5;
    vector<int>dp(n+1,-1);
    return fun(dp,5);

}

//time complexity
//every subproblem(function) solved only once and returns in O(1) time
//so the time complexity is O(n) for n function calls

//space complexity
//n for dp array,n for recursion stack
//O(n)+O(n)=O(n)

//tabulation
int fun1(int n){
    if(n<=1)return n;
    vector<int>dp1(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//time complexity
//O(n) for n function calls

//space complexity
//O(n+1)~ O(n) for dp array

//space optimization
//dp[i]=dp[i-1]+dp[i-2]
//we only need the last two values to calculate the next value
//no need to maintain the whole array
int fun2(int n){
    if(n<=1)return n;
    int prev1=0,prev=1;
    int curr;
    for(int i=2;i<=n;i++){
        curr=prev+prev1;
        prev1=prev;
        prev=curr;
    }
    return prev; //or return curr
}
//tc O(n)
//sc O(1) for prev1,prev,curr
//so the space complexity is O(1) for the variables used to store the last two values