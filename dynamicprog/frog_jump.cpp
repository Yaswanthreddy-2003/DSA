//climbing stairs with minimum cost
//given at a position i, you can jump to i+1 or i+2
// The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

//to find the minimum cost from starting to the end.

//#include <bits/stdc++.h>
//using namespace std;

//memoization
// int memo(int index,vector<int>&h,vector<int>&dp){
//     if(index==0)return dp[0]=0;
//     int onestep=memo(index-1,h,dp)+abs(h[index]-h[index-1]);
//     int twostep=INT_MAX;
//     if(index>1){
//         twostep=memo(index-2,h,dp)+abs(h[index]-h[index-2]);
//     }
//     return dp[index]=min(onestep,twostep);
// }

//tc:o(n)
//sc:o(n) for recursion stack and o(n) for vec dp. o(2n)~o(n)

//tabulation
// void tab(vector<int>&h,vector<int>&dp){
//     dp[0]=0;
//     for(int i=1;i<dp.size();i++){
//         int onestep=dp[i-1]+abs(h[i]-h[i-1]);
//         int twostep=INT_MAX;
//         if(i>1){
//             twostep=dp[i-2]+abs(h[i]-h[i-2]);
//         }
//         dp[i]=min(onestep,twostep);
//     }
// }
//tc o(n) sc o(n)

//optimised
int optimized(vector<int>& h) {
        // Code here
        int n=height.size();
        if(n==1)return 0;
        int prev2=0;
        int prev1=abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            int onestep=prev1+abs(height[i]-height[i-1]);
            int twostep=prev2+abs(height[i]-height[i-2]);
            int curr=min(onestep,twostep);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
}
//tc o(n)
//sc o(1)


int mincost(vector<int>&h){
    int n=h.size();
    vector<int>dp(n,-1);
    //memo(n-1,h,dp);
    //tab(h,dp);
    //return optimized(h);
    return dp[n-1];
    
}
int main()
{
    vector<int>h={30,20,50,10,40};
    cout<<mincost(h)<<endl;

    return 0;
}