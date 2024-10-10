#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    /* I */
    bool isPowerOfTwo_0(int n);
    bool isPowerOfTwo_1(int n);
    bool isPowerOfTwo_2(int n);
    /* II. related to bit manipulation */
    bool isPowerOfTwo_3(int n);
    bool isPowerOfTwo_4(int n);
};

bool Solution::isPowerOfTwo_0(int n) {
    for(int i=0; i<31; i++){
        if (pow(2,i) == n){//supported by <cmath>
            return true;
        }
    }
    return false;
}//O(1) O(1)

bool Solution::isPowerOfTwo_1(int n) {
    if (n == 0){
        return false;
    }
    while (n > 0){
        if (n == 1) {
            return true;
        }
        if (n%2 != 0){
            break;
        }
        n /= 2;
    }
    return false;
}//O(logn) O(1)

bool Solution::isPowerOfTwo_2(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    return (n%2==0 && isPowerOfTwo_2(n/2));
}//O(logn) O(logn)

bool Solution::isPowerOfTwo_3(int n) {
    if(n <= 0) return false;
    return ((1<<30) % n == 0) ? true : false;
}//O(1) O(1)

bool Solution::isPowerOfTwo_4(int n) {
    int x = 1;
    while(x <= n){
        if (x == n){
            return true;
        }
        if (x > INT_MAX/2){
            break;
        }
        x = x<<1;
    }
    return false;
}//O(logn) O(1)

int main(){
    Solution solution;
    int n = 16;
    bool result = solution.isPowerOfTwo_0(n);
    cout << "result: " << result << endl;
    return 0;
}

//compile command: g++ -std=c++11 231.cpp -o 231
//run command: ./231
//git add . && git commit -m "update 231" && git push origin main