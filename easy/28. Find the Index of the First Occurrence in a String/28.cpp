#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr1(string haystack, string needle);
    int strStr2(string haystack, string needle);
};

int Solution::strStr1(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    vector<int> record;
    for (int i=0; i<n; i++){ //O(n)
        if (haystack[i] == needle[0]){
            record.push_back(i);
        }
    }
    for (auto index :record){ //O(n)
        if ((index+m) > n){
            return -1;
        }
        string test = "";
        for (int i=index; i<index+m; i++){ //O(m)
            test += haystack[i];
        }
        if (test == needle){
            return index;
        }
    }
    return -1;
}

int Solution::strStr2(string haystack, string needle) {
    int index = haystack.find(needle);
    return (index == -1) ? -1 : index;
}

int main(){
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    int result = sol.strStr1(haystack, needle);
    cout << result << endl; 
    return 0;
}

//Compile: g++ -std=c++11 28.cpp -o 28
//Run: ./28