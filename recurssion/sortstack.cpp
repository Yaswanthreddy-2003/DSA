#include <iostream>
#include<stack>
#include<vector>
using namespace std;

void insert(stack<int>&s,int value){
    if(s.size()==0||s.top()<=value){
        s.push(value);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,value);
    
    s.push(temp);

}
void sort(stack<int>&s){
    if(s.size()==0)return;
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}
int main()
{
    vector<int>v={5,1,6,2,4,3};
    stack<int>s;
    
    for(int i:v){
        s.push(i);
    }
    sort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
//time complexity
//O(n^2) in worst case
//O(n) in best case

//space complexity
//O(n) for sort function
//O(n) for insert function

//but both functions do not run at the same time
//at any time only one function is running
//so we can say that the space complexity is O(n) for the recursion stack
//and O(n) for the stack used to store the elements
//so the total space complexity is O(n) + O(n) = O(n)
//but we can also say that the space complexity is O(n) for the recursion stack

