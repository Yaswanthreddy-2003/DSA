//boundary traversal of binary tree
/*Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N] 
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: [1, 2, 4, 8, 9, 6, 7, 3]*/

//divide problem into 3 parts
//1. left boundary traversal
//2. right boundary traversal
//3.leaf node traversal
//4. combine all the 3 traversals.
//for above eg: left:1,2 leaf:4,8,9,6 right:7,3  combine:1,2,4,8,9,6,7,3


//checking whether the node is leaf node or not.
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data1) {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

// Function to check if a node is a leaf
bool isleaf(Node* root) {
    return (root->left == nullptr && root->right == nullptr);
}

// Function to add left boundary
void leftboundary(Node* root, vector<int>& res) {
    Node* curr = root->left;  // ✅ Fixed Initialization
    while (curr != nullptr) {
        if (!isleaf(curr)) {
            res.push_back(curr->data);
        }
        curr = (curr->left != nullptr) ? curr->left : curr->right; // ✅ Prevents infinite loop
    }
}

// Function to add right boundary
void rightboundary(Node* root, vector<int>& res) {
    Node* curr = root->right;  // ✅ Fixed Initialization
    vector<int> temp;
    while (curr != nullptr) {
        if (!isleaf(curr)) {
            temp.push_back(curr->data);
        }
        curr = (curr->right != nullptr) ? curr->right : curr->left; // ✅ Prevents infinite loop
    }
    // Reverse and add right boundary
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

// Function to add leaf nodes
void leafnode(Node* root, vector<int>& res) {
    if (root == nullptr) return;  // ✅ Prevents segmentation fault

    if (isleaf(root)) {
        res.push_back(root->data);
        return;
    }
    leafnode(root->left, res);
    leafnode(root->right, res);
}

// Function to perform boundary traversal
vector<int> boundarytraversal(Node* root) {
    vector<int> res;
    if (root == nullptr) return res;

    if (!isleaf(root)) {  // ✅ Ensures root is added only if it's not a leaf
        res.push_back(root->data);
    }

    leftboundary(root, res);
    leafnode(root, res);
    rightboundary(root, res);

    return res;
}

// Driver code
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> res = boundarytraversal(root);
    
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}



