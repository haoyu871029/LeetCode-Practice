#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    void reverseString1(vector<char>& s);
    void reverseString2(vector<char>& s);
};

void Solution::reverseString1(vector<char>& s) {
    int n = s.size();
    int mid = (n/2)-1;
    char temp;
    for (int i=0; i<=mid; i++){
        temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }
}

void Solution::reverseString2(vector<char>& s) {
    reverse(s.begin(), s.end());
}

int main(){
    Solution s;
    vector<char> str = {'h','e','l','l','o'};
    s.reverseString2(str);
    for (int i=0; i<str.size(); i++){
        cout << str[i] << " ";
    }
    cout << endl;
    return 0;

}

//Compile: g++ -std=c++11 344.cpp -o 344
//Run: ./344