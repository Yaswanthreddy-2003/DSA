//insertion in linkedlist
//insertion at the beginning
//insertion at the end
//insertion at kth node
//insertion at value
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node*next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};
Node* convertarr2ll(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
        
    }
    return head;
}

//insertion at the beginning
Node* inserthead(Node* head, int val){
    // Node* temp=new Node(val);
    // temp->next=head;
    // head=temp;
    // return head;

    Node* temp=new Node(val,head);
    head=temp;
    return head;

}

//insertion at the end
Node* inserttail(Node* head,int val){
    Node* temp=new Node(val);
    if(head==nullptr){
        head=temp;
        return head;
    }
    Node* mover=head;
    while(mover->next!=nullptr){
        mover=mover->next;
    }
    mover->next=temp;
    return head;
}
void printll(Node* head){
    Node* mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}

//insertion at kth node
Node* insertkth(Node* head,int k,int val){
    Node* temp=new Node(val);
    if(k==1){
        temp->next=head;
        head=temp;
        return head;
    }
    Node* mover=head;
    int count=0;
    while(mover!=nullptr){
        count++;
        if(count==k-1){
            temp->next=mover->next;
            mover->next=temp;
            break;
        }
        mover=mover->next;
    }
    return head;
}  
int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head=convertarr2ll(arr);
    // head=inserthead(head,100); //100 1 2 3 4 5 6
    head=inserttail(head,100);
    printll(head);
    return 0;
}
