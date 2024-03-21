#include <iostream>
#include <vector>
#include <algorithm> //support max_element, remove, erase
using namespace std;

class Solution {
public:
    int thirdMax_1(vector<int>& nums) {
        auto max_iter = max_element(nums.begin(), nums.end());
        int max_num = *max_iter;
        int third_num;
        for (int i=0; i<3; i++){
            if (nums.empty()){
                return max_num;
            }
            third_num = *(max_element(nums.begin(), nums.end()));
            auto itr = remove(nums.begin(), nums.end(), third_num);
            nums.erase(itr, nums.end());
        }
        return third_num;
    }// 3ms/11.4MB
    int thirdMax_2(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int distinctCount = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                distinctCount++;
                if (distinctCount == 3) {
                    return nums[i];
                }
            }
        }
        return nums[0];
    }// 4ms/11.5MB
};

int main() {
    Solution sol;
    vector<int> nums = {2,2,3,1};
    cout << sol.thirdMax_2(nums) << endl;
    return 0;
}

//compile: g++ -std=c++11 414.cpp -o 414
//execute: ./414