#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map <char,int> mp{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };

        for(int i=0;i<s.size();i++){
            if(mp[s[i]] >= mp[s[i+1]]){
                ans += mp[s[i]];
            }
            else{//for cases such as IV,CM, XL, etc...
                ans -= mp[s[i]];
            }
        }
        return ans;     
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("MCMXCIV") <<endl; //1994
    cout << s.romanToInt("LVIII") <<endl; //58
    return 0;
}

//Compile: g++ -std=c++11 13.cpp -o 13
//Run: ./13