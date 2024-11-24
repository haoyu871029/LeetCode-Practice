#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root);
};

TreeNode* Solution::invertTree(TreeNode* root) {
    if (root == nullptr){
        return nullptr;
    }
    if (root->left){
        invertTree(root->left);
    }
    if (root->right){
        invertTree(root->right);
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

void printTree(TreeNode* root);
int main(){
    /* Build a tree */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    /* Invert the tree by inorder traversal */
    Solution s;
    TreeNode* result = s.invertTree(root);
    printTree(result);
    return 0;
}

void printTree(TreeNode* root){
    if (root == nullptr){
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

//Compile: g++ -std=c++11 226.cpp -o 226
//Run: ./226