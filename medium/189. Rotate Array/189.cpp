#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
    public:
        void rotate1(vector<int>& nums, int k);
        void rotate2(vector<int>& nums, int k);
};

void Solution::rotate1(vector<int>& nums, int k) {
        //要注意的是要改動原本的 nums
        //用 insert() 來從左邊插入元素，但要先想辦法將該元素從尾巴去除。
    stack<int> stk;
    int n = nums.size();
    k = k % n; //還要考慮 k>n 的情況
    for (int i=(n-1); i>=0; i--){
        stk.push(nums[i]);
    }
    for (int i=k; i<n; i++){
        nums[i] = stk.top();
        stk.pop();
    }
    for (int i=0; i<k; i++){
        nums[i] = stk.top();
        stk.pop();            
    }
}

void Solution::rotate2(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> numcopy = nums;
    for(int i=0; i<n; i++) 
        nums[(i+k)%n] = numcopy[i];
}

int main(){
    /* Test */
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate1(nums, k);
    /* Print test result */
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

//Compile: g++ -std=c++11 189.cpp -o 189
//Run: ./189