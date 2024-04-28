#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums);
        int minJump(vector<int>& nums);
};

bool Solution::canJump(vector<int> &nums){
    int n = nums.size();
    int maxReach = 0; //目前最遠可以跳到 index ?
    bool result = false;
    for (int i=0; i<n; i++){
        if (i > maxReach){
            result = false; 
        }
        /* 能到這邊代表目前這裡還在射程範圍內 */
        maxReach = max(maxReach, i+nums[i]); //maxReach 是否應更新
        if (maxReach >= n-1){
            result = true; 
        }
    }
    return result;
}

int Solution::minJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;
    int end = 0;
    int min_jumps = 0;
    for (int i=0; i<n-1; i++){
        maxReach = max(maxReach, i+nums[i]); //maxReach 每圈都會試著更新
        if (i == end){
            end = maxReach;
            min_jumps++;
        }
    }
    return min_jumps;
}

int main(){
    Solution sol;
    vector<int> n1 = {2,3,1,1,4};
    
    if (sol.canJump(n1) == true){
        cout << "Test case can reach the end.\n";
        cout << "Minimum number of jumps to reach the end: " << sol.minJump(n1) << endl;
    }
    else {
        cout << "Test case can't reach the end.\n";
    }

    return 0;
}

//Compile: g++ -std=c++11 jump_game.cpp -o jg
//Run: ./jg