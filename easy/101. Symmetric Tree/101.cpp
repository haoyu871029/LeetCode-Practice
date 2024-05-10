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
    bool isMirror(TreeNode* left, TreeNode* right);
    bool isSymmetric(TreeNode* root);
};

bool Solution::isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    bool check1 = (left->val == right->val); //左子和右子的值是否相等
    bool check2 = isMirror(left->left, right->right); //「左子的左子樹」和「右子的右子樹」應該要是對稱的
    bool check3 = isMirror(left->right, right->left); //「左子的右子樹」和「右子的左子樹」應該要是對稱的
    return check1 && check2 && check3;
}

bool Solution::isSymmetric(TreeNode* root) {
    return isMirror(root->left, root->right);
}

int main(){
    /* Build a tree
    *      1
    *     / \
    *    2   2
    *   / \ / \
    *  3  4 4  3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    /* Test */
    Solution sol;
    cout << sol.isSymmetric(root) << endl;

    return 0;
}

//Compile: g++ -std=c++11 101.cpp -o 101
//Run: ./101