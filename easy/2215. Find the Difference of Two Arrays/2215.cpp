#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);
};

vector<vector<int>> Solution::findDifference(vector<int>& nums1, vector<int>& nums2) {
    /* Convert the vectors to unordered sets */
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<vector<int>> answer(2);
    /* Find the numbers that are in nums1 but not in nums2 */
    for (auto num: set1) {
        if (set2.find(num) == set2.end()) {
            answer[0].push_back(num);
        }
    }
    /* Find the numbers that are in nums1 but not in nums2 */
    for (auto num: set2) {
        if (set1.find(num) == set1.end()) {
            answer[1].push_back(num);
        }
    }
    return answer;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 4, 6};
    Solution obj;
    vector<vector<int>> answer = obj.findDifference(nums1, nums2);
    for (auto nums: answer) {
        for (auto num: nums) {
            cout << num << " ";
        }
        cout << endl;
    }//expected output: 5 6
}

//Compile command: g++ -std=c++11 2215.cpp -o 2215
//Run command: ./2215