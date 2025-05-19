/*1. Pass-by-Value (vector<int> arr)
If you write:

void inorder(Node* root, vector<int> arr) { ... }
A copy of the vector is created every time this function is called.
Any modifications (like arr.push_back(root->data)) happen on the copied vector, not the original one.
When the function returns, all changes made inside inorder() are lost.
This results in an empty vector in inOrder().


2. Pass-by-Reference (vector<int> &arr)
If you write:

void inorder(Node* root, vector<int> &arr) { ... }
The function works on the original vector (passed from inOrder()).
Any changes (like arr.push_back(root->data)) modify the same vector in memory.
The final vector contains all elements from the inorder traversal.
Conclusion
Using pass-by-reference (&) avoids unnecessary copying and ensures the traversal values are correctly stored in the original vector.*/

//substring
//string s="hello world";
//string s1=s.substr(0,5); //hello
//string s2=s.substr(6,5); //world

