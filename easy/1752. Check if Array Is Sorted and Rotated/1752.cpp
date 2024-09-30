#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums);
};

bool Solution::check(vector<int>& nums) {
    /* Find the max number */
    int max_num = 0;
    int max_idx;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] > max_num){
            max_num = nums[i];
            max_idx = i;
        }
    }
    /* The first half of the array must be in non-decreasing order */ 
    for (int i=0; i<max_idx; i++){
        if (nums[i] > nums[i+1]){
            return false;
        }
    }
    /* Determine the starting index of the second half of the array */
    int k = max_idx+1;
    for (int i=max_idx+1; i<nums.size(); i++){
        if (nums[i] < nums[max_idx]){
            k = i;
            break;
        }
    }
    /* The second half of the array must be in non-decreasing order */
    for (int i=k; i<nums.size(); i++){
        if (nums[i] > nums[0]){
            return false;                
        }
        if ((i+1 < nums.size()) && (nums[i] > nums[i+1])){
            return false;
        }
    }
    return true;        
}

int main(){
    Solution s;
    vector<int> nums = {3,4,5,1,2};
    cout << s.check(nums) << endl; //expected output: true
    return 0;
}

//Compile command: g++ -std=c++11 1752.cpp -o 1752
//Run command: ./1752