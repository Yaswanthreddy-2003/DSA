// //insertion in vectors
// vector<int>vec;
// vec.insert(vec.begin()+position,value you want to insert);

// //array
// array is of fixed size,so we can't insert elements in the middle of the array.
// instead we can take a new array of size n+1 and insert the elements in the new array.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[6]={1,2,3,4,5};
    int n=6;
    int pos=3;
    int value=10;
    for(int i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=value;
    n++;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

