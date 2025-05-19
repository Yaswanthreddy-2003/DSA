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