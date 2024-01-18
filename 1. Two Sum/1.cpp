#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> temp; //{ {number,index}, ... }
    vector<int> result; //{ index, index }
    for (int i=0; i<nums.size(); i++){
        if (temp.find(target-nums[i]) != temp.end()){ //return "iterator"
            result.push_back(temp[target-nums[i]]); //"temp[target-nums[i]]" represents the index of the partner
            result.push_back(i); //"i" represents nums[i]'s own index
            return result;
        }
        else{
            temp[nums[i]] = i; //If a partner cannot be found, record it in the form of {number, index} in the 'temp'
        }
    }
    return result;
}

int main(){

    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = twoSum(nums, 9);

    cout << "result:";
    for (int i=0; i<result.size(); i++){
        cout << " " << result[i];
    }
    cout << endl;

    return 0;
}

//compile: g++ -std=c++11 1.cpp -o 1_cpp
//execute: ./1_cpp