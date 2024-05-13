#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s);
};

bool Solution::isValid(string s) {
    stack<char> stk;
    unordered_map<char,char> mp = {{')','('}, {']','['}, {'}','{'}};
    for (char c :s){
        if (mp.find(c) == mp.end()){//c 為 open bracket 時，即 '(' 或 '[' 或 '{'
            stk.push(c);
        }
        else{//c 為 close bracket 時，即 ')' 或 ']' 或 '}'
            if (stk.empty())
                return false; //可以用來檢查是否違反規則 3，ex. s = "]" 或 "[()]}"
            if (stk.top() != mp[c])
                return false; //可以用來檢查是否違反規則 2，ex. s = "[(){]]"
            //到這邊代表 stack 非空而且有對應到
            stk.pop(); 
        }
    }
    return stk.empty(); //可以用來檢查是否違反規則 1，若 false 代表有多的 open bracket，ex. s = "[()]{"
}

int main(){
    Solution sol;
    string s = "()";
    cout << sol.isValid(s) << endl; //1
    s = "()[]{}";
    cout << sol.isValid(s) << endl; //1
    s = "(]";
    cout << sol.isValid(s) << endl; //0
    s = "([)]";
    cout << sol.isValid(s) << endl; //0
    s = "{[]}";
    cout << sol.isValid(s) << endl; //1
    return 0;

}

//Compile: g++ -std=c++11 20.cpp -o 20
//Run: ./20