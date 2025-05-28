//find all subsequences with sum k

void helper(int index, int sum, int k, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if(index==nums.size()){
        if(sum==k){
            result.push_back(current);
        }
        return;
    }
    current.push_back(nums[index]);
    helper(index+1,sum+nums[index],k,nums,current,result);
    current.pop_back();
    helper(index+1,sum,k,nums,current,result);
}
vector<vector<int>>subsets(vector<int>&nums,int k){
    vector<vector<int>>result;
    vector<int>current;
    int index=0;
    int sum=0;
    void helper(index,sum,k,nums,current,result);
    return result;
}

//time complexity 
//O(2^n * n)

//space complexity
//O(n) for the recursion stack
//O(n) for the current vector
//O(n * 2^n) for the result vector
//total O(n * 2^n)



//2.check if there is a subsequence with sum k
bool helper(int index,int sum,int k,vector<int>&nums){
    if(index==nums.size()){
        if(sum==k){
            return true;
        } else {
            return false;
        }
    }
    bool pick=helper(index+1,sum+nums[index],k,nums);
    if(pick==true)return true;

    bool notpick=helper(index+1,sum,k,nums);
    if(notpick==true)return true;

    return false;
}

//time complexity
//O(2^n)
//space complexity
//O(n) for the recursion stack

//3.find the number of subsequences with sum k
int helper(int index,int sum,int k,vector<int>&nums){
    if(index==nums.size()){
        if(sum==k){
            return 1;
        }else return 0;
    }
    //current.push_back(nums[index]);
    int pick=helper(index+1,sum+nums[index],k,nums);
    //current.pop_back();
    //current.push_back(nums[index]);
    int not_pick=helper(index+1,sum,k,nums);
    return pick+not_pick;
}
//tc 
//O(2^n)

//sc
//O(n) for the recursion stack