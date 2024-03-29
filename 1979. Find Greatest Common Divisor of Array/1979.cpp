#include <iostream>
#include <vector>
#include <algorithm> //support minmax_element()
using namespace std;

class Solution {
public:
    int findGCD_1(vector<int>& nums) {
        /* find max & min */
        auto result = minmax_element(nums.begin(), nums.end());
        int min_num = *(result.first);
        int max_num = *(result.second);
        /* calculate GCD: Euclidean Algorithm */
        int a = max_num;
        int b = min_num;
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    int findGCD_2(vector<int>& nums){
        /* find max & min */
        int max = nums[0], min = nums[0];
        for (auto &num :nums){
            if (num > max)  max = num;
            else if (num < min)  min = num;
        }
        /* calculate GCD: Euclidean Algorithm */
        int a = max;
        int b = min;
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,6,9,10};
    cout << sol.findGCD_2(nums) << endl;
    return 0;
}

//compile: g++ -std=c++11 1979.cpp -o 1979
//execute: ./1979