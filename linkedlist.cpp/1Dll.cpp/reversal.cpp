//ll: 1->2->3->4->5
//reversal : 5->4->3->2->1

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
//create ll from arr
Node* convertarr2ll(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
//reversal of ll
Node* reversal(Node* head){
    //method 1
    //store the data of nodes in stack and then pop the elements from the stack and store them in the linked list.
    // stack<int>s;
    // Node* mover=head;
    // while(mover!=nullptr){
    //     s.push(mover->data);
    //     mover=mover->next;
    // }
    // mover=head;
    // while(mover!=nullptr){
    //     mover->data=s.top();
    //     s.pop();
    //     mover=mover->next;
    // }
    // return head;


    //time complexity: O(2n)~ O(n) two traversals are done.
    //space complexity: O(n) stack of size n is used.

    //method 2
    // Node* mover=head;
    // Node* prev=nullptr;
    // Node* front=nullptr;
    // while(mover!=nullptr){
    //     front=mover->next;
    //     mover->next=prev;
    //     prev=mover;
    //     mover=front;

    // }
    // return prev;
    //time complexity: O(n) one traversal is done.
    //space complexity: O(1) no extra space is used.

    //recursive method
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newhead=reversal(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr
    return newhead;

    //time complexity: O(n) one traversal is done.
    //space complexity: O(n) stack of size n is used.(recursion stack) otherwise O(1) space is used.


    
}
void print(Node* head){
    Node* mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}
int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=convertarr2ll(arr);
    head=reversal(head);
    print(head);
    return 0;



}