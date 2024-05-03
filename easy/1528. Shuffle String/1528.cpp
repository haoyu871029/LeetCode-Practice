#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution{
public:
    string restoreString1(string s, vector<int>& indices);
    string restoreString2(string s, vector<int>& indices);
};

string Solution::restoreString1(string s, vector<int>& indices) {
    string result = "";
    map<int,char> mp;
    int n = indices.size();
    for (int i=0; i<n; i++){
        mp[indices[i]] = s[i];
    }
    for (auto pair :mp){
        result += pair.second;
    }
    return result;
}

string Solution::restoreString2(string s, vector<int>& indices){
    int n = s.size() ; 
    string temp = s ;
    for( int i=0; i<n; i++){
        s[indices[i]]= temp[i] ; 
    }
    return s ; 
}

int main(){
    Solution s;
    string str = "codeleet";
    vector<int> indices = {4,5,6,7,0,2,1,3};
    cout << s.restoreString1(str, indices) << endl;
    cout << s.restoreString2(str, indices) << endl;
    return 0;
}

//Compile: g++ -std=c++11 1528.cpp -o 1528
//Run: ./1528