#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        int maxDepth(TreeNode* root);
};

int Solution::maxDepth(TreeNode* root){
    if(root == NULL)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l,r)+1;
}

int main(){
    /* Build a tree
     *      3
     *     / \
     *    9  20
     *       / \
     *      15  7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    /* Test */
    Solution sol;
    cout << sol.maxDepth(root) << endl; //expected: 3
    return 0;
}

//Compile: g++ -std=c++11 104.cpp -o 104
//Run: ./104