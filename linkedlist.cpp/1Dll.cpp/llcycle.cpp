//find if the ll is a cyclic ll or not
//eg: 1->2->3->4
          \      /
            5

//method 1
//store the nodes in a hashmap and check if the node is already present in the hashmap.
/*unordered_map<ListNode*, int> nodemap;
This hashmap stores the memory addresses (pointers) of nodes, not their values.
Even if two nodes have the same value, their addresses in memory are different.*/

// Example
// Consider these nodes in memory:

// Node Position	Value	Memory Address (Example)
// 1 (head)	3	0x100
// 2	3	0x200
// 3	2	0x300
// 4	1	0x400
// 5	2	0x500
// 6	4	0x600
// 7 (Cycle to Node 3)	2	0x300
// When we check nodemap.find(mover), we are checking if a node’s memory address is already in the hashmap.
// Since 0x100 and 0x200 are different, both will be added separately.

bool check(Node* head){
    if(head==nullptr || head->next==nullptr)return false;
    unordered_map<Node*,int>mp;
    Node* mover=head;
    while(mover!=nullptr){
        if(mp.find(mover)!=mp.end()){
            return true;
        }
        mp[mover]=1;
        mover=mover->next;
    }
    return false;
//time complexity: O(n * 2* logn) , logn for find and search operations.
//space complexity: O(n) hashmap of size n is used.
}
//a method which i thought but is incorrect
bool check(Node* head){
    if(head==nullptr || head->next==nullptr)return false;
    unordered_map<Node*,int>mp;
    Node* mover=head;
    while(mover!=nullptr){
        mp[mover]++;
        mover=mover->next;
    }
    for(auto x:mp){
        if(x.second>1){
            return true;
        }
    }
}
//this code gives tle because in a cyclic linked list, the loop will never end.
//mover will never be nullptr.

//method 2
//using two pointers
//slow pointer and fast pointer
bool check(Node* head){
    if(head==nullptr || head->next==nullptr)return false;
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
//time complexity: O(n) n is the number of nodes in the linked list.
//space complexity: O(1) only two pointers are used.

//why are we using 2 pointers one fast moving by 2 steps and other by 1 step?
//if there is a cycle in the linked list, the fast pointer will eventually meet the slow pointer.
//eg: in cycle if the distance between fast and slow pointer is k nodes
//fast moves 2 nodes and slow moves 1 node
//so in next step, the distance decreases by 1
//in next step, the distance decreases by 1
//and at point the distance becomes 0 and they meet.
//since distance % 1 = 0, they will meet at some point.



//if there is no cycle, the fast pointer will reach the end of the linked list.

//code for both cyclic and acyclic ll
Node* findMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // Detect cycle
        if (fast == head || fast->next == head) break;
    }

    return slow;
}
//time complexity: O(n) n is the number of nodes in the linked list.
//space complexity: O(1) only two pointers are used.
