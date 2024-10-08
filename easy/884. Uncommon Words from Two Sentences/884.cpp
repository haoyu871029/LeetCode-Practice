#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2);
};

vector<string> Solution::uncommonFromSentences(string s1, string s2) {
    /* I. use map to store the content of string */
    istringstream iss1(s1), iss2(s2); //supported by <sstream>
    unordered_map<string,int> mp1, mp2;
    string word1, word2;
    while (iss1 >> word1){  
        if (mp1.find(word1) != mp1.end()){
            mp1[word1] += 1;
        }
        else {
            mp1[word1] = 1;
        }
    }
    while (iss2 >> word2){ 
        if (mp2.find(word2) != mp2.end()){
            mp2[word2] += 1;
        }
        else {
            mp2[word2] = 1;
        }            
    }
    /* II. find the uncommon words */
    vector<string> result;
    for (auto pair :mp1){
        if (mp2.find(pair.first)==mp2.end() && pair.second==1){
            result.push_back(pair.first);
        }
    }
    for (auto pair :mp2){
        if (mp1.find(pair.first)==mp1.end() && pair.second==1){
            result.push_back(pair.first);
        }
    }
    return result;
}

int main(){
    Solution sol;
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    vector<string> result = sol.uncommonFromSentences(s1,s2);
    for (string word :result){
        cout << word << " ";
    }//expected output: sweet sour
    return 0;
}

//compile command: g++ -std=c++11 884.cpp -o 884
//execution command: ./884
//git add . && git commit -m "update 884" && git push origin main