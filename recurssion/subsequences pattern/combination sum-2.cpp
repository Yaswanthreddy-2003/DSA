//leetcode 39
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

//example: 1,1,1,2,2 target=4
//output: {1,1,2},{2,2} 


//use forloop recursion when u hv questions that ask u to find unique combinations or unique permutations


//bruteforce approach
//take a set<vector<int>> to store the combinations

void helper(int index, int sum, int target, vector<int>& candidates, vector<int>& current, set<vector<int>>& result) {
    if (sum == target) {
        result.insert(current);
        return;
    }
    if (index >= candidates.size() || sum > target) {
        return;
    }

    //include the current candidate
    current.push_back(candidates[index]);
    helper(index+1, sum + candidates[index], target, candidates, current, result);
    current.pop_back();
    helper(index+1, sum, target, candidates, current, result);
}
vector<vector<int>>combinationsum2(vector<int>&candidates,int target){
    sort(candidates.begin(),candidates.end());
    set<vector<int>>result;
    vector<int>current;
    int index=0;
    int sum=0;
    helper(index,sum,target,candidates,current,result);
    vector<vector<int>>final_result(result.begin(), result.end()); // Convert set to vector
    return final_result;
}

//this will face TLE for large inputs
//for example 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
//100 elements with value 1 and target 30
//the code will generate many duplicate recursions before using the set to store unique combinations

//time complexity
//O(2^n * k* logn) in the worst case, where k is the average size of the combinations,logn is for set insertion
//space complexity
//O(n) for the recursion stack
//O(k*x) where k is the average size of the combinations and x is the number of unique combinations
//total O(n + k*x )

//optimization
//backtracking approach

void helper(int index,int sum,int target,vector<int>&current,vector<int>&candidates,vector<vector<int>>&result){
        if(sum==target){
            result.push_back(current);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            if(sum>target)break;
            current.push_back(candidates[i]);
            helper(i+1,sum+candidates[i],target,current,candidates,result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>current;
        int index=0;
        int sum=0;
        helper(index,sum,target,current,candidates,result);
        return result;
    }

//time complexity
//O(2^n * k) in the worst case, where k is the average size of the combinations
//space complexity
//O(n) for the recursion stack
//O(k*x) where k is the average size of the combinations and x is the number of unique combinations
//total O(n + k*x )
//this will not face TLE for large inputs

//why o(n) for recursion stack?
//because the maximum depth of the recursion stack will be n, where n is the size of the candidates array