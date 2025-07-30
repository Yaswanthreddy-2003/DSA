//combination sum 1
//Given an array of distinct integers candidates and a target integer target, 
//return a list of all unique combinations of candidates where the chosen numbers sum to target. 
//You may return the combinations in any order.

//The same number may be chosen from candidates an unlimited number of times. 
//Two combinations are unique if the frequency of at least one of the chosen numbers is different.

//thee same number can be repeated any number of times

//Example 2:

//Input: candidates = [2,3,5], target = 8
//Output: [[2,2,2,2],[2,3,3],[3,5]]

//all the elements in the candidates array are distinct and also positive.

void helper(int index, int sum, int target, vector<int>& current, vector<int>& candidates, vector<vector<int>>& result) {
    if (sum == target) {
        result.push_back(current);
        return;
    }
    if (index >= candidates.size() || sum > target) {
        return;
    }

    // include the current candidate
    current.push_back(candidates[index]);
    helper(index, sum + candidates[index], target, current, candidates, result); // allow the same number to be used again
    current.pop_back();

    // exclude the current candidate
    helper(index + 1, sum, target, current, candidates, result);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>>result;
    vector<int>current;
    int index=0;
    int sum=0;
    helper(index,sum,target,current,candidates,result);
    return result;
}

// Time complexity: O(2^n * k), where n is the number of candidates and k is the average size of the combinations.
//why not O(2*n * n)?
// Because we are not generating all subsets, we are only generating combinations that sum to the target.
//but why considering k(average size of combinations) in time complexity?
//some combinations will be shorter and some will be longer, so we consider the average size of combinations.

//space complexity:
// O(n + k*x), where n is the depth of the recursion stack, k is the average size of the combinations, and x is the number of unique combinations.
//n is the maximum depth of the recursion stack, which is equal to the number of candidates.
//for example 1,1,1,1,1,1,1,1,1,1 and target =10
//depth will be 10.
