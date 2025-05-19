//tree is not a linear linked list.
//tree is a non linear data structure.
//tree is a collection of nodes where each node has a value and a list of references to other nodes (children).
//tree is a hierarchical data structure.
//tree is a recursive data structure.

//Binary tree is a tree in which each node has at most two children.(0/1/2 children)

//full binary or strict binary tree: a binary tree in which each node has either 0 or 2 children.

//complete binary tree: a binary tree in which all levels are completely filled except possibly for the last level, which is filled from left to right.

//perfect binary tree: a binary tree in which all internal nodes have exactly two children and all leaf nodes are at the same level.
//Every node in a perfect binary tree has either zero or two children. This means that every internal node (non-leaf node) has exactly two children and all leaf nodes are at the same level.

//balanced binary tree: a binary tree in which the height of the left and right subtrees of any node differ by at most 1.
//in balanced binary  tree,the height of the tree should be log2 N maximum where N is the number of nodes in the tree.

//Degenerate Tree:
//A Degenerate Tree is a Binary Tree where the nodes are arranged in a single path leaning to the right or left. The tree resembles a linked list in its structure where each node points to the next node in a linear fashion.

//binary tree
//converting vector into tree
#include <iostream>
using namespace std;

struct node{
public:
    int data;
    node* left;
    node* right;

    node(int data1,node* left1,node* right1){
        data=data1;
        left=left1;
        right=right1;
    }

    node(int data1){
        data=data1;
        left=right=nullptr;
    }


};
void tree(node* root,vector<int>arr){
    root->left=new node(arr[1]);
    root->right=new node(arr[2]);
    root->left->left=new node(arr[3]);
    root->left->right=new node(arr[4]);
    root->right->left=new node(arr[5]);
    root->right->right=new node(arr[6]);

}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    node* root=new node(arr[0]);
    tree(root,arr);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->left->right->data<<endl;
    cout<<root->right->left->data<<endl;
    cout<<root->right->right->data<<endl;
    return 0;

}

//traversal techniques
//1.depth first search
   ->1.inorder
    ->2.preorder
    ->3.postorder