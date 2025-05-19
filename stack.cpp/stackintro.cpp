//what is abstract data structure?
//An abstract data type (ADT) is a mathematical model for data types where a data type is defined by its behavior (semantics) from the point of view of a user of the data, 
//specifically in terms of possible values, possible operations on data of this type, and the behavior of these operations.

//reverse an array using stack
#include <iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>stack;
    stack.push(21);
    stack.push(22);
    stack.push(23);
    stack.push(24);
    int num=0;
    stack.push(num);
    stack.pop();
    stack.pop();
    stack.pop();
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<"hello";
}
