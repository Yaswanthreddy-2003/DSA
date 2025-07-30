//combination sum3
//Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

//Only numbers 1 through 9 are used.
//Each number is used at most once.
//Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

//since the question asks for unique combinations, we can use for loop recursion

Input: k = 3, n = 9 //only subsets of size 3 that sum to 9 will be accepted
Output: [[1,2,6],[1,3,5],[2,3,4]]

void helper(int index,int sum,int k,int n,vector<int>&current,vector<vector<int>>&result,vector<int>&nums){
    if(current.size() == k) {
        if (sum == n) {
            result.push_back(current);
        }
        return;
    }
    for(int i=index;i<nums.size();i++){
        if(sum> n) break; // No need to continue if sum exceeds n
        current.push_back(nums[i]);
        helper(i+1, sum + nums[i], k, n, current, result, nums); // Move to the next index
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>>combination3(int k,int n){
    vector<vector<int>>result;
    vector<int>current;
    vector<int>nums={1,2,3,4,5,6,7,8,9};
    int index=0;
    int sum=0;
    helper(index, sum, k, n, current, result, nums);
    return result;
}
// Time complexity: O(2^n * k), where n is the number of elements in nums and k is the average size of the combinations.
// Space complexity: O(n + k * x), where n is the depth of the recursion stack, k is the average size of the combinations, and x is the number of unique combinations.
// The recursion depth is limited by the number of elements in nums, which is 9 in this case.


