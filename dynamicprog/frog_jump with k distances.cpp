#include <bits/stdc++.h>
using namespace std;

int tab(vector<int>&h,int k){
    int n=h.size();
    vector<int>dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mincost=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int cost=dp[i-j]+abs(h[i]-h[i-j]);
                mincost=min(cost,mincost);
            }
        }
        dp[i]=mincost;
    }
    return dp[n-1];
}
//tc: O(n*k)
//sc: o(n) for dp array
int memo(vector<int>&h,int index,vector<int>&dp,int k){
    if(index==0)return dp[0]=0;
    if(dp[index]!=-1)return dp[index];
    int mincost=INT_MAX;
    for(int j=1;j<=k;j++){
        if(index-j>=0){
            int cost= memo(h,index-j,dp,k)+abs(h[index]-h[index-j]);
            mincost=min(cost,mincost);
        }    
    }
    return dp[index]=mincost;
    
}
//tc: O(n*k)
//sc: O(n) for dp array + O(n) for recursion stack

//we cannot optimise sc upto O(1) using prev,prev1,curr etc
//when k=n, sc becomes o(n)

int main()
{
   vector<int>h={15,4,1,14,15};
   int k=3;
   
   cout<<tab(h,k)<<endl;
   return 0;
   
}