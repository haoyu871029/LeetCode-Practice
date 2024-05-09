#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n);
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n);
};

void Solution::merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n==0) return; //nums2 為空
    for (int i=m; i<m+n; i++){
        nums1[i] = nums2[i-m];
    }
    sort(nums1.begin(), nums1.end());
}

void Solution::merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n==0) return; //nums2 為空
    int end = (m+n)-1;
    while (n>0 && m>0){
        if (nums2[n-1] >= nums1[m-1]){
            nums1[end] = nums2[n-1];
            n--;
        }
        else {//nums2[n-1] < nums1[m-1]
            nums1[end] = nums1[m-1];
            m--;
        }
        end--;
    }
    while (n > 0){//nums2 還有剩
        nums1[end] = nums2[n-1];
        n--;
        end--;
    }
    //如果是 m>0，代表 nums1 有剩下，但因為預排序的關係，他們已經在正確的位置上了。
}

int main() {
    Solution solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    solution.merge2(nums1, 3, nums2, 3);
    for (int i=0; i<nums1.size(); i++){
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
//Compile: g++ -std=c++11 88.cpp -o 88
//Run: ./88