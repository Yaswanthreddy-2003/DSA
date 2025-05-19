/**     1
    /   \
    2     3
    / \   / \
    4   5 6   7

zig zag traversal: [[1],[3,2],[4,5,6,7]]
1st levl left->right, next level right->left and it continues.*/

//this question is similar to level order traversal, the only difference is that we need to reverse the elements of the even levels.
//for that we took a boolean variable, if it is true we push the elements from left to right and if it is false we push the elements from right to left.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data1,Node* left1,Node* right1){
        data=data1;
        left=left1;
        right=right1;
    }
    Node(int data1){
        data=data1;
        left=right=nullptr;
    }
}
vector<vector<int>>zigzag(Node* root){
    vector<vector<int>>ans;
    if(root==nullptr){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>v(size);//vector of size size
        for(int i=0;i<size;i++){
            Node* curr=q.front();
            q.pop();
            if(lefttoright){
                v[i]=curr->data;
            }
            else{
                v[size-i-1]=curr->data;
            }
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
        }
        ans.push_back(v);
        lefttoright=!lefttoright;
    }
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
    vector<vector<int>>res=zigzag(root);
    for(auto x:res){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//time complexity is O(n) where n is the number of nodes in the tree.
//space complexity is O(n) where n is the number of nodes in the tree.

output:
[[1],[3,2],[4,5,6,7]]

/
