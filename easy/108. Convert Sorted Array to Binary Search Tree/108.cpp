#include <vector>
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

TreeNode* build(vector<int>& nums,int left, int right){
    if(left > right)
        return NULL;
    int mid = (left+right)/2;
    TreeNode* NewNode = new TreeNode(nums[mid]);
    NewNode->left = build(nums, left, mid-1);
    NewNode->right = build(nums, mid+1, right);
    return NewNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    int end = nums.size()-1;
    return build(nums,0,end);
}

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = sortedArrayToBST(nums);

    return 0;
}

//Compile: g++ -std=c++11 108.cpp -o 108
//Run: ./108