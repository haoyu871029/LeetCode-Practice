#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums);
};

int jump(vector<int>& nums) {
    int n = nums.size();
    int min_jumps = 0;
    int end = 0;
    int maxReach = 0;
    for (int i=0; i<n-1; i++){
    //為什麼只需要跑 0~(n-2)？因為一定跳得到終點
    //跳到終點的那一步一定已經在 min_jumps++ 過了
        maxReach = max(maxReach, i+nums[i]); //maxReach 每圈都會試著更新
        if (i == end){
            end = maxReach;
            min_jumps++;
            //就算在 end 前有幾個數字可以跳到比 end 更遠，但至少還是需要一跳對吧
            //因為上一跳到的到 i，代表一定也到的了 i 之前的某一個
            //所以只是趁到 end 的這個機會把下一個 end 和跳躍次數更新一下
            //下一個 end 就是上一個 end 到這一個 end 之間，跑完更新好的 maxReach
        }
    }
    return min_jumps;
}

int main(){
    Solution sol;
    vector<int> n1 = {2,3,1,1,4};
    cout << sol.jump(n1) << endl; //2
    return 0;
}

//Compile: g++ -std=c++11 45.cpp -o 45
//Run: ./45