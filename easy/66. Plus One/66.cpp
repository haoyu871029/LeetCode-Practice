#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
    public:
        vector<int> plusOne1(vector<int>& digits);
        vector<int> plusOne2(vector<int>& digits);
};

vector<int> Solution::plusOne1(vector<int>& digits) {
    int n = digits.size();
    for (int i=n-1; i>=0; i--){
        if (digits[i] == 9){
            digits[i] = 0;
        } 
        else {
            digits[i]++;
            return digits;
        }
    }
    digits.insert(digits.begin(), 1); //處理所有位都是 9 的情況
    return digits;
}

vector<int> Solution::plusOne2(vector<int>& digits) {
    int n = digits.size();
    vector<int> ans;;
    stack<int> stk;

    int carry = 1;
    int digit_value;
    for (int i=n-1; i>=0; i--){
        digit_value = carry + digits[i];
        stk.push(digit_value%10);
        carry = digit_value / 10;
    }
    if (carry == 1){
        stk.push(1);
    }

    while (!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main(){
    Solution sol;
    vector<int> digits = {1, 2, 3};
    vector<int> ans = sol.plusOne2(digits);
    /* Print the answer */
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

//Compile: g++ -std=c++11 66.cpp -o 66
//Run: ./66