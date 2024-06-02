#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    int hammingWeight(int n);
};

int Solution::hammingWeight(int n) {
    int num = 0;
    while (n != 0){
        if (n%2 == 1){
            num++;
        }
        n >>= 1; //位元右移運算符
    }
    return num;
}

int main(){
    Solution sol;
    int n = 11;
    cout << sol.hammingWeight(n) << endl;
    return 0;
}

//Compile: g++ -std=c++11 191.cpp -o 191
//Run: ./191