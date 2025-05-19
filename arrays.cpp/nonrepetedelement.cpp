//method 1
#include<iostream>
#include<vector>
using namespace std;
int nonrepeat(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        bool flag=true;
        for(int j=0;j<nums.size();j++){
            if(i!=j && nums[i]==nums[j]){
                flag=false;
                break;
            }

        }
        if(flag){
            return nums[i];
        }
    }
    return -1; //if no non repeating element is found
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}

//time complexity is O(n^2)
//space complexity is O(1)

//method 2
int nonrepeat(vector<int>&nums){
    int result=0;
    for(int i=0;i<nums.size();i++){
        result^=nums[i];
    }
    return result;
}

//time complexity is O(n)
//space complexity is O(1)

//method3
int nonrepeat(vector<int>&nums){
    unordered_set<int,int>mapp; //for(auto i:nums){mapp[i]++;}
    for(int i=0;i<nums.size();i++){
        mapp[nums[i]]++;
    }
    for(auto i:mapp){
        if(i.second ==1){
            return i.first;
        }
    }
    return -1;
    
    
}
//what is i.first and i.second?
//mapp is key value pair
//i.first is key
//i.second is value here it is the frequency of the element

//time complexity is O(n)
//space complexity is O(n)