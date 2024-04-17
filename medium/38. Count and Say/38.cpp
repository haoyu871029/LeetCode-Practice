#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        /* Base case & Settings */

        if (n == 1) return "1"; //base case
        string str_before = countAndSay(n-1);
        char digit = str_before[0]; //代表目前針對的數字
        int num = 0; //用來累積目前針對的數字有幾個

        /* 遍歷 countAndSay(n-1) 的結果: str_before */

        string str = "";
        for (int i=0; i<str_before.size(); i++){
            if (str_before[i] == digit){//same digit
                num++;
                if (i == str_before.size()-1){//insert final digit
                    str += to_string(num) + digit;        
                }            
            }
            else{//next digit
                str += to_string(num) + digit; //insert last digit
                digit = str_before[i];
                num = 1;
                if (i == str_before.size()-1){//insert final digit
                    str += to_string(num) + digit; 
                }
            }
        }
        return str;
    }
};

int main(){
    Solution sol;
    cout << sol.countAndSay(1) << endl;
    cout << sol.countAndSay(2) << endl;
    cout << sol.countAndSay(3) << endl;
    cout << sol.countAndSay(4) << endl;
    cout << sol.countAndSay(5) << endl;
    cout << sol.countAndSay(6) << endl;
    cout << sol.countAndSay(7) << endl;
    cout << sol.countAndSay(8) << endl;
    cout << sol.countAndSay(9) << endl;
    cout << sol.countAndSay(10) << endl;
    return 0;
}

//Compile: g++ -std=c++11 38.cpp -o 38
//Run: ./38