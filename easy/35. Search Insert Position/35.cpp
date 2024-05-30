#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int searchInsert1(vector<int>& nums, int target);
        int searchInsert2(vector<int>& nums, int target);
};

int Solution::searchInsert1(vector<int>& nums, int target) {
    int n = nums.size();
    if (target > nums[n-1]) return n; //target 大於目前 nums 中所有元素
    for (int i=0; i<n; i++){
        if (nums[i]==target || nums[i]>target){ 
            return i;
        }
    }
    return -1; //不會發生這個情況
}

int Solution::searchInsert2(vector<int>& nums, int target) {
    int n = nums.size();
    if (target > nums[n-1]) return n; //target 大於目前 nums 中所有元素
    int left=0, mid, right=n-1;
    while (left <= right){
        mid = (left+right)/2;
        if (nums[mid] == target) return mid;
        if (target > nums[mid])  left = mid+1;
        else right = mid-1;
    }
    return left;
}

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,5,6,7};
    int target = 4;
    cout << sol.searchInsert1(nums, target) << endl; //expect 3
    cout << sol.searchInsert2(nums, target) << endl; //expect 3
    return 0;

}

//Compile: g++ -std=c++11 35.cpp -o 35
//Run: ./35