#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        for (int k = i; k < n; k++) {
            nums[k] = 0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,3,12};
    solution.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

//cd "283. Move Zeroes"
//compile: g++ 283.cpp -o 283 -std=c++11
//execute: ./283