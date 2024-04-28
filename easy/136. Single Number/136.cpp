#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int singleNumber1(vector<int>& nums);
    int singleNumber2(vector<int>& nums);
};

int Solution::singleNumber1(vector<int>& nums) {
    int n = nums.size();
    int result;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i+=2){
        if (i == n-1){//1,1,2,2,3,3,4
            result = nums[i];
        }
        else if (nums[i] != nums[i+1]){
            result = nums[i];
            break;
        }
    }
    return result;
}

int Solution::singleNumber2(vector<int>& nums) {
    int x = 0;
    int n = nums.size();
    for (int i=0; i<n; i++){
        x ^= nums[i];
    }
    return x;
}

int main(){
    Solution sol;
    vector<int> nums = {4,1,2,1,2};
    cout << sol.singleNumber1(nums) << endl;
    cout << sol.singleNumber2(nums) << endl;
    return 0;
}

//Compile: g++ -std=c++11 136.cpp -o 136
//Run: ./136