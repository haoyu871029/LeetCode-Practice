#include <iostream>
#include <sstream> //support istringstream
#include <cctype> //support ispunct(), tolower()
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string result;
        unordered_map<string, int> freq;

        /* 對 paragraph 作預處理 */
        for(auto &c :paragraph)
            c = ispunct(c) ? ' ' : tolower(c);

        /* 對 banned 作預處理 */
        unordered_set<string> banned_set(banned.begin(), banned.end());
        
        /* 記數的同時做判斷 */
        int max_freq = 0;
        istringstream ss(paragraph);
        string str;
        while(ss>>str){
            freq[str]++;
            if(banned_set.count(str)==0 && freq[str]>max_freq) {
                max_freq = freq[str];
                result = str;
            }
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