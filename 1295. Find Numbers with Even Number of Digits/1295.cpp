#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto &n :nums){
            int tmp = n;
            int digits = 0;
            while (tmp != 0){
                digits++;
                tmp /= 10;
            }
            //cout << digits << endl;
            if (digits%2 == 0){
                result++;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {12,345,2,6,7896};
    cout << s.findNumbers(nums) << endl;
    return 0;
}

// compile: g++ -std=c++11 1295.cpp -o 1295
// execute: ./1295