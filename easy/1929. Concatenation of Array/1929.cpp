#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getConcatenation_0(vector<int>& nums);
        vector<int> getConcatenation_1(vector<int>& nums);
};

vector<int> Solution::getConcatenation_0(vector<int>& nums) {
    vector<int> result(nums);
    result.insert(result.end(), result.begin(), result.end());
    return result;
}

vector<int> Solution::getConcatenation_1(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(2*n);
    for (int i=0; i<n; i++){
        result[i] = result[i+n] = nums[i];
    }
    return result;
}

int main(){
    Solution solution;
    vector<int> nums = {1, 2, 1};
    vector<int> result = solution.getConcatenation_1(nums);
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}

//Compile: g++ -std=c++11 1929.cpp -o 1929
//Execute: ./1929