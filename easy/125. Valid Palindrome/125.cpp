#include <iostream>
#include <string>
#include <cmath> //support: round()
#include <cctype> //support: isalnum()
using namespace std;

class Solution {
    public:
        bool isPalindrome1(string s);
        bool isPalindrome2(string s);
};

bool Solution::isPalindrome1(string s) {
    /* 先對 s 做預處理：大寫轉小寫、去除 non-alphanumeric characters */
    string new_s = "";
    for (char c :s){
        if (c>=65 && c<=90){//c是大寫字母
            c = tolower(c);
            new_s += c;
        }
        else if (c>=97 && c<=122){//c是小寫字母
            new_s += c;
        }
        else if (c>=48 && c<=57){//c是數字
            new_s += c;
        }
    }
    /* 利用 for loop 去檢查 */
    int n = new_s.size();
    int end = new_s.size()-1;
    for (int i=0; i<round(n/2.0); i++){
        if (new_s[i] != new_s[end-i]){
            return false;
        }
    }
    return true;
}

bool Solution::isPalindrome2(string s) {
	int start = 0;
	int end = s.size()-1;
	while (start <= end){
        /* 若檢查到 non-alphanumeric characters，就跳過。 */
    	if (!isalnum(s[start])){
        	start++; 
            continue;
        }
    	if (!isalnum(s[end])){
        	end--;
            continue;
        }
        //會到這邊代表目前前後都有能比較的字元
        /* 檢查前後字元是否相同 */
    	if (tolower(s[start]) != tolower(s[end]))
        	return false;
    	else{//tolower(s[start]) == tolower(s[end])
        	start++;
        	end--;
    	}
	}
    //遍歷完成都沒有 return false，代表 s 是回文。
	return true;
}

int main(){
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome1(s) << endl; //expect: true
    cout << sol.isPalindrome2(s) << endl; //expect: true
    return 0;
}

//Compile: g++ -std=c++11 125.cpp -o 125
//Run: ./125