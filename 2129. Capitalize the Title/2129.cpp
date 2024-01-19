#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string c_title = "";
        istringstream iss(title);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        for (auto &str :words){
            if (str.size() <= 2){
                for (auto &c :str){
                    c_title += tolower(c);
                }
            }
            else{
                c_title += toupper(str[0]);
                for (int i=1; i<str.size(); i++){
                    c_title += tolower(str[i]);
                }
            }
            c_title += " ";
        }
        c_title.pop_back();
        return c_title;
    }
};

int main(){
    string title = "i love solving problems and it is fun";
    Solution sol;
    cout << sol.capitalizeTitle(title) << endl;
    return 0;
}

//compile: g++ 2129.cpp -o 2129 -std=c++11
//execute: ./2129