#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct TreeNode {//Definition for a binary tree node.
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp) {
    if (preStart>preEnd || inStart>inEnd) 
        return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int root_pos = mp[root->val]; //root_pos means the position of the root node in the inorder array
    int left_num = root_pos-inStart; //left_num means the number of nodes in the left subtree

    root->left = constructTree(preorder, preStart+1, preStart+left_num, inorder, inStart, root_pos-1, mp);
    root->right = constructTree(preorder, preStart+left_num+1, preEnd, inorder, root_pos+1, inEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preStart = 0, preEnd = preorder.size()-1;
    int inStart = 0, inEnd = inorder.size()-1;

    map<int,int> mp;
    for (int i=inStart; i<=inEnd; i++)
        mp[inorder[i]] = i;  //{{9,0}, {3,1}, {15,2}, {20,3}, {7,4}}

    return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}

int postorder(TreeNode* root){
    if (root == NULL)
        return 0;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
    return 1;
}

int main(){

    /* build a binary tree
            3
           / \
          9  20
            /  \
           15   7
    */
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);

    /* test: postorder traversal */
    postorder(root);

    return 0;
}

//Compile: g++ -std=c++11 105.cpp -o 105
//Run: ./105