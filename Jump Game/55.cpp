#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums);
};

bool Solution::canJump(vector<int> &nums){
    int n = nums.size();
    int maxReach = 0; //目前最遠可以跳到 index ?
    for (int i=0; i<n; i++){
        if (i > maxReach){
            return false; 
        }
        /* 能到這邊代表目前這裡還在射程範圍內 */
        maxReach = max(maxReach, i+nums[i]); //maxReach 是否應更新
        if (maxReach >= n-1){
            return true; 
        }
    }
    return true;  //應該不會到這裡才對
}

int main(){
    Solution sol;
    vector<int> n1 = {2,3,1,1,4};
    cout << sol.canJump(n1) << endl; //true

    vector<int> n2 = {3,2,1,0,4};
    cout << sol.canJump(n2) << endl; //false

    vector<int> n3 = {2,1,0,3,4};
    cout << sol.canJump(n3) << endl; //false

    return 0;
}

//Compile: g++ -std=c++11 55.cpp -o 55
//Run: ./55