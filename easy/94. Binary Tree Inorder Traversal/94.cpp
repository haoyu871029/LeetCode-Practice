#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:
        void traversal(vector<int>& result, TreeNode* ptr);
    public:
        vector<int> inorderTraversal1(TreeNode* root);
        vector<int> inorderTraversal2(TreeNode* root);
};
    
void Solution::traversal(vector<int>& result, TreeNode* ptr){
    if (ptr == nullptr) return;
    traversal(result, ptr->left);
    result.push_back(ptr->val);
    traversal(result, ptr->right);
}
    
vector<int> Solution::inorderTraversal1(TreeNode* root) {
    vector<int> result;
    traversal(result, root);
    return result;
}

vector<int> Solution::inorderTraversal2(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;

    /* 回收左子樹 inorder traversal 的 result vector */
    vector<int> left = inorderTraversal2(root->left);
    result.insert(result.end(), left.begin(), left.end()); //將 left vector 中的所有元素添加到 result vector 的末端。
    
    result.push_back(root->val);
    
    /* 回收右子樹 inorder traversal 的 result vector */
    vector<int> right = inorderTraversal2(root->right);
    result.insert(result.end(), right.begin(), right.end()); //將 right vector 中的所有元素添加到 result vector 的末端。
    
    return result;
}

int main(){
    /* Build a binary tree */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    /* Test: Inorder traversal */
    Solution sol;
    vector<int> result = sol.inorderTraversal2(root);
    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }//expect: 1 3 2
    cout << endl;
    return 0;

}

//Compile: g++ -std=c++11 94.cpp -o 94
//Run: ./94