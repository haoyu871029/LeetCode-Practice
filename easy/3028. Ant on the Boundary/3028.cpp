#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums);
};

int returnToBoundaryCount(vector<int>& nums) {
    int times = 0, current = 0;
    for (auto steps :nums){
        current += steps;
        if (current == 0){
            times++;
        }
    }
    return times;
}

int main() {
    vector<int> nums = {1, -1, 1, -1, 1, -1, 1, -1};
    Solution solution;
    cout << solution.returnToBoundaryCount(nums) << endl; //expect 4
    return 0;
}

//compile command: g++ -std=c++11 3028.cpp -o 3028
//run command: ./3028
//git add . && git commit -m "update 3028" && git push origin main            