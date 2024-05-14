#include <vector>
#include <iostream>
#include <climits> //support INT_MIN
#include <algorithm> //support max
using namespace std;

class Solution {
public:
    int maxProduct1(vector<int>& nums);
    int maxProduct2(vector<int>& nums);
};

int Solution::maxProduct1(vector<int>& nums){
    int maxi = INT_MIN;
    int n = nums.size();
    int prod = 1;
    for (int i=0; i<n; i++){
        prod *= nums[i];
        maxi = max(prod,maxi);
        if (prod == 0)
            prod = 1;
    }
    prod = 1;
    for (int i=n-1; i>=0; i--){
        prod *= nums[i];
        maxi = max(prod,maxi);
        if (prod == 0)
          prod = 1;
    }
    return maxi;
}

int Solution::maxProduct2(vector<int>& nums) {
    int n = nums.size();
    int curr_max = nums[0];
    int curr_min = nums[0];
    int ans = nums[0];
    cout << curr_max << " " << curr_min << " " << ans << endl;
    for (int i=1 ;i<n; i++){
        int temp_max = curr_max;
        curr_max = max(nums[i], max(temp_max*nums[i], curr_min*nums[i]));//有當前元素參與後的累積最大值
        curr_min = min(nums[i], min(temp_max*nums[i], curr_min*nums[i]));//有當前元素參與後的累積最小值
        ans = max(ans, curr_max);
        //cout << curr_max << " " << curr_min << " " << ans << endl;
    }
    return ans;
}

int main(){
    vector<int> nums = {2,3,-2,4};
    Solution sol;
    cout << sol.maxProduct1(nums) << endl; //expect 6
    nums = {2,3,-1,2,4,-1};
    cout << sol.maxProduct1(nums) << endl; //expect 48
    nums = {2,-5,-2,-4,3};
    cout << sol.maxProduct1(nums) << endl; //expect 24
    return 0;
}

//Compile: g++ -std=c++11 152.cpp -o 152
//Run: ./152