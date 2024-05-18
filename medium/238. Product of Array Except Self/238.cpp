#include <vector>
#include <iostream>
#include <numeric> //support partial_sum()
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n), suf(n), ans(n);
    /* Part 1 */
    partial_sum(nums.begin(), nums.end(), pre.begin(), multiplies<int>());
    partial_sum(nums.rbegin(), nums.rend(), suf.rbegin(), multiplies<int>()); //想像成反過來做，反過來放。
    /* Part 2 */
    for(int i=0; i<n; i++){
        /* 注意邊界元素 */
        int pre_i = ((i==0) ? 1 : pre[i-1]);
        int suf_i = ((i==n-1) ? 1 : suf[i+1]);
        ans[i] = pre_i * suf_i;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    //pre: {1, 2, 6, 24}
    //suf: {24, 24, 12, 4}
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;

}

//Compile: g++ -std=c++11 238.cpp -o 238
//Run: ./238