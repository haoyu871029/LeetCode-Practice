#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        stack<char> stk;
        for (auto &c :s){
            if (c != ' '){
                stk.push(c);
            }
            else{
                int n = stk.size();
                for (int i=0; i<n; i++){
                    result += stk.top();
                    stk.pop();
                }
                result += ' ';
            }
        }
        int n = stk.size();
        for (int i=0; i<n; i++){
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};

int main(){
    string s = "Let's take LeetCode contest";
    Solution sol;
    cout << sol.reverseWords(s) << endl;
    return 0;
}

//compile: g++ 557.cpp -o 557 -std=c++11
//execute: ./557