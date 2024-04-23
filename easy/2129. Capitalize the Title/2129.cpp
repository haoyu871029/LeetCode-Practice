#include <iostream>
#include <sstream> //support istringstream
#include <vector>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string result = "";
        istringstream iss(title);
        string word;
        while (iss >> word){
            if (word.size() <= 2){
                for (auto &c :word){
                    result += tolower(c);
                }            
            }
            else{
                result += toupper(word[0]);
                for (int i=1; i<word.size(); i++){
                    result += tolower(word[i]);
                }
            }
            result += " ";
        }
        result.pop_back();
        return result;
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