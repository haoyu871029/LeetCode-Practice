#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool canConstruct1(string ransomNote, string magazine);
        bool canConstruct2(string ransomNote, string magazine);
};

bool Solution::canConstruct1(string ransomNote, string magazine) {
    /* 遍歷 magazine 來建構 dictionary */
    unordered_map<char, int> dictionary; //key: character, value: frequency
    for (char c :magazine) {
        if (dictionary.find(c) == dictionary.end())
            dictionary[c] = 1;
        else
            dictionary[c]++;
    }

    /* 遍歷 ransomNote 來消耗 dictionary */
    for (char c :ransomNote) {
        if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0)
            dictionary[c]--;
        else //c is not in magazine or c is used up
            return false;
    }

    return true;
}

bool Solution::canConstruct2(string ransomNote, string magazine) {
    /* pre-sort */ 
    sort(ransomNote.begin(),ransomNote.end());
    sort(magazine.begin(),magazine.end());

    /* 同時遍歷 ransomNote 和 magazine */
    int i=0, j=0;
    while (i<ransomNote.length() && j<magazine.size()){
        if (ransomNote[i] == magazine[j]){
            i++; //ransomNote 只有在找到一個字母後才會往後
            j++;
        }
        else if (ransomNote[i] > magazine[j]){
            j++;
        }
        else //ransomNote[i] < magazine[j] 代表 magazine 再往後只會更大，不可能再找到 ansomNote[i] 了
            return false;
    }
    bool result = (i==ransomNote.size());
    return result;
}

int main(){
    bool result;
    Solution sol;
    result = sol.canConstruct2("ad", "abcd"); //true
    result = sol.canConstruct2("fihjjjjei", "hjibagacbhadfaefdjaeaebgi"); //第二種情況失敗
    if (result)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

//Compile: g++ -std=c++11 383.cpp -o 383
//Run: ./383