//brute force approach
bool check(vector<int>&nums){
    vector<int>arr=nums;
    sort(arr.begin(),arr.end());
    if(arr==nums){
        return true;
    }

    for(int x=0;x<nums.size();x++){
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=arr[(i+x)%nums.size()]){
                flag=false;
                break;
            }
        }
        if(flag){
            return true;
        }
        return false;
    }
}

// time complexity is O(nlogn) + O(n) = O(nlogn)
// space complexity is O(n)

//important technique
// u can't write vector<int>arr=sort(nums.begin(),nums.end());
//sort function returns void
//so u can't assign void to vector<int>ar




//optimal approach
bool check(vector<int>&nums){
    int count=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]){
            count++;
        }
    }
    if(nums[nums.size()-1]>nums[0]){
        count++;
    }
    if(count<=1){
        return true;
    }
    return false;

    //return count<=1;
}
//time complexity is O(n)
//space complexity is O(1)

//u can't write if(nums[nums.size()-1]>nums[0]){count++}) inside the for loop
//because if u write inside the for loop then it would be executed n-1 times for every i and count will be equal to n-1
//so u need to write it outside the for loop to check the last element with the first element.


//method-2
bool check(vector<int>&nums){
    vector<int>arr=nums;
    arr.insert(arr.end(),nums.begin(),nums.end());

    for(int i=0;i<nums.size();i++){
        if(is_sorted(arr.begin()+i,arr.begin()+i+nums.size())){
            return true;
        }
    }
    return false;
}

//time complexity: 
vector<int>arr=nums; O(n)
arr.insert(arr.end(),nums.begin(),nums.end()); //O(n)
O(n)+O(n) =0(2n) ~0(n)

for loop -> o(n)
is_sorted(arr.begin()+i,arr.begin()+i+nums.size()) ->checks n elements -> o(N)
total o(N*n) = o(n^2)

final 0(n^2)+o(n) = o(n^2)

//space complexity is O(n)
