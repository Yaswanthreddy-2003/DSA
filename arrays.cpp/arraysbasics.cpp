//int array[n]={0};
//all the elements of the array are initialized to 0.

//int array[n]={1};
//only the first element of the array is initialized to 1 and the rest of the elements are initialized to 0.
//int array[n]={-1};
//only the first element of the array is initialized to -1 and the rest of the elements are initialized to 0.

//min sum of indices whose value of sum of array indexs is equal to k
int minimum(vector<int>&arr,int k){
    int n=arr.size();
    int min_sum=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                min_sum=min(min_sum,i+j);
            }
        }
    }
    return min_sum;
}
