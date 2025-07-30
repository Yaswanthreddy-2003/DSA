//given a subarray,print all the sums of subsets generated in increasing ordeer

void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }

//time complexity:
//2^n combinations and pushing a value takes O(1) time
//sorting of an array of size 2^n takes O(2^n * log(2^n)) time
//total is O(2^n + 2^n * log(2^n)) ~ O(2^n * log(2^n))

//space complexity:
//O(n) for the recursion stack
//O(2^n) for the result vector
//total is O(n + 2^n) ~ O(2^n)


//subset sum-2
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

//remember for questions asking for unique combinations or unique permutations, use for loop recursion
void helper(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    // Iterate through the array starting from the current index
    for(int i=index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1])continue;
        current.push_back(nums[i]);
        helper(i+1, nums, current, result);
        current.pop_back();
    }
}
vector<vector<int>>noDuplicates(vector<int>&nums){
    vector<vector<int>>result;
    vector<int>current;
    sort(nums.begin(), nums.end());
    int index=0;
    helper(index,nums,current,result);
    return result;
}

//time complexity:
//O(2^n * k), where n is the number of elements in nums and k is the average size of the subsets.
//O(nlogn) for sorting the nums array
//total time complexity is O(2^n * k + nlogn) ~ O(2^n * k)

//space complexity:
//O(n) for the recursion stack
//O(2^n * k) for the result vector
//total space complexity is O(n + 2^n * k) ~ O(2^n * k)