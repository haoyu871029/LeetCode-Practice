#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs1(int n);
    int climbStairs2(int n);
};

int Solution::climbStairs1(int n) {
    vector<int> dp(n+1);
    for (int i=0; i<=2; i++){
        dp[i] = i;
    }
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int Solution::climbStairs2(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs2(n-1) + climbStairs2(n-2);
}

int main(){
    Solution s;
    cout << s.climbStairs1(3) << endl;
    cout << s.climbStairs2(3) << endl;
    return 0;
}

//Compile: g++ -std=c++11 70.cpp -o 70
//Run: ./70