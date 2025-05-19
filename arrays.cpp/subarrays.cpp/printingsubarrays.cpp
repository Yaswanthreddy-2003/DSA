//[1,2,3]
//subarrays are [1],[1,2],[1,2,3],[2],[2,3],[3]
//[1,3] is not a subarray of [1,2,3]
//for a subarray, the order of the elements should be the same.should be continuous.
//subarray is a contiguous part of an array.
//[1,3] is a subsequence not a subarray
//printing subarrays
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,5,6};
    // for(int i=0;i<arr.size();i++){
    //     for(int j=i;j<arr.size();j++){
    //         for(int k=i;k<=j;k++){
    //             cout<<arr[k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // } 
    

    //sum of all subarrays
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        for(int j=i+1;j<arr.size();j++){
            sum+=arr[j];
            cout<<sum<<endl;
        }
    }
}