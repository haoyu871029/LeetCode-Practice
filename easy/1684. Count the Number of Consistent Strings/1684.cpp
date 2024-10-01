#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words);
};

int Solution::countConsistentStrings(string allowed, vector<string>& words) {
    /* Create a map to store the allowed characters */
    unordered_map<char, int> mp;
    for (char c :allowed){
        mp[c] = 1;
    }
    /* Count the number of consistent strings */
    int count = 0;
    for (auto s :words){
        count++;
        for (char c :s){
            if (mp.find(c) == mp.end()){
                count--;
                break;
            }
        }
    }
    return count;
}

int main() {
    string allowed = "abc";
    vector<string> words = {"a","b","c","ab","ac","bc","abc"};
    Solution sol;
    cout << sol.countConsistentStrings(allowed, words) << endl; //expected output is 7
    return 0;
}

//Compile command: g++ -std=c++11 1684.cpp -o 1684
//Run command: ./1684