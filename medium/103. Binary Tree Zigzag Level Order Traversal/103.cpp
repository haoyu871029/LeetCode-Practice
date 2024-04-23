#include <vector>
#include <iostream>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        /* Initialization */

        queue<TreeNode*> Q;
        int level = 0;
        Q.push(root);

        /* Processing */

        while (!Q.empty()) { //Q不為空
            size_t size = Q.size();
            vector<int> nodes(size);
            for (int i = 0; i < size; i++) {//遍歷 Q 來處理該層的節點
                /* Part 1 */
                TreeNode* curr = Q.front();
                Q.pop();
                int idx = (level%2==0) ? i : size-1-i; 
                nodes[idx] = curr->val; //將目前節點的值存入 nodes
                /* Part 2 */
                if (curr->left) Q.push(curr->left); //將目前節點的左子推入 Q
                if (curr->right) Q.push(curr->right); //將目前節點的右子推入 Q
            }
            result.push_back(nodes);
            level++;
        }
        return result;
    }
};

int main(){

    /* Build a tree */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    /* Test */

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    for (auto& nodes :result) {
        for (auto& val :nodes) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

//Compile: g++ -std=c++11 103.cpp -o 103
//Run: ./103