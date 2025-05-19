//height is same as maximum depth of the tree
// the height of leaf node is 0/-1 depending on the question
// height of root node is the height of the tree.

       1
      / \
      2  3
     / \ / \
    4  5  6  7
         /\
        8 9
// height of the tree is 3 if we consider the height of leaf node as 0. 
//if height of leaf node is 1 then height of the tree is 4.  

//height of node 3 is 3.

//code
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data1,Node* left1,Node* right1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
}

int maxdepth(Node* root){
    if(root==null){
        return 0;
    }

    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    return 1+max(lh,rh);

}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    Node* root=new Node(arr[0]);
    root->left=new Node(arr[1]);
    root->right=new Node(arr[2]);
    root->left->left=new Node(arr[3]);
    root->left->right=new Node(arr[4]);
    root->right->left=new Node(arr[5]);
    root->right->right=new Node(arr[6]);
    cout<<maxdepth(root);
    return 0;
}

//in tc,why is best case O(logn) and worst case O(n)?
//O(logn) is for balanced trees and O(n) is for skewed trees.

//in balanced tree, the height difference between left and right subtree is atmost 1.
//explanation:
//0 level - 1 node
//1 level - 2 nodes
//2 level - 4 nodes
//3 level - 8 nodes
//4 level - 16 nodes
 //.......
//h level - 2^h nodes

//total num of nodes n=2^0 +2^1+2^2+...+2^h . this is gp
//n=2^(h+1)-1 ~ n=2^(h+1)
//logn=h+1(log 2)
//h=logn-1
//h=logn
//since any operation search,insert,delete takes O(h) time in balanced trees
//O(h)=O(logn) for balanced trees

//for skewed trees, skewed trees are like linked lists
//so the height of the tree is n and the number of nodes is n.
//so the time complexity is O(n) for skewed trees.

//space complexity
//best case is O(logn) and worst case is O(n).


