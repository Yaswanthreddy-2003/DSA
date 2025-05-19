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


//deletion of node in linked list
//deletion of head
Node* deletehead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;//why delete temp? coz we have to free the memory of the head in heap.
    return head;
}

    Node* deletetail(Node* head){
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        Node* mover=head;
        while(mover->next->next!=nullptr){
            mover=mover->next;
        }
        delete mover->next;
        mover->next=nullptr;
        //after deleting the tail, won't the address of  element before the tail points to null pointer automatically??
        //no, we have to do it manually.
        //why do we have to do it manually?
        //coz we have to free the memory of the tail element.
        //if we don't free the memory of the tail element, then it will be a memory leak.
        return head;
    }

    //deletion of kth node 
    Node* deletekth(Node* head,int k){
        if(head==nullptr){
            return head;
        }
        Node* temp=head;
        if(k==1){
            
            head=head->next;
            delete temp;
            return head;
        }
        int count=0;
        Node* prev=nullptr;
        while(temp!=nullptr){
            count++;
            prev=temp;
            temp=temp->next;
            if(count==k-1){
                prev->next=temp->next
                delete temp;
                break;
            }
        }
        return head;


    }

    //deletion of value
    Node* deletevalue(Node* head,int val){
        if(head==nullptr){
            return head;
        }
        Node* temp=head;
        if(head->data==val){
            head=head->next;
            delete temp;
            return head;
        }
        Node* prev=nullptr;
        while(temp!=nullptr){
            if(temp->data==val){
                prev->next=temp->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }


    void printll(Node* head){
        Node* mover=head;
        while(mover!=nullptr){
            cout<<mover->data<<" ";
            mover=mover->next;
        }
    }



int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head=convertarr2ll(arr);
    
    //head=deletehead(head);
    head=deletekth(head,3);
    printll(head);
}
