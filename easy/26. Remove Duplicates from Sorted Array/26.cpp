#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums);
};

int Solution::removeDuplicates(vector<int>& nums) {
    int idx = 1;
    for (int i=1; i<nums.size(); i++){
        if (nums[i-1] < nums[i]){
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx;
}

int main(){
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int result = solution.removeDuplicates(nums);
    cout << result << endl; //expect 5
    return 0;
}

//Compile command: g++ -std=c++11 26.cpp -o 26
//Run command: ./26