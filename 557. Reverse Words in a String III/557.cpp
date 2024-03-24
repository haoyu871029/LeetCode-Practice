#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords_1(string s) {
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
        /* last word in sentence */
        int n = stk.size();
        for (int i=0; i<n; i++){
            result += stk.top();
            stk.pop();
        }
        return result;
    }// 20ms/12.30MB
    string reverseWords_2(string s) {
        int lastSpace = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                reverse(s.begin()+lastSpace, s.begin()+i);
                lastSpace = i+1;
            }
        }
        reverse(s.begin()+lastSpace, s.end());
        return s;
    }// 12ms/11MB
};

int main(){
    string s = "Let's take LeetCode contest";
    Solution sol;
    cout << sol.reverseWords_2(s) << endl;
    return 0;
}

//compile: g++ 557.cpp -o 557 -std=c++11
//execute: ./557