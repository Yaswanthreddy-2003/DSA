#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* convertarr2dll(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1 ;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node* insertbeforehead(Node* head,int val){
    Node* newhead = new Node(val,head,nullptr);
    head=head->next;
    head->back=newhead;
    return newhead;
}

Node* insertaftertail(Node* head,int val){
    Node* mover=head;
    while(mover->next!=nullptr) {
        mover=mover->next;
    }
    Node* temp=new Node(val,nullptr,mover);
    mover->next=temp;
    return head;
}
Node* insertbeforetail(Node* head,int val){
    Node* mover=head;
    Node* prev=nullptr;
    while(mover->next!=nullptr){
        prev=mover;
        mover=mover->next;
    }
    Node* temp=new Node(val,mover,prev);
    prev->next=temp;
    mover->back=temp;
    return head;
}
Node* insertafterkth(Node* head,int position,int data){
    Node* mover=head;
    int count=-1;
    Node* temp=new Node(data);
    while(temp!=nullptr){
        count++;
        if(count==position)break;
        mover=mover->next;
    }
    if(mover==nullptr)return head; //if k is greater than the length of the linked list
    temp->next=mover->next;
    temp->back=mover;
    if(mover->next!=nullptr)mover->next->back=temp;
    mover->next=temp;
    return head;
}
Node* insertbeforekth(Node* head,int val,int k){
    if(k==1){
        return insertbeforehead(head,val);
    }
    Node* mover=head;
    Node* prev=nullptr;
    int count=0;
    while(mover!=nullptr){
        count++;
        prev=mover;
        mover=mover->next;
        if(count==k-1)break;
    }
    Node* temp=new Node(val,mover,prev);
    prev->next=temp;
    mover->back=temp;
    return head;
    

}
void print(Node* head){
    Node* mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}

int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head=convertarr2dll(arr);
    //head=insertbeforehead(head,100);
    head=insertaftertail(head,100);
    print(head);
    return 0;
    
}