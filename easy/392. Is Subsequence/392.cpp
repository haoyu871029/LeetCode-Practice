#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence1(string s, string t);
    bool isSubsequence2(string s, string t);
};

bool Solution::isSubsequence1(string s, string t) {
    /* 可以提前判斷的情況 */
    int s_num = s.size();
    int t_num = t.size();
    if (s == t) return true;
    else if (s == "") return true;
    else if (s_num > t_num) return false;
    else if ((s_num == t_num) && (s != t)) return false;
    /* 需要透過迴圈遍歷來處理 */
    int k = 0;
    for (int i=0; i<t_num; i++){
        if (t[i] == s[k]){
            k++;
        }
        if (k == s_num){
            return true;
        }
    }
    return false;
}

bool Solution::isSubsequence2(std::string s, std::string t) {
    int s_num = s.size(), t_num = t.size();
    int i = 0, j = 0;
    while (i < s_num && j < t_num) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s_num;
}

int main(){
    Solution sol;
    cout << sol.isSubsequence1("abc", "ahbgdc") << endl; //1
    cout << sol.isSubsequence1("axc", "ahbgdc") << endl; //0
    cout << sol.isSubsequence2("abc", "ahbgdc") << endl; //1
    cout << sol.isSubsequence2("axc", "ahbgdc") << endl; //0

    return 0;
}

//Compile: g++ -std=c++11 392.cpp -o 392
//Run: ./392