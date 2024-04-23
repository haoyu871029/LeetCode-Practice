#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes_1(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }// 10ms/21.6MB
    void moveZeroes_2(vector<int>& nums) {
        int zeros = 0, n = nums.size();
        for (auto &num :nums){
            if (num == 0){
                zeros++;
            }
        }
        int j = 0;
        for (int i=0; i<n; i++){
            if (nums[i] == 0){
                j++;
            }
            else{
                nums[i-j] = nums[i];
            }
        }
        for (int i=(n-zeros); i<n; i++){
            nums[i] = 0;
        }        
    }// 16ms/22MB
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,3,12};
    solution.moveZeroes_1(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

//cd "283. Move Zeroes"
//compile: g++ 283.cpp -o 283 -std=c++11
//execute: ./283