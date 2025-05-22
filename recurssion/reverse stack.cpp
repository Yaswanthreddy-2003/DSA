//method 1
//take 2 stacks
void reverse(stack<int>&s,stack<int>&temp){
    if(s.size()==0)return;
    int value=s.top();
    s.pop();
    temp.push(value);
    reverse(s,temp);
}

//using single stack
void insert(stack<int>&s,int value){
    if(s.size()==0){
        s.push(value);
        return;
    }
    int last=s.top();
    s.pop();
    insert(s,value);
    s.push(last);

}
void reverse(stack<int>&s){
    if(s.size()==0)return;
    int value=s.top();
    s.pop();
    reverse(s);
    insert(s,value);
}
//time complexity in detail
//time complexity for recursive function is calculated by total number of recursive calls made and number of operations done in each recursive call
//reverse function is called n times O(n)
//for every reverse call, insert function is called.

//in insert function
//pops all element until it is empty O(n)
//pushes all elements back O(n)

// for first call(deepest element) ,stack is empty so direct push the value O(0) no recursive call
//second last - 1 recursive call
//first/top most element - n-1 recursive calls
//O(0+1+2+....+n-1)=O(n*(n-1)/2)=O(n^2)

//in every reccursive call,push and pop is included,so u do not have to count them again extra.
//so the time complexity is O(n^2) for the insert function

//O(n)+O(n^2)=O(n^2)

//space complexity
//O(n) for the recursion stack

int main(){
    stack<int>s;
    stack<int>temp;
    s.push(5); 
    s.push(1);
    s.push(6);
    s.push(2);
    s.push(4);
    s.push(3);

    reverse(s,temp);
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }


}