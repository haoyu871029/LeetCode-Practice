#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
    public:
        int missingNumber1(vector<int>& nums);
        int missingNumber2(vector<int>& nums);
        int missingNumber3(vector<int>& nums);
};

int Solution::missingNumber1(vector<int>& nums) {//version 1
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i=0; i<n; i++){
        if (i != nums[i]){
            return i;
        }
    }
    return n;
}

int Solution::missingNumber2(vector<int>& nums) {//version 2
    unordered_map<int,int> mp;
    int n = nums.size();
    for (int i=0; i<n; i++){
        mp[nums[i]] = i;
    }        
    for (int i=0; i<=n; i++){
        if (mp.find(i) == mp.end())
            return i;
    }
    return -1;
}

int Solution::missingNumber3(vector<int>& nums) {//version 3
    int x = 0;
    int n = nums.size();
    for(int l :nums){
        x ^= l; //XOR: 相等為0 相異為1
    }
    for(int i=0; i<=n; i++){
        x ^= i;
    }
    return x;
}

int main(){
    Solution sol;
    vector<int> nums = {3,0,1};
    cout << sol.missingNumber3(nums) << endl;

    return 0;
}

//Compile: g++ -std=c++11 268.cpp -o 268
//Run: ./268
