//to find the length of linkedlist from a given array

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};
//function to create ll
Node* linkedlist(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
//finding the length of ll
int length(Node* head){
    int count=0;
    Node* mover=head;
    while(mover!=nullptr){
        count++;
        mover=mover->next;
    }
    return count;
}
int main(){
    vector<int>arr={1,2,3,4,5,6};
    int llength;
    Node* head=linkedlist(arr);
    llength=length(head);
    cout<<llength;
    
}
//output: 6

//why declare mover as head??
//because we have to traverse the linked list and we don't want to lose the head pointer.
//if we lose the head pointer, then we can't traverse the linked list.
//head pointer should be constant and not be moved.
