#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2);
};

bool Solution::areSentencesSimilar(string sentence1, string sentence2) {
    
    auto splitWords = [](const string &sentence) {
        vector<string> words;
        istringstream iss(sentence); //supported by <sstream>
        string word;
        while (iss >> word){ 
            words.push_back(word);
        }
        return words;
    };

    vector<string> words1 = splitWords(sentence1);
    vector<string> words2 = splitWords(sentence2);
    if (words1.size() < words2.size()) swap(words1, words2);
    
    int start = 0, end = 0;
    int n1 = words1.size(), n2 = words2.size();
    while (start<n2 && words1[start] == words2[start]) start++;
    while (end<n2 && words1[n1-1-end] == words2[n2-1-end]) end++;
    return (start+end >= n2); //若用 ==，則 "a" vs "a  aa a" 會是 false，實際上是 true
}

int main(){
    Solution sol;
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";
    cout << sol.areSentencesSimilar(sentence1, sentence2) << endl; //expect true
    return 0;
}

//compile command: g++ -std=c++11 1813.cpp -o 1813
//execute command: ./1813
//git add . && git commit -m "update 1813" && git push origin main  