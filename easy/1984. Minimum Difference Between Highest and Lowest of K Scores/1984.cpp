#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k);
};

int Solution::minimumDifference(vector<int>& nums, int k) {
    /* Edge case */
    int n = nums.size();
    if (n == 1){
        return 0;
    }
    /* Pre-sorting */
    sort(nums.begin(), nums.end());
    /* Processing */
    int min_dif = INT_MAX;
    for (int i=0; i<=(n-k); i++){
        int test_dif = nums[i+k-1]-nums[i];
        if (test_dif < min_dif){
            min_dif = test_dif;
        }
    }
    return min_dif;
}

int main() {
    Solution sol; 
    vector<int> nums = {9,4,1,7};
    int k = 2;
    cout << sol.minimumDifference(nums, k) << endl; //expected output is 2
    return 0;
}

//Compile command: g++ -std=c++11 1984.cpp -o 1984
//Run command: ./1984