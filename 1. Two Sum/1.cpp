#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; //用一個 map 去存每個沒找到夥伴的人
        vector<int> result;
        for (int i=0; i<nums.size(); i++){
            int partner = target - nums[i];
            /* 每次都回去這個 map 找夥伴 */
            if (m.find(partner) != m.end()){//return "iterator"
                result.push_back(m[partner]);
                result.push_back(i);
                break;
            }
            else{//沒找到就把自己存進去，等別人來找。
                m[nums[i]] = i;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = s.twoSum(nums, 9);

    cout << "result:";
    for (int i=0; i<result.size(); i++){
        cout << " " << result[i];
    }
    cout << endl;

    return 0;
}

//compile: g++ -std=c++11 1.cpp -o 1
//execute: ./1