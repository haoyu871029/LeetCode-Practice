#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        /* Settings */

        int target = 0;
        vector<vector<int>> output;
        set<vector<int>> s;
        int j, k;

        /* Preprosscessing */

        sort(nums.begin(), nums.end()); //sort the array

        /* Main */

        for (int i = 0; i < nums.size(); i++){
            j = i + 1;
            k = nums.size() - 1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } 
                else if (sum < target){ j++; } 
                else{ k--; }
            }
        }

        /* Output */

        for(auto triplets :s)
            output.push_back(triplets);
        return output;     
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> output = s.threeSum(nums);

    for (int i = 0; i < output.size(); i++){
        for (int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}

//Compile: g++ -std=c++11 15.cpp -o 15
//Run: ./15