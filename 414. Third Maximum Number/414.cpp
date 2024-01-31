#include <iostream>
#include <vector>
#include <algorithm> //support max_element
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max_num = *(max_element(nums.begin(), nums.end()));
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
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,2,3,1};
    cout << sol.thirdMax(nums) << endl;
    return 0;
}

//compile: g++ -std=c++11 414.cpp -o 414
//execute: ./414