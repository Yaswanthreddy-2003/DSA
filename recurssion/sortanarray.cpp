//intuition
//we can use recursion to sort an array
//pop the last element of array until the array is empty
//then insert in sorted array
//if the element to be inserted is greater than the last element of the array,then insert in end
//else pop the last element of the array and call insert function again

#include <iostream>
#include <vector>
using namespace std;
void insert(vector<int>&a,int value){
    if(a.size()==0||a.back()<=value){
        a.push_back(value);
        return;
    }
    int last=a.back();
    a.pop_back();
    insert(a,value);
    a.push_back(last);
    
}
void sort1(vector<int>&a){
    if(a.size()==0){
        return;
    }
    int last=a.back();
    a.pop_back();
    sort1(a);
    insert(a,last);
}
int main()
{
    vector<int>a={3,1,2,5,4};
    
    sort1(a);
    for(int i:a){
        cout<<i<<" ";
    }

    return 0;
}
//time complexity
//for example 5,4,3,2,1
//for 5 ,a.back()<-value,so 1 step
//for 4 ,insert function called 2 times
//for 3 ,insert function called 3 times
//for 2 ,insert function called 4 times
//for 1 ,insert function called 5 times
//O(1)+O(2)+......+O(n-1)+O(n)=O(n^2)

//best case will be when the array is already sorted

//call sortArray() n times
//each call goes into insert() once
//So:
//Each insert() takes O(1) in best case
//O(n) inserts each taking O(1) time



//space complexity
//O(n) for recursion stack
