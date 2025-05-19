//binary search applies only to sorted array.

//real life example of binary search: 
// 1. searching a word in dictionary.
// 2. searching a number in phonebook.


//binary search is used to find the index of the element in the sorted array.
//for finding the index,we divide the array into two parts and check the middle element.
//if the middle element is equal to the element we are searching for,then we return the index of the middle element.
//if the middle element is greater than the element we are searching for,then we search in the left part of the array,leaving the right part totally
//if the middle element is less than the element we are searching for,then we search in the right part of the array,leaving the left part totally.
//we continue this process until we find the element or the left part becomes greater than the right part.

//iterative code:
int bs(int arr[],int target){
    int n=sizeof(arr)/sizeof(arr[0]);//arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
/*eg: [3,4,6,7,9,12,16,17] target=16
low=0,high=7,mid=3
arr[mid]=7<16,so low= mid+1=4
low=4,high=7. mid=4+7/2=5
arr[mid]=12<16,so low=mid+1=6
low=6,high=7,mid=6+7/2=6
arr[mid]=16=16,so return mid=6
index of 16 is 6.*/

//recursive code:
int bs(int arr[],int target,int low=0, int high){
    if(low>high){
        return -1;
    }
    int mid= (low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
        return bs(arr,low+1,high,target);
    }
    else{
        return bs(arr,low,high-1,target);
    }
}

/*eg: [3,4,6,7,9,12,16,17] target=13
low=0,high=7,mid=3
arr[mid]=7<13,so low= mid+1=4
low=4,high=7. mid=4+7/2=5
arr[mid]=12<13,so low=mid+1=6
low=6,high=7,mid=6+7/2=6
arr[mid]=16<13,so high=mid-1=5
low=6,high=5, low>high -> return -1.

there is no element such as 13 in the array.*/

// recursive tree :
// f(arr,0,7,13) -> return -1
// f(arr,4,7,13) -> return -1
// f(arr,6,7,13) -> return -1
// f(arr,6,5,13)
// return -1






