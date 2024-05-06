#include <unordered_map>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern1(string pattern, string s);
    bool wordPattern2(string pattern, string s);
};

bool Solution::wordPattern1(string pattern, string s) {
    bool result;
    unordered_map<string,char> mp; 
    string s_pattern = "";
    istringstream iss(s); //supported by <sstream>
    string word;
    int i = 0;
    while (iss >> word){ 
        if (mp.find(word) == mp.end()){
            char letter = static_cast<char>(i+97);
            mp[word] = letter;
            i++;
        }
        s_pattern += mp[word];
    }
    if (pattern == s_pattern){
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

bool Solution::wordPattern2(string pattern, string s) {
    unordered_map<char, int> pattern_mp; //用來記錄 pattern 中每個字母的最後出現位置
    unordered_map<string, int> s_mp; //用來記錄 s 中每個單字的最後出現位置
    istringstream iss(s); 
    string word;
    int n = pattern.size();
    int i; //用來紀錄目前讀取了幾個單字
    for(i=0; iss>>word; i++){
        char letter = pattern[i];
        if (i==n || (pattern_mp[letter] != s_mp[word])){
        //(i == n) 表示單字數超過 pattern 長度
        //(pattern_mp[letter] != s_mp[word]) 表示目前字母的累積出現次數與目前單字的累積出現次數對不起來
            return false; 
        }
        //(i != n) && (pattern_mp[letter] == s_mp[word])
        pattern_mp[letter] = s_mp[word] = i+1; //因為若 map 中不存在某個鍵值時卻被呼叫，會自動創建一個新的 item 且 value 為 0 (int 的預設值)，因此將 value 設為 i+1 以避免這種情況。
    }
    return i==n; //若 i!=n 則回傳 false，代表單字數小於 pattern 長度
}

int main() {
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << sol.wordPattern1(pattern, s) << endl;
    cout << sol.wordPattern2(pattern, s) << endl;
    return 0;
}

//Compile: g++ -std=c++11 290.cpp -o 290
//Run: ./290