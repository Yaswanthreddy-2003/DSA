//find the diameter of binary tree
eg:                                     1
                                      /   \
                                     2     3
                                    / \   / \
                                  4   5 6   7
                                 / \
                                8   9
//diameter of the tree is 6. (8-4-2-1-3-7-9) 1+number of edges in the path.

//here we need to consider height of each subtree and then check the maximum of the sum of the heights of the left and right subtree.
//diameter is the sum of the heights of the left and right subtree.
//for evry node, diameter changes. so we need to update the diameter for every node.

int maxdiameter(Node* root){
    int diameter=0;
    height(root,diameter);
    return diameter;
}
int height(Node* root, int &diameter){
    if(node==nullptr){
        return 0;
    }
    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}

     