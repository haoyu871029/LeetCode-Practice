#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    bool isAnagram1(string s, string t);
    bool isAnagram2(string s, string t);
};

bool Solution::isAnagram1(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return (s == t);
}

bool Solution::isAnagram2(string s, string t) {
    if (s.size() != t.size()){
        return false;
    }
    //到這邊代表 s 和 t 長度必相同
    vector<int> freq(26, 0);
    for (int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }//freq[0] 代表 a 的個數, freq[1] 代表 b 的個數, 以此類推
    for (int i=0; i<freq.size(); i++){
        if (freq[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(){
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram1(s, t) << endl;
    cout << sol.isAnagram2(s, t) << endl;
    return 0;
}

//Compile: g++ -std=c++11 242.cpp -o 242
//Run: ./242