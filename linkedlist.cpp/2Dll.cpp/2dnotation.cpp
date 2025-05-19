//representation of 2d linked list
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
Node* deletehead(Node* head){
    if(head==nullptr || head->next=nullptr)return nullptr;
    Node* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}


Node* deletetail(Node* head){
    if(head==nullptr)return head;
    Node* mover=head;
    // while(mover->next->next !=nullptr){
    //     mover=mover->next;
        
    // }
    // delete mover->next;
    // mover->next=nullptr;
    // return head;
    while(mover->next!=nullptr){
        mover=mover->next;
    }
    Node* prev=mover->back;
    prev->next=nullptr;
    mover->back=nullptr;
    delete mover;
    return head;
    
}


Node* deletekth(Node* head,int k){
    if(head==nullptr)return head;
    int count=0;
    Node* mover=head;
    while(mover!=nullptr){
        count++;
        if(count==k) break;
        mover=mover->next;
    }
    Node* prev=mover->back;
    Node* front=mover->next;

    if(prev==nullptr && front==nullptr){
        return nullptr;
    }
    else if(prev==nullptr){
        front->back=nullptr;
        mover->next=nullptr;
        delete mover;
        return front;
    }
    else if(front==nullptr){
        prev->next=nullptr;
        mover->back=nullptr;
        delete mover;
        return head;
    }
    prev->next=front;
    front->back=prev;

    mover->next=nullptr;
    mover->back=nullptr;
    delete mover;
    return head;
}
void print(Node* head){
    Node* mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<"->";
        mover=mover->next;
    }
}
int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head=convertarr2dll(arr);
    head=deletekth(head,4);
    print(head);
    // Node* y=new Node(arr[0],nullptr,nullptr);
    // cout<<y;
    // cout<<y->data;
    // cout<<y->next;
    // cout<<y->back;
    return 0;
}