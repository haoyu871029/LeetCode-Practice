#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool containsDuplicate1(vector<int>& nums);
        bool containsDuplicate2(vector<int>& nums);
};

bool Solution::containsDuplicate1(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for (int i=1; i<n; i++){
        if (nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;
}

bool Solution::containsDuplicate2(vector<int>& nums) {
    unordered_map<int,int> mp;
    for (auto num :nums){
        if (mp.find(num) == mp.end()){
            mp[num] = 1;
        }
        else{
            return true;
        }
    }
    return false;
}

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << sol.containsDuplicate1(nums) << endl;
    cout << sol.containsDuplicate2(nums) << endl;
    return 0;
}

//Compile: g++ -std=c++11 217.cpp -o 217
//Run: ./217