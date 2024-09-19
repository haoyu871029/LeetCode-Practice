#include <iostream>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
    public:
        int myAtoi(string s);
};

int Solution::myAtoi(string s) {
    /* Setting and Edge Case */
    bool neg = false; //是否為負數
    int n = s.size(); //字串長度
    int i = 0; //欲代表 II. 中的第一個非數字字元在整個字串中的位置
    int j = 0; //欲代表 II. 中的第一個字元在整個字串中的位置
    if (n == 0) {
        return 0;
    }

    /* Processing for I. */
    while (i < n && s[i] == ' ') {//迴圈會在出現非空白的時候結束
        i++; //i++ 是為了判斷下一個字元
    }//此時 i 為第一個非空白的字元在字串中的位置
    if (i < n && s[i] == '-') {
        i++;
        neg = true;
    } 
    else if (i < n && s[i] == '+') {
        i++;
    }
    while (i < n && s[i] == '0') {
        i++;
    }//此時 i 值代表 II. 中的第一個字元在整個字串中的位置

    /* Processing for II. */
    j = i; //確定 j 值，此時的 j 值代表 II. 中的第一個字元在整個字串中的位置
    for (; i < n; i++) {
        if (!isdigit(s[i])){
            break;
        }
    } //確定 i 值，此時的 i 值代表 II. 中第一個非數字字元在整個字串中的位置
    if (i == j) {//代表根本還沒經過迴圈的 i++ 就 break 了，也就是說 II. 的第一個字元就是非數字，或是 II. 為空字串
        return 0;
    }
    // i-j 代表 II. 中數字字串的長度
    if (i-j > 10) {//若有溢位發生則可提前結束的情況一
        //2,147,483,648 和 2,147,483,647 都是 10 位數
        return neg ? INT_MIN : INT_MAX;
    }
    if (i-j == 10) {//若有溢位發生則可提前結束的情況二
        if (neg){//比對數字字串和 "2147483648"
            string str = "2147483648";
            int k = 0;
            while (k < 10) {
                if (str[k] == s[j+k]){
                    k++;
                    if (k == 10) //意即數字字串代表的數字和 INT_MIN 相等 (雙方第0~9個字元都相同)
                        return INT_MIN;
                    continue;
                } 
                else if (s[j+k] > str[k]) //意即數字字串代表的數字比 INT_MIN 還小
                    return INT_MIN;
                else //意即數字字串代表的數字比 INT_MIN 還大
                    break;
            }
        } 
        else{
            string str = "2147483647";
            int k = 0;
            while (k < 10) {
                if (str[k] == s[j+k]){
                    k++;
                    if (k == 10)
                        return INT_MAX;
                    continue;
                } 
                else if (s[j+k] > str[k])
                    return INT_MAX; 
                else
                    break;
            }
        }
    }
    
    /* Convertion */
    string str = s.substr(j, i - j);
    int res = stoi(str);
    return neg ? -res : res;
}

int main() {
    Solution sol;
    cout << sol.myAtoi("42") << endl; //expect: 42
    cout << sol.myAtoi("   -42") << endl; //expect: -42
    cout << sol.myAtoi("4193 with words") << endl; //expect: 4193
    return 0;
}

//Compile: g++ -std=c++11 8.cpp -o 8
//Run: ./8