#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost);
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost);
};

int Solution::canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    /* 先留下有效起點（油量大於等於消耗的站） */
    int n = gas.size();
    vector<int> val_gas_index;
    for (int i=0; i<n; i++){
        if (gas[i] >= cost[i] && gas[i] != 0){
            val_gas_index.push_back(i);
        }
    }
    if (val_gas_index.size() == 0){
        return -1;
    }
    /* 每個有效起點都去試試看 */
    for (auto index: val_gas_index){//還要記得判斷是否已經繞一圈
        int i = index;
        int pass = 0;
        int car_gas = 0;
        bool check = true;
        while (pass < n){
            car_gas += gas[i];
            if (cost[i] > car_gas){//判斷下一站是否到的了
                check = false;
                break;
            }
            car_gas -= cost[i]; //經過這一站剩下多少油
            pass++;
            i = (i+1)%n; //i的累加記得考慮路線是圓形
        }
        if (check == true){
            return index;
        }
    }
    return -1;
}

int Solution::canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    /* 若total_gas<total_cost，不可能繞得完一圈 */
    int n = gas.size();
    int total_gas = 0,total_cost = 0;
    for (int i=0; i<n; i++){
        total_gas += gas[i];
        total_cost += cost[i];
    }
    if (total_gas < total_cost)
        return -1;
    //若total_gas>total_cost，代表一定找得到起始站並能繞完一圈。
    /* 遍歷一圈即可處理 */
    int curr_gas = 0, starting_point = 0;
    for (int i=0; i<n; i++){
        curr_gas += gas[i]-cost[i]; //在這站加油開到下一站後會剩下多少油
        if (curr_gas < 0) {//代表上一個起點到目前這站之間的任何一站都不可能是起點
            starting_point = i+1; //考慮新的起點
            curr_gas = 0;
        }
    }
    return starting_point;     
}

int main(){
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << sol.canCompleteCircuit1(gas, cost) << endl;
    cout << sol.canCompleteCircuit2(gas, cost) << endl;

    return 0;
}

//Compile: g++ -std=c++11 134.cpp -o 134
//Run: ./134