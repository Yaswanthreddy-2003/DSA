//iterative solution of postorder usinng 2 stcks.
 class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1,st2;
        vector<int>post;
        if(root==nullptr){
            return post;
        }
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=nullptr){
                st1.push(root->left);
            }
            if(root->right!=nullptr){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            post.push_back(st2.top()->val);
            st2.pop();
        }
        return post;
    }
};  
//simple idea:  there will be 2 stacks and elements from last stack will be pushed to vector post. 
//stack follows LIFO. last ele of stack will be pushed first to vector post.
//stack2 will be the reversal of the output. by knowing stack2 ,we can do the required operations to input and st1.

//using 1 stack
vector<int>postorder(TreeNode* root){
    stack<TreeNode*>st;
    vector<int>post;
    if(root==nullptr){
        return post;
    }
    st.push(root);
    while(!st.empty()){
        st.push(root);
        root=root->left;
        
    }
}