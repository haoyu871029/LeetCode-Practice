#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int start = 0, end = length-1, k;
        while (start <= end){
            k = (start+end)/2;
            if (nums[k] == target){
                return k;
            }
            else if (nums[k] > target){
                end = k-1;
            }
            else{//nums[k] < target)
                start = k+1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution sol;
    cout << sol.search(nums, target) << endl;
    return 0;
}

//Compile: g++ -std=c++11 704.cpp -o 704
//Execute: ./704