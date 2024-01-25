#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string str, result;
        int max_freq = 0;
        unordered_map<string, int> freq;
        unordered_set<string> banned_set(banned.begin(), banned.end());

        for(auto &c :paragraph)
            c = ispunct(c) ? ' ' : tolower(c);
        istringstream ss(paragraph);
        while(ss>>str)
            //freq[str]++;
            if(banned_set.count(str)==0 && max_freq<++freq[str]) {
                max_freq = freq[str];
                result = str;
            }
        return result;
    }
};

int main(){
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    Solution sol;
    cout << sol.mostCommonWord(paragraph, banned) << endl;
    return 0;
}

// compile: g++ 819.cpp -o 819 -std=c++11
// execute: ./819