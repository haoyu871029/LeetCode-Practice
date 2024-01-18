#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        int l = nums.size();
        vector<int> record(l,0);
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
    }
};

int main(){
    Solution sol;
    vector<int> input{1,2,2,4};
    vector<int> result = sol.findErrorNums(input);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

//compile: g++ -std=c++11 645.cpp -o 645
//execute: ./645