#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n);
};

uint32_t Solution::reverseBits(uint32_t n) {
    uint32_t x = 0;
    int d = 0;
    while(n>0) {
        x += (n%2) << (31-d);
        n >>= 1;
        d++;
    }
    return x;
}

int main(){
    Solution s;
    cout << s.reverseBits(43261596) << endl;
    return 0;
}

//Compile: g++ -std=c++11 190.cpp -o 190
//Run: ./190