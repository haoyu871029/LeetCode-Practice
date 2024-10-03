#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

int Solution::maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp0(n), dp1(n);
    dp0[0] = dp1[0] = nums[0];
    for (int i=1; i<n; i++){
        dp1[i] = max(nums[i], nums[i] + dp1[i-1]);
        dp0[i] = max(dp0[i-1], dp1[i]);
    }
    return dp0.back();
}

int main() {
    Solution solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << solution.maxSubArray(nums) << endl; //expect 6
    return 0;
}

//Compile command: g++ -std=c++11 53.cpp -o 53 -std=c++11
//Run command: ./53