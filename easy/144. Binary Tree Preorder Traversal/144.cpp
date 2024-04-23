#include <vector>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

struct TreeNode {//Definition for a binary tree node.
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr){
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->right != nullptr){
                s.push(node->right);
            }
            if (node->left != nullptr){
                s.push(node->left);
            }            
        }
        return result;
    }
};

int main(){
    /* Build a binary tree */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    /* Test */

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

//Compile: g++ -std=c++11 144.cpp -o 144
//Run: ./144