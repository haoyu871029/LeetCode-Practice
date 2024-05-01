#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeElement(vector<int>& nums, int val);
};

int Solution::removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    if(n == 0) return 0;
    int k = 0;
    int curr_index = 0;
    for (int i=0; i<n; i++){
        if (nums[i] != val){
            nums[curr_index] = nums[i];
            curr_index++;
            k++;
        }
    }
    return k;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution sol;
    int k = sol.removeElement(nums, val);
    cout << k << endl;
    for (int i=0; i<k; i++){
        cout << nums[i] << " ";
    }
    return 0;
}

//Compile: g++ -std=c++11 27.cpp -o 27
//Run: ./27