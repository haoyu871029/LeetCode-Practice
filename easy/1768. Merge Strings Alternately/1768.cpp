#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2);
};

string Solution::mergeAlternately(string word1, string word2) {
    int n = (word1.size()>word2.size()) ? word1.size() : word2.size();
    string str = "";
    for (int i=0; i<n; i++){
        if (i < word1.size()){
            str += word1[i];
        }
        if (i < word2.size()){
            str += word2[i];
        }
    }
    return str;
}

int main(){
    Solution s;
    string word1 = "abc";
    string word2 = "defg";
    cout << s.mergeAlternately(word1, word2) << endl;
    //expected output is "adbecfg"
    return 0;
}

//Compile command: g++ -std=c++11 1768.cpp -o 1768
//Run command: ./1768