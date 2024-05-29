#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPowerOfThree1(int n);
        bool isPowerOfThree2(int n);
};

bool Solution::isPowerOfThree1(int n) {
    if(n==0 || n<0) return false;
    if(n==1) return true;
    return n%3==0 && isPowerOfThree1(n/3);
}

bool Solution::isPowerOfThree2(int n) {
    if(n==0 || n<0) return false;
    while(n%3 == 0) n /= 3; 
    //if n is power of 3, then the loop will end with (1%3 == 1)
    return n==1;
}

int main(){
    Solution solution;
    int n = 27;
    cout << solution.isPowerOfThree1(n) << endl;
    cout << solution.isPowerOfThree2(n) << endl;
    return 0;
}

//Compile: g++ -std=c++11 326.cpp -o 326
//Run: ./326