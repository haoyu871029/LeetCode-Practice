#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int majorityElement1(vector<int>& nums);
        int majorityElement2(vector<int>& nums);
};

int Solution::majorityElement1(vector<int>& nums) {
    unordered_map<int,int> mp;
    int n = nums.size();
    for (int i=0; i<n; i++){
        if (mp.find(nums[i]) == mp.end()) 
            mp[nums[i]] = 1;
        else
            mp[nums[i]]++;
    }
    for (auto &pair :mp){//遍歷map的方式
        if (pair.second > n/2){
            return pair.first;
        }
    }
    return -1; //沒有找到 majority element
}

int Solution::majorityElement2(vector<int>& nums) {
    int n = nums.size();
    int leader = nums[0];
    int count = 0;
    for (int i=0; i<n; i++){
        if (count == 0){
            leader = nums[i];
        }
        count += (nums[i]==leader)? 1 : -1;
    }
    return leader;
}

int main(){
    Solution sol;
    vector<int> nums = {2,1,3,1,4};
    cout << sol.majorityElement1(nums) << endl;
    cout << sol.majorityElement2(nums) << endl;
    return 0;
}

//Compile: g++ -std=c++11 169.cpp -o 169
//Run: ./169