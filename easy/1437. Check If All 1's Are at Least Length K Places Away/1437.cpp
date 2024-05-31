#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool kLengthApart1(vector<int>& nums, int k);
        bool kLengthApart2(vector<int>& nums, int k);
};
    
bool Solution::kLengthApart1(vector<int>& nums, int k) {
    int n = nums.size();
    int start;
    for (int i=0; i<n; i++){//找起始 1 的位置
        if (nums[i] == 1){
            start = i;
            break;
        }
    }
    int left = start;
    for (int i=start+1; i<n; i++){
        if (nums[i] == 1){
            if (i-left-1 < k) return false;
            left = i;
        }
    }
    return true;
}

bool Solution::kLengthApart2(vector<int>& nums, int k) {
    int left = -1;
    int pos; 
    int n = nums.size();
    for (int i=0; i<n; i++){
        if(nums[i] == 1){
            if ((i-left-1)<k && left!=-1){ 
                return false;
            }
            left = i; //初始 1 的位置也會在這裡被確定
        }
    }
    return true;
}

int main(){
    Solution s;
    vector<int> nums = {1,0,0,0,1,0,0,1};
    int k = 2;
    cout << s.kLengthApart1(nums, k) << endl; //expect 1
    return 0;
}

//Compile: g++ -std=c++11 1437.cpp -o 1437
//Run: ./1437