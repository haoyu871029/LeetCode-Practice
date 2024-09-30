#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x);
};

bool Solution::isPalindrome(int x) {
    /* Edge case */
    if (x < 0){
        return false;
    }
    /* Convert x to deque */
    deque<int> dq;
    while (x != 0){
        dq.push_back(x%10);
        x /= 10;
    }
    /* Check if x is palindrome */
    while (dq.size() > 1){
        if (dq.front() != dq.back()){
            return false;
        }
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}

int main(){
    Solution sol;
    int x = 121;
    cout << sol.isPalindrome(x) << endl; //expect: 1
    return 0;
}

//Compile command: g++ -std=c++11 9.cpp -o 9
//Run command: ./9