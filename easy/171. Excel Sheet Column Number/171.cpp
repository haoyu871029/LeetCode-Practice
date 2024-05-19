#include <string>
#include <iostream>
#include <cmath> //support pow()
using namespace std;

class Solution {
    public:
        int titleToNumber1(string columnTitle);
        int titleToNumber2(string columnTitle);
};

int  Solution::titleToNumber1(string columnTitle) {
    int n = columnTitle.size();
    int index = 0;
    int result = 0;
    for (int i=n-1; i>=0; i--){
        result += (pow(26,i) * (columnTitle[index]-'A'+1));
        index++;
    }
    return result;
}

int Solution::titleToNumber2(string columnTitle) {
    int result = 0;
    for (char c :columnTitle){
        result = (result*26) + (c-'A'+1);
    }
    return result;
}

int main(){
    Solution sol;
    string columnTitle = "AB";
    cout << sol.titleToNumber1(columnTitle) << endl;
    cout << sol.titleToNumber2(columnTitle) << endl;
    return 0;
}

//Compile: g++ -std=c++11 171.cpp -o 171
//Run: ./171