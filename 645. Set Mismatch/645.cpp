#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums_1(vector<int>& nums) {
        vector<int> result(2); //初始化一個大小為 2 的 vector
        int l = nums.size();
        vector<int> record(l,0); //將 vector 內的 l 個元素初始化為 0
        for (auto &n :nums){
            record[n-1]++;
        } //for loop結束後，缺少數紀錄值為0，多餘數紀錄值為2，其餘數紀錄值為1
        for (int i=0; i<l; i++){ //因為body需要index
            if (record[i] == 2){
                result[0] = i+1;
            }
            else if (record[i] == 0){
                result[1] = i+1;
            }
        }
        return result;
    } //about 20ms
    vector<int> findErrorNums_2(vector<int>& nums) {
        vector<int> result(2);
        map<int,int> mp;
        int l = nums.size();
        for (int i=1; i<=l; i++){
            mp[i] = 0;
        }
        for (auto &n :nums){
            mp[n]++;
        }
        for (int i=1; i<=l; i++){
            if (mp[i] == 2)
                result[0] = i;
            else if (mp[i] == 0)
                result[1] = i;
        }
        return result;
    } //about 100ms
};

int main(){
    Solution sol;
    vector<int> input{1,2,2,4};
    vector<int> result = sol.findErrorNums_1(input);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

//compile: g++ -std=c++11 645.cpp -o 645
//execute: ./645