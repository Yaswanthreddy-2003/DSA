//breadth first search
//    ->level order traversal
//traverses level by level rather than going deep into the tree.
//eg;
/*    1
     / \
//   2   3
//  / \   \
// 4   5   6*/
//it will gothrough 1sst level 1 then 2,3 then 4,5,6 left to right
//output : 1 2 3 4 5 6

//code
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data1,TreeNode* left1,TreeNode* right1){
        data=data1;
        left=left1;
        right=right1;
    }
    TreeNode(int data1){
        data=data1;
        left=right=nullptr;
    }
};
void levelorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left!=nullptr){
            q.push(node->left);
        }
        if(node->right!=nullptr){
            q.push(node->right);
        }

    }
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    TreeNode* root=new TreeNode(arr[0]);
    root->left=new TreeNode(arr[1]);
    root->right=new TreeNode(arr[2]);
    root->left->left=new TreeNode(arr[3]);
    root->left->right=new TreeNode(arr[4]);
    root->right->left=new TreeNode(arr[5]);
    root->right->right=new TreeNode(arr[6]);
    levelorder(root);
    return 0;
}

//dry run

/*root=1
q={1}
node->1
q={}
cout<<1
q={2,3}

node->2
q={3};
cout<<2
q={3,4,5}

node->3
q={4,5}
cout<<3
q={4,5,6,7}

node->4
q={5,6,7}
cout<<4 
q={5,6,7}   

node->5
q={6,7}
cout<<5
q={6,7}

node->6
q={7}
cout<<6
q={7}

node->7
q={}
cout<<7
q={}
//output: 1 2 3 4 5 6 7*/

//leetcode 102
//level order traversal
/*   1
   / \
  2   3
 / \   /\
4   5  6 7 */
//output: [[1],[2,3],[4,5,6]]

vector<vector<int>>levelorder(TreeNode* root){
    vector<vector<int>>ans;
    if(root==nullptr){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        for(int i=0;i<q.size();i++){
            TreeNode* node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    //......
    vector<vector<int>>ans=levelorder(root);
    for(auto i: ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

//dry run
/*root=1
q={1}
level={1}
q={}
ans={{1}}  
q={2,3}

node->2
q={3};
level={2}
q={3,4,5}
ans={{1},{2}}

node->3
q={4,5}
level={3}
q={4,5,6,7}
ans={{1},{2},{3}}

node->4
q={5,6,7}
level={4}
q={5,6,7}
ans={{1},{2},{3},{4}}

node->5
q={6,7}
level={5}
q={6,7}
ans={{1},{2},{3},{4},{5}}

node->6
q={7}
level={6}
q={7}
ans={{1},{2},{3},{4},{5},{6}}

node->7
q={}
level={7}
q={}
ans={{1},{2},{3},{4},{5},{6},{7}}

//output: [[1],[2,3],[4,5,6]]*/