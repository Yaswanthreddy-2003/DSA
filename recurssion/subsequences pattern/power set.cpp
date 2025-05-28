//leetcode 78
//given an integer array nums of unique elements, return all possible subsets (the power set).

// void helper(int index,vector<vector<int>>&result,vector<int>&current,vector<int>&nums){
//     if(index==nums.size()){
//         result.push_back(current);
//         return;
//     }
//     current.push_back(nums[index]);
//     helper(index+1,result,current,nums);
//     current.pop_back();
//     helper(index+1,result,current,nums);
// }
// vector<vector<int>>subsets(vector<int>&nums){
//     vector<vector<int>>result;
//     vector<int>current;
//     int index=0;
//     helper(index,nums,current,result);
//     return result;
// }
// int main(){
//     vector<int>nums={1,2,3};
//     vector<vector<int>>result=subsets(nums);
//     for(int i=0;i<result.size();i++){
//         for(int j=0;j<result[i].size();j++){
//             cout<<result[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }
// //time complexity 
// //for every element,2 choices pick or not pick
// //so total 2^n combinations
// //push for a vector of n size takes O(n) time
// //so total time complexity is O(n*2^n)

// //space complexity
// //O(n) for the recursion stack
// //O(n) for the current vector
// //O(n*2^n) for the result vector
// //total O(n*2^n)

// //how is sc for result vector O(n*2^n)?
// //because we have 2^n subsets and each subset can have at most n elements
// //so total space for result vector is O(n*2^n)