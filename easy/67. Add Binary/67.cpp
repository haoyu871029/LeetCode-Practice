#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        string addBinary1(string a, string b);
        string addBinary2(string a, string b);
};

string Solution::addBinary1(string a, string b) {
    /* 先幫位數少的那個補 0 */
    int n = a.size()>b.size() ? a.size()-b.size() : b.size()-a.size();
    if (a.size() > b.size()){
        for (int i=0; i<n; i++){
            b = "0" + b;
        }
    }
    else if (b.size() > a.size()){
        for (int i=0; i<n; i++){
            a = "0" + a;
        }
    }
    /* 進行二進位加法 */
    n = a.size(); //a.size() = b.size()
    int carry = 0;
    string ans = "";
    for (int i=n-1; i>=0; i--){
        if (a[i]=='1' && b[i]=='1'){//1+1
            ans = (carry?"1":"0") + ans;
            carry = 1;
        }
        else if (a[i]=='0' && b[i]=='0'){//0+0
            ans = (carry?"1":"0") + ans;
            carry = 0;
        }
        else{//1+0 or 0+1
            ans = (carry?"0":"1") + ans;
            carry = (carry?1:0);
        }
    }
    if (carry){
        ans = "1" + ans;
    }
    return ans;
}

string Solution::addBinary2(string a, string b) {
    string ans;
    int carry = 0;
    int value = 0;
    int i = a.size()-1;
    int j = b.size()-1;
    while (i>=0 || j>=0 || carry) {
        value += carry;
        if (i >= 0){
            value += (a[i] - '0'); //等號右邊會是 ASCII code 的運算
            i--;
        }
        if (j >= 0){
            value += (b[j] - '0'); //等號右邊會是 ASCII code 的運算
            j--;
        }
        ans += (value%2 + '0'); //等號右邊會是 ASCII code 的運算
        carry = value / 2;
        value = 0;
    }
    reverse(begin(ans), end(ans));
    return ans;
}

int main(){
    Solution sol;
    string a = "1010";
    string b = "1011";
    cout << sol.addBinary1(a, b) << endl; //expect: 10101
    cout << sol.addBinary2(a, b) << endl; //expect: 10101
    return 0;
}

//Compile: g++ -std=c++11 67.cpp -o 67
//Run: ./67