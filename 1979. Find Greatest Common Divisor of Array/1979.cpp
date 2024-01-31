#include <iostream>
#include <vector>
#include <algorithm> //support minmax_element
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto result = minmax_element(nums.begin(), nums.end());
        int min_num = *(result.first);
        int max_num = *(result.second);
        if (max_num%min_num == 0){
            return min_num;
        }
        /* Euclidean Algorithm */
        int a = max_num;
        int b = min_num;
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
    cout << sol.findGCD(nums) << endl;
    return 0;
}

//compile: g++ -std=c++11 1979.cpp -o 1979
//execute: ./1979